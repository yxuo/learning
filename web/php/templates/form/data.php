<?php

// source: https://www.phptutorial.net/php-tutorial/php-form/

if(isset($_POST['email'])){
    $email = $_POST['email'];
    echo "<h2>Email = $email</h2>";
}