<?php
header("Location: index.php");
if ($_POST["login"] !== "admin" && $_POST["login"] !== NULL && $_POST["login"] !== "" && $_POST["passwd"] !== NULL && $_POST["passwd"] !== "" && $_POST["submit"] === "OK")
{
	$filename = "credentials/users";
	$user_exists = false;
	if (file_exists($filename) && $arr = unserialize(file_get_contents($filename)))
		foreach ($arr as $user)
            if ($user["login"] === $_POST["login"])
            {
				$user_exists = true;
				break;
			}
	if ($user_exists)
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