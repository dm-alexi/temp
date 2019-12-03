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

if ($argc < 2)
	exit;
$arr = ft_split(trim($argv[1]));
array_push($arr, array_shift($arr));
echo implode(" ", $arr), "\n";
?>