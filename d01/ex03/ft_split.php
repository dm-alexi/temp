<?php
function ft_split($line)
{
	if (!is_string($line))
		return NULL;
	$arr = array();
	$line = trim($line);
	while ($tmp = strstr($line, " ", true))
	{
		array_push($arr, $tmp);
		$line = trim(strstr($line, " "));
	}
	if ($line !== "")
		array_push($arr, $line);
	sort($arr, SORT_STRING);
	return $arr;
}
?>
