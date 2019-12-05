#!/usr/bin/php
<?php
if ($argc < 2 || !($ch = curl_init($argv[1])))
	exit;
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
$str = curl_exec($ch);
curl_close($ch);
$dir = strstr($argv[1], "//") !== false ? substr(strstr($argv[1], "//"), 2) : $argv[1];
if (!(file_exists($dir)))
	mkdir($dir);
preg_match_all("/<img.*?>/", $str, $arr);
foreach ($arr[0] as $val)
{
	preg_match("/src=([\"'])(.*?)\\1/", $val, $tmp);
	$link = preg_match("/^http/", $tmp[2]) ? $tmp[2] : $argv[1].$tmp[2];
	if (!($ch = curl_init($link)))
		continue;
	$filename = $dir.strrchr($link, "/");
	$f = fopen($filename, "w");
	curl_setopt($ch, CURLOPT_FILE, $f);
	curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
	curl_setopt($ch, CURLOPT_TIMEOUT, 5000);
	$success = curl_exec($ch);
	fclose($f);
	curl_close($ch);
	if (!$success)
		unlink($filename);
}
?>