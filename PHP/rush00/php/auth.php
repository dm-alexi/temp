<?php
function auth($login, $passwd)
{
	$user = unserialize(file_get_contents("../private/passwd"));
	foreach ($user as &$log)
		if ($log['login'] === $login)
		{
			if ($log['passwd'] === hash('whirlpool', $passwd))
				return true;
			else
				return false;
		}
}
?>
