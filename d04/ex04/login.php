<?php
include("auth.php");

session_start();
if ($_POST["login"] === NULL || $_POST["login"] === "" || $_POST["passwd"] === NULL || $_POST["passwd"] === "" || !auth($_POST["login"], $_POST["passwd"]))
{
	$_SESSION["loggued_on_user"] = "";
	header("Location: index.html");
	echo "ERROR\n";
	exit ;
}

$_SESSION["loggued_on_user"] = $_POST["login"];
?>
<!DOCTYPE html>
<html>
<head>
		<meta charset="utf-8">
		<title>42chat</title>
	</head>
	<body>
		<h1 style="text-align:center;">42chat</h1>
		<iframe name="chat" src="chat.php" height=550px width=100%></iframe>
		<iframe name="speak" src="speak.php" height=50px width=100%></iframe>
		<form action="logout.php">
			<input type="submit" name="logout" value="Log out">
		</form>
	</body>
</html>