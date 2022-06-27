;1. Ler um número inteiro e imprimir seu sucessor e seu antecessor.
li $v0, 5
syscall
la $t7, 0($v0)
mov NUM, $t7

sub NUM, 1
jmp PRINT

mov NUM, $t7
add NUM, 1
jmp PRINT

li $v0, 10
syscall

PRINT
mov $t7, NUM
li $v0, 1
la $a0, ($t7)
syscall
jr $ra 


;2. Entrar com dois números inteiros e gerar a seguinte saída:
jmp SCAN
mov R1, $t7
jmp SCAN
mov R2, $t7

mov al, R1
div R2

mov $t7, R1
jmp PRINT

mov $t7, R2
jmp PRINT

mov $t7, ax
jmp PRINTF

mov $t7, ah
jmp PRINTF

li $v0, 10
syscall

PRINT
li $v0, 1
la $a0, ($t7)
syscall
jr $ra 

PRINTF
li $v0, 2
la $f12, ($t7)
syscall
jr $ra 

SCAN
li $v0, 5
syscall
la $t7, 0($v0)
jr $ra 


;4.  Ler uma temperatura em graus Centígrados e apresentá-la convertida em graus Fahrenheit. A fórmula de conversão é: F = (9*C+160)/5. Onde F é a temperatura em Fahrenheit e C é a temperatura em Centígrados.
li $v0, 6
syscall
la $t7, 0($v0)
mov CEL, $t7

mov al, 9
mul CEL
mov CEL, ax

add CEL, 160

mov al, CEL
div 5

mov $t7, ax
li $v0, 2
la $f12, ($t7)
syscall