#!/usr/bin/php
<?php
if ($argc < 2)
	exit;
echo implode(" ", preg_split("/\\s+/", trim($argv[1]))), "\n";
?>