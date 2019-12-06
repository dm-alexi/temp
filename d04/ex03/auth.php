<?php
function auth($login, $passwd)
{
	$filename = "../private/passwd";
	$arr = unserialize(file_get_contents($filename));
	foreach ($arr as $val)
		if ($val["login"] === $login)
			return ($val["passwd"] === hash("whirlpool", $passwd));
	return false;
}
?>