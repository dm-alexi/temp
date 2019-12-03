#!/usr/bin/php
<?php
if ($argc < 2)
	exit;
fgets(STDIN);
$arr = array();
while (($f = fgets(STDIN)) !== false)
	array_push($arr, explode(";", trim($f)));
if ($argv[1] == "average" || $argv[1] == "moyenne")
{
	$sum = 0.0;
	$n = 0;
	foreach ($arr as $val)
		if ($val[2] !== "moulinette" && $val[1] !== "")
		{
			$sum += $val[1];
			++$n;
		}
	if ($n > 0)
		echo ($sum / $n), "\n";
}
if ($argv[1] == "average_user" || $argv[1] == "moyenne_user" || $argv[1] == "moulinette_variance" || $argv[1] == "ecart_moulinette")
{
	$points = array();
	$nums = array();
	$moul = array();
	foreach ($arr as $val)
		if (!array_key_exists($val[0], $points) && $val[1] !== "" && $val[2] !== "moulinette")
		{
			$points[$val[0]] = $val[1];
			$nums[$val[0]] = 1;
		}
		else if (array_key_exists($val[0], $points) && $val[1] !== "" && $val[2] !== "moulinette")
		{
			$points[$val[0]] += $val[1];
			++$nums[$val[0]];
		}
		else if ($val[2] == "moulinette")
			$moul[$val[0]] = $val[1];
	foreach (array_keys($points) as $key)
		$points[$key] /= $nums[$key];
	ksort($points);
	if ($argv[1] == "average_user" || $argv[1] == "moyenne_user")
		foreach (array_keys($points) as $key)
			echo $key, ":", $points[$key], "\n";
	else
		foreach (array_keys($points) as $key)
			echo $key, ":", $points[$key] - $moul[$key], "\n";
}
?>