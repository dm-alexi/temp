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

function is_alpha($a)
{
	return strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", $a);
}

function cmp_single($a, $b)
{
	if ($a == $b)
		return 0;
	if ((is_alpha($a) && is_alpha($b)) || (is_numeric($a) && is_numeric($b)))
		return $a > $b ? 1 : -1;
	if (is_alpha($a))
		return -1;
	if (is_alpha($b))
		return 1;
	if (is_numeric($a))
		return -1;
	if (is_numeric($b))
		return 1;
	return $a > $b ? 1 : -1;
}

function cmp($a, $b)
{
	$a_arr = str_split(strtoupper($a));
	$b_arr = str_split(strtoupper($b));
	$na = count($a_arr);
	$nb = count($b_arr);
	$n = $nb > $na ? $na : $nb;
	for ($i = 0; $i < $n; ++$i)
		if ($res = cmp_single($a_arr[$i], $b_arr[$i]))
			return $res;
	return $na - $nb;
}

$arr = array();
for ($i = 1; $i < $argc; ++$i)
	$arr = array_merge($arr, ft_split(trim($argv[$i])));
usort($arr, "cmp");
foreach ($arr as $val)
	echo $val, "\n"
?>