<?php
header("Location: ../index.php");
session_start();
session_destroy();
$_SESSION['user'] = NULL;
?>
