<?php
include("auth.php");
ob_start();
session_start();
if (!$_SESSION['user'])
    $_SESSION['user'] = session_id();
$passwd = $_POST['passwd'];
$login = $_POST['login'];
if ($login && $passwd)
{
    if (auth($login,  $passwd))
    {
        $file_name = "../data/box/".$_SESSION['user'].".csv";
        $_SESSION['activ'] = true;
        if (file_exists($file_name))
        {
            if (file_exists("../data/box/".$login.".csv"))
            {
                $order = unserialize(file_get_contents("../data/box/".$login.".csv"));
                $order[] = unserialize(file_get_contents($file_name));
                file_put_contents("../data/box/".$login.".csv", serialize($order));
                unlink($file_name);
            }
            else
                rename($file_name, "../data/box/".$login.".csv");
        }
        $_SESSION['user'] = $login;
        if ($login === 'admin')
            header("Location: ./admin.php");
        else
            header("Location: ../index.php");
    }
    else
    {
        echo "LOGIN ERROR\n";
        header ("refresh: 2; url=../html/sign_in.html ");
    }
}
else
{
    echo "LOGIN ERROR\n";
    header ("refresh: 2; url=../html/sign_in.html ");
}
?>