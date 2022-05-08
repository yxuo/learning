<?php

echo date('D') . "\n";
echo date('H') . "\n";
echo date('i') . "\n";
echo date('I') . "\n";
echo date('s') . "\n";
echo date('S') . "\n";

/*
    multi line
*/

$birth = isset($_GET['a']) ? $_GET['a'] : 2000;
$age = abs($birth - date("Y"));
// if (in_array($age, range(18,60)))
//     echo "The vote is mandatory";
// else
//     echo "The vote is optional";

# old

$boolTrue1 = (bool) true;
$boolFalse1 = False;

// var_dump($boolTrue1);
// var_dump($boolFalse1);

// 4

$txt1 = "hello";
$txt2 = "world";
$num1 = 123;
$num1 = 456;

// echo $txt1 . $txt2 . $num1 . $num2 . "\n";
// echo "{$txt1} {$txt2} {$num1} {$num2}\n";
// echo '$txt1 $txt2 $num1 $num2\n' . "\n";

// arithmetics

$num1 = 2;
$num2 = 3;
$num3 = -2;

// echo $num1 + $num2 . "\n";
// echo $num1 - $num2 . "\n";
// echo $num1 * $num2 . "\n";
// echo $num1 ** $num2 . "\n";
// echo pow($num1, $num2) . "\n";
// echo $num1 / $num2 . "\n";
// echo $num1 % $num2 . "\n";
// echo abs($num3) . "\n";
// echo round(2.55,1,1) . "\n";  // PHP_ROUND_HALF_UP = 1
// echo round(2.55,1,2) . "\n";  // PHP_ROUND_HALF_UDOWN = 2
// echo number_format(3258.754, 2, ",", "."). "\n";    // num, decimals, decimal_sep, thousand_sep

// increment

$num = 3;
$num %= 2;

// ptr

$num = 12345;
$ptr = &$num;

// echo $num . "\n";
// echo $ptr[0] . "\n";

// var var

$name = "Raphael";
$$name = "Rivas";
// echo "{$name} {$$name}\n";

// arr

class myClass{
    var $arr = array('abc','123','def');
    public $pub = "public variable";
    private $priv = "private variable";
}

$myClass = new myClass();
// echo $myClass->pub . "\n";
// echo $myClass->arr[0];

// ex1
$price = isset($_GET['price']) ? $_GET['price'] : 9.99;
// echo "price = $price\n";
$price = $price - ($price * 10 / 100);
// echo "new price = $price\n";

// ex2
$ano = isset($_GET["aa"])?$_GET["aa"]:2022;
// echo "ano = --$ano";

// ex3
$var = isset($_GET["var"]) ? $_GET["var"] : 50;
$ptr = &$var;
$var2 = $var;
// echo "var = $var, ptr = $ptr\n";

$ptr = "hello";
// echo "var = $var, ptr = $ptr\n";

$var2 = 123;
// echo "var = $var, var2 = $var2\n";