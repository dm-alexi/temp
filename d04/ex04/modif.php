<?php
header("Location: index.html");
$filename = "../private/passwd";
if ($_POST["login"] !== NULL && $_POST["login"] !== "" && $_POST["oldpw"] !== NULL && $_POST["oldpw"] !== "" && $_POST["newpw"] !== NULL && $_POST["newpw"] !== ""
	&& $_POST["submit"] === "OK" && ($arr = file_get_contents($filename)) !==false)
{
	$arr = unserialize($arr);
	$success = false;
	foreach ($arr as $key => $val)
		if ($val["login"] === $_POST["login"])
		{
			if ($val["passwd"] === hash("whirlpool", $_POST["oldpw"]))
			{
				$arr[$key]["passwd"] = hash("whirlpool", $_POST["newpw"]);
				if (file_put_contents($filename, serialize($arr)))
					$success = true;
			}
			break;
		}
	echo ($success ? "OK\n" : "ERROR\n");
}
else
	echo "ERROR\n";
?>