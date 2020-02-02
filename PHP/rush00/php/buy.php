<?php
ob_start();
session_start();
if (!$_SESSION['activ'])
{
    header("Location: ../html/sign_in.html");
    exit;
}
$file_name = "../data/box/".$_SESSION['user'].".csv";
if ($_POST['buy'] == 'ok' && $_POST['name'] && $_POST['phone'] && $_POST['address'] && $_POST['surname'] && file_exists($file_name))
{
    $tmp = array($_POST['name'], $_POST['surname'], $_POST['email'], $_POST['phone'], $_POST['address']);
    $keys = array("name", "surname", "email", "phone", "address");
    $order = array_combine($keys, $tmp);
    $order [] = unserialize(file_get_contents($file_name));
    $order_name = "../data/order/" . $_SESSION['user'] . ".csv";
    file_put_contents($order_name, serialize($order));
    unlink($file_name);
    echo "Thanks for you order ;-)";
    header("refresh: 2; url=../index.php");
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link href="../html/assets/css/style.css" rel="stylesheet">
    <title>buy</title>
</head>
<body>
<h1> Enter your information: </h1>
<form action="buy.php" method="POST">
    Name: <input name="name" type="text" value="">
    <br />
    Surname: <input name="surname" type="text" value="">
    <br />
    Email: <input name="email" type="text" value="">
    <br />
    Phone: <input name="phone" type="text" value="">
    <br />
    Delivery address: <input name="address" type="text" value="">
    <br />
    <input class="btn btn-primary" type="submit" name="buy" value="ok">
</form>
<div><a href="../php/add_box.php" class="btn btn-primary">Back in cart</a></div>
</body>
</html>
