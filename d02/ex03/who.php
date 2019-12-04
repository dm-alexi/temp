#!/usr/bin/php
<?php
if (!($f = fopen("/var/run/utmpx", "r")))
	exit;
date_default_timezone_set('Europe/Moscow');
fread($f, 628);
while ($tmp = fread($f, 628))
{
	$tmp = unpack("a256login/a4term_id/a32tty/ipid/ilogin_type/itime/imicroseconds/a256hostname/a64reserved", $tmp);
	if ($tmp["login_type"] == 7)
		echo $tmp["login"]." ".$tmp["tty"]."  ".date("M  j G:i", $tmp["time"])."\n";
}
fclose($f);
?>