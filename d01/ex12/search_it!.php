#!/usr/bin/php
<?php
$arr = array();
for ($i = 2; $i < $argc; ++$i)
{
	$tmp = explode(":", $argv[$i]);
	$arr[$tmp[0]] = $tmp[1];
}
if (array_key_exists($argv[1], $arr))
	echo $arr[$argv[1]], "\n";
?>