<?php
function sorted_up($arr)
{
	for ($i = 0, $n = count($arr); $i < $n - 1; ++$i)
		if ($arr[$i] > $arr[$i + 1])
			return false;
	return true;
}

function sorted_down($arr)
{
	for ($i = 0, $n = count($arr); $i < $n - 1; ++$i)
		if ($arr[$i] < $arr[$i + 1])
			return false;
	return true;
}

function ft_is_sort($arr)
{
	if (!is_array($arr))
		return NULL;
	return (sorted_up($arr) || sorted_down($arr));
}
?>
