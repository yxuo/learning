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

## Date

You can use single quote `'`:

```php
date("y");
```

Or double quote `"`:

```php
date('y');
```

### Date formats

Year:

```php
date("y"); // 22
date("Y"); // 2022
```

Month:

```php
date("m"); // 12
date("M"); // Dec
```

Day:

```php
date("h"); // 13
```

Week day:

```php
date("h"); // 13
date("i"); // Sun
date("l"); // Sunday
```

### Time formats

#### Hour

12 (1-12):

```php
date("g"); //  1
date("h"); // 01
date("a"); // am
date("A"); // AM
```

24 (0-23):

```php
date("G"); //  1
date("H"); // 01
```

#### Minute

```php
date("i") // 00-59
```

#### Second

```php
date("s") // 00-59
```

#### Microsecond (php 5.2.2)

```php
date("u") // 00-59
```

### Unix timestamp:

```php
date("U");
```

## Source

* [PHP date_format() Function - W3Schools](https://www.w3schools.com/php/func_date_date_format.asp)