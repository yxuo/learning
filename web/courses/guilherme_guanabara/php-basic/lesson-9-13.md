# 9. Conditional if

## Ternary

```php
$biggest = 1 > 0 ? 1 : 0
```

> if 1 > 0 biggest = 1, else biggest = 0

## Common if usage:

```php
if(1 > 0)
{
    ...
}
```

```php
if(1 > 0)
    ...
```

* Curly bracket is optional

## Aligned conditions

```php
if(true){
    ...
}
    if(true){
        ...
    }
}
```

## Exercise

*using forms*

1. Read the birth year and show if this person is of legal age.
2. No1 + elective age, between 16-17 year-old.
3. Read 2 grades, calculate the average and if tne student had been passed.

# 10. Conditional switch

```php
$number = 1;
switch($number){
    case 1:
        echo "A";
        break;
    case 1:
        echo "B";
        break;
    default:
        echo "default";
}
```

Return:

```
A
```

## Break

Always use break, without it all other conditions will be passed trough:

```
ABdefault
```

You don't need use break in the default statement.

## Exercise

1. Read number, operation (double, cube, sqrt).
2. Read week day (1-7) and show which days are not weekend.
3. Show all states of your country and show its region (e.g. RJ Sudeste, CA Pacific, KYA - Siberian).

# 11. Repetition while

```php
$num = 1;
while($num <= 10){
    echo "$num "
    $num++
}
```

## Exercise

*Using While*

1. Show progressive counting from 1 to 10.
2. Create dynamically 5 text boxes in a form.
3. Create customizable counter (start, end, increment).

# 12. Repetition Do While

```php
$num = 1;
do{
    echo "$num ";
    $num++;
}
while(num <= 10);
```

## Exercise

*Using Do While*

1. Show regressive counting from 1 to 10.
2. Calculuate the factorial of int.
3. Show the number table from 1 to 10).

# 13. Repetition For

```php

for($num = 1; $num < 10; $num++){
    echo "$num ";
}
```

## Exercise

*Using for*

1. Show counting from 1 to 10.
2. Show the number table from 1 to 10).
3. Show if the typed number is a prime number.
