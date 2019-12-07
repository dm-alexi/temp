<?php
header("Location: index.php");
session_start();
if ($_SESSION["user"] !== "admin" && $_SESSION["user"] !== NULL && $_SESSION["user"] !== "" && $_POST["passwd]"] !== NULL && $_POST["passwd"] !== "")
{
    $filename = "credentials/users";
	$user_not_found = false;
	if (file_exists($filename) && $arr = unserialize(file_get_contents($filename)))
		foreach ($arr as $key => $user)
            if ($user["login"] === $_SESSION["user"])
				if ($user["passwd"] === $_POST["passwd"])
				{
					unset($arr[$key]);
					$_SESSION["user"] = "";
					if (file_put_contents($filename, serialize($arr)))
						exit;
                }
				else
					break;
}
echo "ERROR\n";
?>