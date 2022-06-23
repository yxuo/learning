// const PS = require("scanf-printf-obi")
var scanf_stub = require('scanf-printf-obi').scanf,
    printf_stub = require('scanf-printf-obi').sprintf,
    fgets_stub = require('scanf-printf-obi').fgets
    
var v1, v2;

// scanf("%d %d","v1","v2");

if(v1 > v2)
    // printf(v1);
    console.log(v1);
    else
    console.log(v2);
    // printf(v2);
