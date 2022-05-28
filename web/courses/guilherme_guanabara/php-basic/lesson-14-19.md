# 14. PHP routines - part 1

function
```php
function sum($a,$b){
    $s = $a + $b;
    echo $s;
}
sum(3,4);
```

Get multiple parameters:
```php
function sum(){
    $arr_args = func_get_args();
    $len = func_num_args();
    // parse params
    for($i=0;$i<$len;$i++){
        ...
    }
}
```

## Exercise

*Procedure*

 1. Sum two ints.
 2. Sum two values using return.
 3. Sum with multiple parameters.

# 15. PHP routines - part 2

## Parameter as reference:
```php
function tst(&$var){
    $var = 10;
}
$num = 5;
tst($num);
```

* External routines - code, functions that are in other files.

## Include external file:
```php
include file2.php
```

## Include vs require:
* Include - optional, the code will run.
* Require - mandatory, the code will stop.

* Include, require once - prevent duplicated imported files.

## Exercise

*Reference*

1. Create a simple function that uses reference parameter.
2. Create include library with a function and variable, and use them.