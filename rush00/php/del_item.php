<?php
session_start();
include("manage.php");

if ($_SESSION["user"] !== "admin")
{
	header("Location: ../index.php");
	echo "ERROR\n";
	exit;
}
header("Location: admin.php");
if ($_POST["submit"] === NULL || $_POST["submit"] === "")
{
	echo "ERROR\n";	
	exit;
}
$arr = data_read();
foreach ($arr as $key => $val)
	if (explode(";", $val)[0] === $_POST["submit"])
	{
		unset($arr[$key]);
		break;
	}
data_write($arr);
?>