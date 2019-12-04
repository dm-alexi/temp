#!/usr/bin/php
<?php
if ($argc < 2 || !($f = file_get_contents($argv[1])))
	exit;
$pattern1 = "/<([^>]*)title=\"(.*?)\"([^>]*)>/";
$pattern2 = "/<([^>]*)title='(.*?)'([^>]*)>/";
$pattern3 = "/<a([^>]*)>(.*?)</";
$f = preg_replace_callback($pattern1, function($m) { return "<".$m[1]."title=\"".strtoupper($m[2])."\"".$m[3].">"; }, $f);
$f = preg_replace_callback($pattern2, function($m) { return "<".$m[1]."title='".strtoupper($m[2])."'".$m[3].">"; }, $f);
$f = preg_replace_callback($pattern3, function($m) { return "<a".$m[1].">".strtoupper($m[2])."<"; }, $f);
echo $f;
?>