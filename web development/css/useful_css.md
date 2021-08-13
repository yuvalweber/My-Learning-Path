# Table of Contents
- [useful attributes](#useful-attributes)
- [media breakpoints](#media-breakpoints)
- [css selectors](#css-selectors)
- [css functions](#css-functions)
- [css animations](#css-animations)
<br>
<br>

## useful attributes
1) make space between lines bigger
```
p {
    line-height: 2;
}
```    
2)make image float to the right of text
```
img {
    float:right; /* clear is the opposite of float */
}
```    

## media breakpoints
1) if the size larger than 900px, we narrow the size of the font 
```
@media (min-width: 900px) {
    h1 {
        font-size: 9px;
    }
}
```
you can also make a @media condition with 'and' so both statements need to be true

<br>

## css selectors
1) change if this is the active link 
```
a:active {
    background-color: azure;
}
```    
2) changed when hover with the mouse
```
a:hover {
    background-color: chartreuse;
}
``` 
3) insert something after the element (you can also use ::before as the opposite).
```
p::after {
    content: " - added after";
}
```
4) change first letter of element
```
p::first-letter {
    font-size: 40px;
}
```
5) affect all chceked input elements
```
input:checked {
    text-decoration: line-through;
}
```
6) affect all input with type of text
```
input[type=text] {
    background-color: burlywood;
}

```
7) affect all required items
```
input:required {
    color:greenyellow;
}
```
8) affect focused element
```
input[type=text] {
    width: 100px;
    -webkit-transition: width .35s ease-in-out; /* will make transition look cool */
    transition: width .35s ease-in-out;
}

input[type=text]:focus {
    width: 250px;
}
```
9) change the style of list item object (like the dot on the side)
```
::marker {
    color:red;
    font-size: 30px;
}
```
10) affect all placeholder items
```
::placeholder {
    color:darkgray;
}
```
11) change how it looks when you mark items with mouse
```
::selection {
    color:grey;
    background-color: lightskyblue;
}
```
<br>

## css functions  

1) make background mixed colors
```
body {
    background-image: linear-gradient(135deg,mintcream,lime);
}
```
<br>

## css animations 
1) make background-color from blue to red
```
@keyframes blueToRed {
    from {background-color: blue;}
    to   {background-color: red;}
}

#blueToRed {
    width: 300px;
    height: 300px;
    animation: blueToRed 5s ;
}
```
2) animating with transition proprty
```
div.square {
    height: 100px;
    background-color: red;
    width: 100px;
    transition: width 5s ease-in-out;
}

div.square:hover {
    width: 400px;
}
```