<?php
$filename = "../private/chat";
if (file_exists($filename))
	date_default_timezone_set("Europe/Moscow");
	$arr = unserialize(file_get_contents($filename));
	foreach ($arr as $val)
		echo date("[H:i]", $val["time"])." <b>".$val["login"]."</b>: ".$val["msg"]."<br />", "\n";
?>