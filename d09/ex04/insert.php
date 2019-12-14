<?php
$filename = "list.csv";
$arr = file_exists($filename) ? explode("\n", file_get_contents($filename)) : array();
array_unshift($arr, $_GET['id'] . ";" . $_GET['text']);
file_put_contents($filename, implode("\n", $arr));
?>