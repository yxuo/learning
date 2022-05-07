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

