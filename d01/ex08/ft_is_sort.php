<?php
function ft_is_sort($arr)
{
	for ($i = 0, $n = count($arr); $i < $n - 1; ++$i)
		if ($arr[$i] > $arr[$i + 1])
			return false;
	return true;
}
?>
