<?php
$filename = "list.csv";
$arr = explode("\n", file_get_contents($filename));
foreach ($arr as $key => $val)
    if ($val === $_GET['id'] . ";" . $_GET['text'])
    {
        unset($arr[$key]);
        break;
    }
file_put_contents($filename, implode("\n", $arr));
?>