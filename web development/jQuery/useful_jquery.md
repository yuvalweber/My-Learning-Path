# useful jquery
1) change color of h1 to red
```
$("h1").css("color","red");
```
2) wait for document to be ready and then execute the command
```
$(document).ready(function() {
    $("h1").css("color","red");
}); 
```
3) get the property of something
```
$("h1").css("color");
```

4) add class to object
```
$("h1").addClass("dani-din");
```
5) remove class from object
```
$("h1").removeClass("dani-din");
```
6) check if has class
```
$("h1").hasClass("dani-din");
```
7) change text
```
$("h1").text("dani-din");
```
8) change html
```
$("h1").html("dani-din");
```

9) get attribute
```
 $("h1").attr("src");
 ```
10) set attribute
```
 $("h1").attr("src","dani.png");
```
11) if click do something
```
$("h1").click(function() {
    alert(1);
});
```
&nbsp;another way to do this
```
$("h1").on("click",function() {
    alert(1);
});
```
12) adding button
```
$("h1").before("<button>dani</button>");
 ```
13) remove button
```
$("button").remove();
```
14) fade animation
```
$("h1").fadeIn(3000);
$("h1").fadeOut(3000):
```
&nbsp;you can also use fadeToggle, to toggle the animation when click

15) slide animation
```
$("h1").slideUp(3000);
$("h1").slideDown(3000);
```
&nbsp;you can also use slideToggle, to toggle the animation when click
  
16) create freeStyle animation
```
$("div").animation({
    left: '250px';
    height: '+=150px';
},3000);
```