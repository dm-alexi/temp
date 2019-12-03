#!/usr/bin/php
<?php
if ($argc != 2)
	exit("Incorrect Parameters\n");
$a = (float)$argv[1];
$b = (float)$argv[3];
$op = trim($argv[2]);
if ($op == "+")
	echo ($a + $b), "\n";
if ($op == "-")
	echo ($a - $b), "\n";
if ($op == "*")
	echo ($a * $b), "\n";
if ($op == "/" && $b != 0)
	echo ($a / $b), "\n";
if ($op == "%" && $b != 0)
	echo ($a % $b), "\n";
?>