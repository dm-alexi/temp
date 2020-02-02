<?php
function data_read()
{
    $filename="../data/data.csv";
    return explode("\n", file_get_contents($filename));
}
function data_write($arr)
{
    $filename="../data/data.csv";
    file_put_contents($filename, implode("\n", $arr));
}
?>