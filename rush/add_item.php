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
if ($_POST["title"] === NULL || $_POST["title"] === "" || $_POST["category"] === NULL || $_POST["category"] === "" || $_POST["description"] == NULL ||
$_POST["description"] == "" || $_POST["price"] === NULL || $_POST["price"] === "" || $_POST["quantity"] === NULL || $_POST["quantity"] === "" ||
$_POST["picture"] === NULL || $_POST["picture"] === "" || $_POST["submit"] !== "Add")
{
	echo "ERROR\n";	
	exit;
}
$item = implode(";", array($_POST["title"], $_POST["category"], $_POST["description"], $_POST["price"], $_POST["quantity"], $_POST["picture"]));
$arr = data_read();
$arr[] = $item;
data_write($arr);
?>