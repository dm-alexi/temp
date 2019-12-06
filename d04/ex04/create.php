<?php
header("Location: index.html");
if ($_POST["login"] !== NULL && $_POST["login"] !== "" && $_POST["passwd"] !== NULL && $_POST["passwd"] !== "" && $_POST["submit"] === "OK")
{
	$dir = "../private";
	$filename = "../private/passwd";
	if (!file_exists($dir))
		mkdir($dir);
	$account_exists = false;
	if (file_exists($filename) && ($arr = file_get_contents($filename)) !==false)
	{
		$arr = unserialize($arr);
		foreach ($arr as $val)
			if ($val["login"] === $_POST["login"])
			{
				$account_exists = true;
				break;
			}
	}
	if ($account_exists)
		echo "ERROR\n";
	else
	{
		$arr[] = array("login" => $_POST["login"], "passwd" => hash("whirlpool", $_POST["passwd"]));
		echo (file_put_contents($filename, serialize($arr)) ? "OK\n" : "ERROR\n");
	}
}
else
	echo "ERROR\n";
?>