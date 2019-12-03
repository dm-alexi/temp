#!/usr/bin/php
<?php
$arr = array();
for ($i = 1; $i < $argc; ++$i)
	$arr = array_merge($arr, preg_split("/\\s+/", trim($argv[$i])));
sort($arr, SORT_STRING);
foreach ($arr as $val)
	echo $val, "\n"
?>