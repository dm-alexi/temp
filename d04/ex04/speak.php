<?php
session_start();
if ($_SESSION["loggued_on_user"] === NULL || $_SESSION["loggued_on_user"] === "")
{
	echo "ERROR\n";
	exit;
}
if ($_POST["msg"] !== NULL && $_POST["msg"] !== "")
{
	date_default_timezone_set("Europe/Moscow");
	$filename = "../private/chat";
	if ($f = fopen($filename, "c+"))
	{
		flock($f, LOCK_SH);
		$arr = unserialize(file_get_contents($filename));
		$entry["login"] = $_SESSION["loggued_on_user"];
		$entry["time"] = time();
		$entry["msg"] = $_POST["msg"];
		$arr[] = $entry;
		flock($f, LOCK_EX);
		file_put_contents($filename, serialize($arr));
		flock($f, LOCK_UN);
		fclose($f);
	}
}
?>
<html>
	<head>
		<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
	</head>
	<body>
		<form action="speak.php" method="POST">
			<input type="text" name="msg" placeholder="Enter your message..." value="">
			<input type="submit" name="submit" value="Send">
		</form>
	</body>
</html>