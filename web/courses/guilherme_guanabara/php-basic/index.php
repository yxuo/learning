<html>
        <body>
            <?php
                echo "<h3>Choose [op]eration between [sum] or [mul]tiplication between [a] and [b].</h3>";
                $a = isset($_GET["a"]) ? $_GET['a'] : 2;
                $b = isset($_GET["b"]) ? $_GET['b'] : 3;
                $op = isset($_GET["op"]) ? $_GET['op'] : "sum";
                $e = $op == "sum" ? "$a + $b = " : "$a * $b = ";
                $e .= $op == "sum" ? $a + $b : $a * $b;
                echo "<p>$e</p>";

                if ($a > 0 aNd $b > 0)
                    echo "<p>true</p>";
            ?>
        </body>
</html>