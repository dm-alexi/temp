#!/usr/bin/php
<?php
echo "Enter a number: ";
while (($f = fgets(STDIN)) !== false)
{
        $f = trim($f);
        if (!is_numeric($f) || ($f - floor($f) != 0))
                echo "'".$f."' is not a number\n";
        else if ($f % 2)
             echo "The number ".$f." is odd\n";
        else
                echo "The number ".$f." is even\n";
        echo "Enter a number: ";
}
echo "\n";
?>
