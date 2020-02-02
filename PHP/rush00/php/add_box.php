<?php
session_start();
if (!$_SESSION['user'])
    $_SESSION['user'] = session_id();
$file_name = "../data/box/".$_SESSION['user'].".csv";
if (file_exists($file_name))
    $order = unserialize(file_get_contents($file_name));
$csv = explode("\n", file_get_contents("../data/data.csv"));  // sozdaem massiv dlia vibora elementa pokupki
if (isset($_POST['id']))
{
    $flag = 0;
    if ($order)
        foreach ($order as &$elem)
            if ($elem['id'] === $_POST['id'])
            {
                $elem['quantity']++;
                $flag = 1;
                break ;
            }
    if ($flag === 0)
    {
        $keys = array("id", "name", "category", "description", "price", "quantity", "img");
        $order[] = array_combine($keys, explode(";", $csv[$_POST['id']]));
        $order[count($order) - 1]['quantity'] = "1";
    }
    file_put_contents($file_name, serialize($order));
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link href="../html/assets/css/style.css" rel="stylesheet">
    <title>cart</title>
</head>
<body>
<div class="container">
    <div class="cart_section">
        <div class="container-fluid">
            <div class="row">
                <div class="col-lg-10 offset-lg-1">
                    <table>
                        <thead>
                        <tr>
                            <th>Item:</th><th>Quantity:</th><th>Price:</th>
                        </tr>
                        </thead>
                        <tbody>
                        <?php
                        $total = 0;
                        $price = 0;
                        if ($order)
                        {
                            foreach ($order as $value)
                            {
                                if ($value['total'])
                                    continue ;
                                $path = "<img src='../html/assets/images/". $value['img']. "' class='card-img-top' style='width: 17.9rem; height: 150px;' alt='...'>";
                                echo "<tr>";
                                echo "<th>" . $path . "</th>";
                                echo "<th>" . $value['quantity'] . "</th>";
                                echo "<th>" . $price = $value['price'] * $value['quantity'] . "</th>";
                                $total += $price;
                                echo "</tr>";
                            }
                            echo "<tr>";
                            echo "<th colspan='4' > <div align='right'><p>Total:" . $total . "</p></div>". "</th>";
                            echo "</tr>";
                        }
                        else {
                            echo "<tr>";
                            echo "<th>". "Box is empty" . "</th>"; // объеденить несколько ячеек строку и столбик и вывести
                            echo "</tr>";
                        }
                        ?>
                        </tbody>
                    </table>
                        </div>
                        <div class="cart_buttons">
                            <a href="../index.php" class="btn btn-primary">Continue shopping</a>
                            <a href="../php/buy.php" class="btn btn-primary">Buy</a>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
</body>
</html>

