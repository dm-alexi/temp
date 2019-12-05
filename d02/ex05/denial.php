#!/usr/bin/php
<?php
if ($argc < 3 || !file_exists($argv[1]) || !($f = fopen($argv[1], "r")) || (($legend = fgets($f)) == false))
	exit;
if (!in_array($argv[2], ($legend = explode(";", trim($legend)))))
	exit;
foreach ($legend as $val)
	$$val = array();
$n = count($legend);
while (($tmp = fgets($f)) !== false)
{
	$tmp = explode(";", trim($tmp));
	if (count($tmp) != $n)
		continue;
	$tmp = array_combine($legend, $tmp);
	foreach ($legend as $val)
		${$val}[$tmp[$argv[2]]] = $tmp[$val];
}
fclose($f);
echo "Enter your command: ";
while (($f = fgets(STDIN)) !== false)
{
	eval(trim($f));
	echo "Enter your command: ";
}
?>