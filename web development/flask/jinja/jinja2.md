# Examples
<br>
<br>

## useful filters 
1) format specifiers 
```
{{ "%s, %s!"|format(greeting, name) }}
```
2) Join
```
{{ [1, 2, 3]|join('|') }}
```
3) turn to list 
```
{{ |list }}
```
4) turn to json
```
{{ |tojson }}
```
<br>

## useful tests 
1) check if defined 
```
{% if variable is defined %}
```
2) check if divided by
```
{% if variable is divisbleby(3) %}
```
3) check if value in value 
```
{% if variable in "yuval" %}
```
<br>
<br>

## loops
1) for loop example of dict
```
{% for key,value in dict %}
  {{ key }}
{% endfor %}
```
2) for loop without whitespaces treaming 
```
{% for item in seq -%}
  {{ item }}
{%- endfor %}
```
<br>
<br>

## make jinja ouput as raw 
```
{% raw %}
 <ul>
 {% for item in seq %}
  <li>{{ item }}</li>
 {% endfor %}
{% endraw %}
```
<br>
<br>

## render a template
```
{% include 'base.html' %}
Body
{% include 'footer.html' %}
```
