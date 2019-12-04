#!/usr/bin/php
<?php
if ($argc < 2 || !($ch = curl_init($argv[1])))
	exit;
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
$str = curl_exec($ch);
curl_close($ch);
$dir = strstr($argv[1], "www");
if (!(file_exists($dir)))
	mkdir($dir);
preg_match_all("/<img.*?>/", $str, $arr);
foreach ($arr[0] as $val)
{
	preg_match("/src=\"(.*?)\"/", $val, $tmp);
	$link = preg_match("/^http/", $tmp[1]) ? $tmp[1] : $argv[1].$tmp[1];
	if (!($ch = curl_init($link)))
		continue;
	echo $link."\n";
	$filename = strrchr($link, "/");
	$f = fopen($dir.$filename, "w");
	curl_setopt($ch, CURLOPT_FILE, $f);
	curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
	curl_setopt($ch, CURLOPT_TIMEOUT, 4000);
	$success = curl_exec($ch);
	fclose($f);
	curl_close($ch);
	if (!$success)
		unlink($dir.$filename);
}
?>