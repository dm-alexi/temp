<?php

if ($_POST['login'] && $_POST['passwd'])
{
	header("Location: ../html/sign_in.html");
	if (!file_exists("../private"))
		mkdir("../private");
	if (!file_exists("../private/passwd"))
	{
		$user [] = array ("login" => $_POST['login'], "passwd" => hash('whirlpool', $_POST['passwd']));
		file_put_contents("../private/passwd", serialize($user));
	}
	if (file_exists("../private/passwd"))
	{
		$user = unserialize(file_get_contents("../private/passwd"));
		if ($user)
		{
			foreach ($user as $log)
			{
				if ($log['login'] === $_POST['login'])
				{
					echo "ERROR\n";
					exit ;
				}
			}
		}
	}
	$user [] = array ("login" => $_POST['login'], "passwd" => hash('whirlpool', $_POST['passwd']));
	file_put_contents("../private/passwd", serialize($user));
	echo "OK\n";
}
else
	echo "ERROR\n";
?>
