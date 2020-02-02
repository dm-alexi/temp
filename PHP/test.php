<?php
$arr[0] = "";
$arr[1] = NULL;
$arr[2] = 0;

foreach ($arr as $key => $val)
{
	print $key . "\t" . $val . "\t" . isset($arr[$key]) . PHP_EOL;
}
print (isset($arr[4]) ? "y" : "n");
?>