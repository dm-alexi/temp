<?php
session_start();
if ($_GET["login"] !== NULL && $_GET["login"] !== "" && $_GET["passwd"] !== NULL && $_GET["passwd"] !== "" && $_GET["submit"] === "OK")
{
	$_SESSION["login"] = $_GET["login"];
	$_SESSION["passwd"] = $_GET["passwd"];
}
?>

<html><body>
	<form action="index.php" method="GET">
		Username: <input name="login" value=<?php echo $_SESSION["login"]?>>
		<br />
		Password: <input name="passwd" type="password" value=<?php echo $_SESSION["passwd"]?>>
		<input type="submit" name="submit" value="OK">
	</form>
</body></html>