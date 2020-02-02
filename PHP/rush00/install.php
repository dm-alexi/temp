#!/usr/bin/php
<?php
$user [] = array ("login" => 'admin', "passwd" => hash('whirlpool', 'admin'));
mkdir("private");
mkdir("data/order");
mkdir("data/box");
file_put_contents("private/passwd", serialize($user));
?>