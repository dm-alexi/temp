#!/usr/bin/php
<?php
if ($argc < 2 || !file_exists($argv[1]) || !($file = file_get_contents($argv[1])))
	exit;
$arr = explode("\n\n", trim($file));
$arr = array_map(function($val) { return substr(strstr($val, "\n"), 1) ;}, $arr);
sort($arr);
for ($i = 0, $n = count($arr); $i < $n; ++$i)
	echo ($i + 1)."\n".$arr[$i]."\n\n";
?>