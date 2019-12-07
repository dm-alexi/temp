<?php
include("auth.php");

session_start();
if ($_GET["login"] !== NULL && $_GET["login"] !== "" && $_GET["passwd"] !== NULL && $_GET["passwd"] !== "" && auth($_GET["login"], $_GET["passwd"]))
{
	$_SESSION["loggued_on_user"] = $_GET["login"];
	echo "OK\n";
	exit;
}
if ($_POST["login"] !== NULL && $_POST["login"] !== "" && $_POST["passwd"] !== NULL && $_POST["passwd"] !== "" && auth($_POST["login"], $_POST["passwd"]))
{
	$_SESSION["loggued_on_user"] = $_POST["login"];
	echo "OK\n";
	exit;
}
$_SESSION["loggued_on_user"] = "";
echo "ERROR\n";
?>