<?php
include("manage.php");
/*
if ($_SESSION["user"] !== "admin")
{
	header("Location: index.php");
	echo "ERROR\n";
	exit;
}*/
header("Location: admin.php");
if ($_POST["submit"] === NULL || $_POST["submit"] === "")
{
	echo "ERROR\n";	
	exit;
}
$arr = data_read();
unset($arr[$_POST["submit"]]);
data_write($arr);
?>