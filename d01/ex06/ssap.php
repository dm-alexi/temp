#!/usr/bin/php
<?php
function ft_split($line)
{
	$arr = array();
	$line = trim($line);
	while ($tmp = strstr($line, " ", true))
	{
		array_push($arr, $tmp);
		$line = trim(strstr($line, " "));
	}
	if ($line !== "")
		array_push($arr, $line);
	return $arr;
}

$arr = array();
for ($i = 1; $i < $argc; ++$i)
	$arr = array_merge($arr, ft_split(trim($argv[$i])));
sort($arr, SORT_STRING);
foreach ($arr as $val)
	echo $val, "\n"
?>