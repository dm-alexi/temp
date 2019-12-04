#!/usr/bin/php
<?php
if ($argc < 2)
	exit;
if (!preg_match("/^([Dd]imanche|[Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi) \\d{1,2} ([Jj]anvier|[Ff][eé]vrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]o[uû]t|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd][eé]cembre) \\d{4} \\d{2}:\\d{2}:\\d{2}$/", $argv[1]))
	exit("Wrong Format\n");
$months = array("/[Jj]anvier/", "/[Ff][eé]vrier/", "/[Mm]ars/", "/[Aa]vril/", "/[Mm]ai/", "/[Jj]uin/", "/[Jj]uillet/", "/[Aa]o[uû]t/", "/[Ss]eptembre/", "/[Oo]ctobre/", "/[Nn]ovembre/", "/[Dd][eé]cembre/");
$arr = preg_split("/ /", $argv[1]);
for ($i = 1; $i <= 12; ++$i)
	if (preg_match($months[$i - 1], $arr[2]))
		break;
if (strlen((string)$i) < 2)
	$i = "0".$i;
date_default_timezone_set("UTC");
echo strtotime($arr[3]."-".$i."-".$arr[1]." ".$arr[4]), "\n";
//echo strtotime("2013-11-12 12:02:21"), "\n";
?>