# PHP

## Comment

```php

# Like Python

// Like C

/*
    Multi
    line
    comment
*/
```

## Variable variables

Works like history of initializations.

```php
$a = "alpha";
$b = "beta";
$c = "gamma";

$c;     //gamma
$$c;    //beta
$$$c;   //alpha
```

## URL parameter

```php
$age = %_GET['age'];
```

```php
$age = %_GET["age"];
```

