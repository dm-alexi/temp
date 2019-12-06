<?php
function auth($login, $passwd)
{
	$filename = "../private/passwd";
	if (!file_exists($filename) || !($arr = unserialize(file_get_contents($filename))))
		return false;
	foreach ($arr as $val)
		if ($val["login"] === $login)
			return ($val["passwd"] === hash("whirlpool", $passwd));
	return false;
}
?>