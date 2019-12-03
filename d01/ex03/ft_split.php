<?php
function ft_split($line)
{
	$arr = preg_split("/\\s+/", trim($line));
	sort($arr, SORT_STRING);
	return $arr;
}
?>
