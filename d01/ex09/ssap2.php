#!/usr/bin/php
<?php
function cmp_single($a, $b)
{
	if ($a == $b)
		return 0;
	if ((preg_match('/[A-Z]/', $a) && preg_match('/[A-Z]/', $b)) || (is_numeric($a) && is_numeric($b)))
		return strcmp($a, $b);
	if (preg_match('/[A-Z]/', $a))
		return -1;
	if (preg_match('/[A-Z]/', $b))
		return 1;
	if (is_numeric($a))
		return -1;
	if (is_numeric($b))
		return 1;
	return strcmp($a, $b);
}

function cmp($a, $b)
{
	$a_arr = str_split(strtoupper($a));
	$b_arr = str_split(strtoupper($b));
	$na = strlen($a);
	$nb = strlen($b);
	$n = $nb > $na ? $na : $nb;
	for ($i = 0; $i < $n; ++$i)
		if ($res = cmp_single($a_arr[$i], $b_arr[$i]))
			return $res;
	return $na - $nb;
}

$arr = array();
for ($i = 1; $i < $argc; ++$i)
	$arr = array_merge($arr, preg_split("/\\s+/", trim($argv[$i])));
usort($arr, "cmp");
foreach ($arr as $val)
	echo $val, "\n"
?>