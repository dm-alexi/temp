<?php
if ($_GET["login"] !== NULL && $_GET["passwd"] !== NULL && $_GET["submit"] === "OK")
{
	$_SESSION["login"] = $_GET["login"];
	$_SESSION["passwd"] = $_GET["passwd"];
}
?>