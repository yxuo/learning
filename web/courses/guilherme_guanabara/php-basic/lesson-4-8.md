# 4. PHP variables

Variables are items that stores content.

Like Python, php is simple to use:

```php
$idade = 3
```

* Always use $ at start, it's obligatory.

* PHP code is case sensitive, so it's conventioned to use `camelCase`.

Also like Python, PHP is srongly typed, so you dont initialize the type of variable.

## Force type with typecast:

```php
$int1 = (int) 3;
$int2 = (integer) 3;

$int_txt1 = (int) "3";    // 3
$int_txt2 = (int) "3txt"; // 3
$int_txt2 = (int) "txt3"; // 0

$real1 = (real) 3.14;
$real2 = (float) 3.14;
$real3 = (double) 3.14;

$chars1 = (string) "hello";

$boolTrue1 = (bool) true;
// true, True, 1, -2, NAN, "any text", array(2)

$boolFalse1 = (bool) false;
// false, False, 0, "0", "", array(), NULL, null
```

### Bool

The typecast `(bool)` detects these values as `true` or `false`.

Without typecast, the only way to automatically set to bool is using `true`, `True` or `false`, `False`.

PHP automatically convert `True` to `true`, so it makes sense to write always `true`/`false` in lowercase.

### int

You can convert text to int but only if the first charecters are numbers, otherwise the result will be `0`.

## print

```php
$txt1 = "hello";
$txt2 = "world";
$num1 = 123;
$num1 = 456;

echo $txt1 . $txt2 . $num1 . $num2 . "\n";
echo "{$txt1} {$txt2} {$num1} {$num2}";
```

Always use dot `.` or braces `{}`.

:x: Don't do this:

```php
echo $txt1, $txt2, $num1, $num2, "\n";
echo "$txt1 $txt2 $num1 $num2";
```

Never use commas `,` or variable inside double quotes `"$variable"`.

To print litteral dollar sign `$` or raw text, use single quote `'$variable'`.

## Source

* [How To Print Variable Name With Dollar Sign In PHP - CodeSpeedy](https://www.codespeedy.com/echo-dollar-sign-in-php/)

* [PHP - concatenate or directly insert variables in string - StackOverflow](https://stackoverflow.com/questions/5605965/php-concatenate-or-directly-insert-variables-in-string)

# 5. Arithmetic operators

* `localhost` is the same as `127.0.0.1`.

```php
$num1 = 2;
$num2 = 3;
$num3 = -144;

echo $num1 + $num2 . "\n";      // 2+3 = 5      Add
echo $num1 - $num2 . "\n";      // 2-3 = -1     Subtract
echo $num1 * $num2 . "\n";      // 2*3 = 6      Multiply
echo $num1 ** $num2 . "\n";     // 2^3 = 8      Power
echo pow($num1, $num2) . "\n";  // 2^3 = 8      Power
echo $num1 / $num2 . "\n";      // 2/3 = 0.67   Division
echo $num1 % $num2 . "\n";      // 2/3 = 2      Module
echo sqrt($num3) . "\n";        // -2 = 2       Square root
echo abs($num3) . "\n";         // -2 = 2       Absolute
```

## format number

```php
//                (num, decimals, decimal_sep, thousand_sep)
echo number_format(3258.754, 2, ",", "."). "\n";
```

## Read values from url:

```php
    <?php
    $n1 = $_GET["a"];
    $n2 = $_GET["b"];
    echo "<h2>Recebido: a = $n1, b = $n2</h2>"
     ?>
```

URL:

```
http://localhost/my-folder/?a=2&b=3
```

# 6. Attribution operators

## Increment:

```php
$num = 3;

$num += 1;  // 4
$num ++;    // 4
$num -= 1;  // 2
$num --;    // 2
$num *= 3;  // 9
$num **= 3; // 27
$num /= 3;  // 1
$num .= 1;  // 31   (concatenate)
```

## Comment:

```php
//  C       comment
#   Python  comment
```

## Pointer:

```php
$num = 12345;
$ptr = &$num;
```

## Variable variables:

```php
$name = "Raphael";
$$name = "Rivas";
echo "{$name} {$$name}\n";
```

Another example:

```php
  $a = "a";
  $b = "Bar";
  $c = "Curl";
  $d = "World";
  $e = "Hello";

  $e;       // Hello
  $$e;      // World
  $$$e;     // Curl
  $$$$e;    // Bar
  $$$$$e;   // a
```

## Array:

```php
$txt = "abc 123";
$txtArr = array('abc','123','def');
```

## Class:

```php
class myClass{
    var $arr = array('abc','123','def');
    public $pub = "public variable";
    private $priv = "private variable";
}

$myClass = new myClass();
echo $myClass->pub . "\n";
echo $myClass->arr[0];
```

## Exercise

1. Apply 10% off

    ```php
    $price = 159.99

    $price = 159.99;
    echo "price = $price\n";
    $price = $price - ($price * 10 / 100);
    echo "new price = $price\n";
    ```

2. Show last year

    ```php
        $year = isset($_GET["aa"]) ? $_GET["aa"] : 2022;
        echo "year = --$year";
    ```

3. Change variable value by reference (pointer)

    ```php
    $var = isset($_GET["var"]) ? $_GET["var"] : 50;
    $ptr = &$var;
    echo "var = $var, ptr = $ptr\n";

    $ptr = "hello";
    echo "var = $var, ptr = $ptr\n";
    ```
## optional url parameter

Works:

```php
$price = isset($_GET['price']) ? $_GET['price'] : 9.99;
```

```php
$price = 9.99;
if(isset($_GET['price'])) $price = $_GET['price'];
```

```php
if(isset($_GET['price']))
    $price = $_GET['price'];
```

```php
if(isset($_GET['price']))
{
    $price = $_GET['price'];
}
```

## Source

* [Variable variables - PHP](https://www.php.net/manual/en/language.variables.variable.php)

# 7. Relational operators

## Ternary

Just like in C:

```php
$num = 5;
$num == 5 ? 50 : -10;   //$num = 50
```

## Conditionals

They are ike C or Python, SQL.

`AND`:
```php
if($a > 0 and $b > 0) ... ;
if($a > 0 And $b > 0) ... ;
if($a > 0 AND $b > 0) ... ;
if($a > 0 && $b > 0) ... ;
```

`OR`:

```php
if($a > 0 or $b > 0) ... ;
if($a > 0 Or $b > 0) ... ;
if($a > 0 OR $b > 0) ... ;
if($a > 0 || $b > 0) ... ;
```

## Exercises

1. Let user choose between sum and multiply

    ```php

    echo "Choose [op]eration between [sum] or [mul]tiplication between [a] and [b].";
    $sum = isset($_GET['sum']) ? $_GET['sum'] : 2;
    $sub = isset($_GET)
    ```

2. Show if a person is between 18 and 60 years old by birth age;

   ```php
    $birth = isset($_GET['a']) ? $_GET['a'] : 2000;
    $age = abs($birth - date("Y"));
    
    if (in_array($age, range(18,60)))
        echo "The vote is mandatory";
    else
        echo "The vote is optional";
   ```

# 8 HTML5 + PHP integration

## GET

send form via URL - fast, extremely usnecure

HTML:

```html
<form method="get" action="data.php">
    <input type="text" name="v">
    ...
</form>
```

PHP:
```php
$value = $_GET["v"]
```

URL:

```
localhost/tst?v=10
```


## POST

send form via packages - a bit slower and more secure

## html5 form:

```html
<form method="get" action="data.php">
    ...
</form>
```

## HTML5 review

Void elements (solo tags):

```html
<br>
<img src="image.png">
```

### In HTML5 slash is optional in void elements

HTML 4:

```html
<br/>
<img src="image.png"/>
```

HTML5:

```html
<br>
<img src="image.png">
```

## CSS tips

```css
/*
tag {}
#id{}
.class{}
tag.class{}
*/
```

## Exercise

*HTML, CSS + PHP*

1. Read a value and show the square root

2. Read name, birth and sex. Show the current age.

3. Use a form to change CSS size, text and color.