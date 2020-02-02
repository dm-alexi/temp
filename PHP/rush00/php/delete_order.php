<?php
session_start();
if ($_SESSION["user"] !== "admin")
{
    header("Location: ../index.php");
    echo "Permission denied.\n";
    exit;
}
header("Location: admin.php");
unlink($_POST['submit']);
?>