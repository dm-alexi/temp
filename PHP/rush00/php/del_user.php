<?php
session_start();
if ($_SESSION["user"] !== "admin")
{
	header("Location: ../index.php");
	echo "ERROR\n";
	exit;
}
header("Location: admin.php");
if ($_POST["submit"] === NULL || $_POST["submit"] === "" || $_POST["submit"] === 0)
{
	echo "ERROR\n";	
	exit;
}
$users = unserialize(file_get_contents("../private/passwd"));
unset($users[$_POST['submit']]);
$_SESSION[$users[$_POST['submit']]] = NULL;
file_put_contents("../private/passwd", serialize($users));
?>