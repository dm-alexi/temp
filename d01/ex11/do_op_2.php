#!/usr/bin/php
<?php
if ($argc != 2)
	exit("Incorrect Parameters\n");
$arr = array();
$line = trim($argv[1]);
if (($n = strlen($line)) < 3)
	exit("Syntax Error\n");
$i = (($line[0] == "+" || $line[0] == "-") ? 1 : 0);
$dot = 0;
while ($i < $n && (is_numeric($line[$i]) || ($line[$i] == "." && $dot++ == 0)))
	++$i;
if ($i == 0 || $i >= $n - 1 || !is_numeric($a = substr($line, 0, $i)))
	exit("Syntax Error\n");
$line = trim(substr($line, $i));
if (strlen($line) < 2 || !is_numeric($b = substr($line, 1)) || !strstr("+-*/%", ($op = $line[0])))
	exit("Syntax Error\n");
$a = (float)$a;
$b = (float)$b;
if ($op == "+")
	echo ($a + $b), "\n";
if ($op == "-")
	echo ($a - $b), "\n";
if ($op == "*")
	echo ($a * $b), "\n";
if ($op == "/" && $b != 0)
	echo ($a / $b), "\n";
if ($op == "%" && (int)$b != 0)
	echo ($a % $b), "\n";
?>