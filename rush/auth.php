<?php

function auth_admin($passwd)
{
    $filename = "admin/passwd";
    if (file_exists($filename) && file_get_contents($filename) === hash("whirlpool", $passwd))
        return false;
    if (!file_exists($filename))
        file_put_contents($filename, file_put_contents(hash("whirlpool", $passwd)));
    return true;
}

function auth($login, $passwd)
{
    if ($login === "admin")
        return auth_admin($passwd);
    $filename = "private/passwd";
	if (!file_exists($filename) || !($arr = unserialize(file_get_contents($filename))))
		return false;
	foreach ($arr as $val)
		if ($val["login"] === $login)
			return ($val["passwd"] === hash("whirlpool", $passwd));
	return false;
}
?>