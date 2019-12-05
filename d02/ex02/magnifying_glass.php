#!/usr/bin/php
<?php
if ($argc < 2 || !($f = file_get_contents($argv[1])))
	exit;
$f = preg_replace_callback("/<a (.*?)\/a>/s", function($m)
{
	$m[1] = preg_replace_callback("/ title=([\"'])(.*?)\\1/s", function($m)
	{
		return " title=".$m[1].strtoupper($m[2]).$m[1];
	}, $m[1]);
	$m[1] = preg_replace_callback("/(>(.*?)<)/s", function($m)
	{
		return strtoupper($m[0]);
	}, $m[1]);
	return "<a ".$m[1]."/a>";
}, $f);
echo $f;
?>