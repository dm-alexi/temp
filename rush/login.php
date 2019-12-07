<?php
include("auth.php");

session_start();
if ($_POST["login"] === NULL || $_POST["login"] === "" || $_POST["passwd"] === NULL || $_POST["passwd"] === "" || !auth($_POST["login"], $_POST["passwd"]))
{
	$_SESSION["user"] = "";
	header("Location: index.php");
	echo "ERROR\n";
	exit ;
}
$_SESSION["user"] = $_POST["login"];
if ($_SESSION["user"] === "admin")
    header("Location: admin.php");
else
    header("Location: user.php");
?>