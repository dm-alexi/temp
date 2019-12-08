<?php
include("manage.php");
session_start();
if ($_SESSION["user"] !== "admin")
{
    header("Location: ../index.php");
    echo "Permission denied.\n";
    exit;
}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>A typical e-shop - administration</title>
		<style>
			table {margin-left: 0; margin-right: auto; border-collapse: collapse; border: solid;}
            td {border: 1px solid; width: 5%; font-size: small;}
            th {border: 1px solid;}
		</style>
	</head>
	<body>
		<h1> Add item: </h1>
		<form action="add_item.php" method="POST">
			id: <input name="id" type="text" value="">
			<br />
			Name: <input name="name" type="text" value="">
			<br />
            Category: <input name="category" type="text" value="">
            <br />
			Description: <input name="description" type="text" value="">
			<br />
			Price: <input name="price" type="text" value="">
			<br />
			Quantity: <input name="quantity" type="text" value="">
			<br />
			Picture: <input name="picture" type="text" value="">
			<br />
			<input type="submit" name="submit" value="Add">
		</form>
		<hr>
		<h1> Stock </h1>
		<table>
			<tr>
				<th>id</th><th>Name</th><th>Category</th><th>Description</th><th>Price</th><th>Quantity</th><th>Picture</th><th>Action</th>
			</tr>
			<?php
				$arr = data_read();
				foreach ($arr as $val)
				{
					$val = explode(";", $val);
					echo '<tr><form action="del_item.php" method="POST">';
					echo "<td width:90;>".$val[0]."</td><td>".$val[1]."</td><td>".$val[2]."</td><td>".$val[3]."</td><td>".$val[4]."</td><td>".$val[5]."</td>";
					echo "<td><img style='width: 13.9rem; height: 115px;' src='../html/assets/images/".$val[6]."'></td>";
					echo '<td><button type="submit" name="submit" value='.$val[0].'>DEL</button></td></form></tr>';
				}
			?>
		</table>
		<hr>
		<h1> Orders </h1>
		<table>
            <tr><th>Name</th><th>Surname</th><th>Phone</th><th>Total sum</th><th>Action</th></tr>
                <?php
                $files = scandir("../data/order/");
                if (count($files) > 2)
                {
                    foreach ($files as $val) {
                        if ($val === "." || $val === "..")
                            continue;
                        $file_name = "../data/order/" . $val;
                        $order = unserialize(file_get_contents($file_name));
                        $total = 0;
                        if ($order[0])
                            foreach ($order[0] as $value)
                                $total += $value['price'] * $value['quantity'];
                        echo "<tr>";
                        echo "<td>" . $order['name'] . "</td>";
                        echo "<td>" . $order['surname'] . "</td>";
                        echo "<td>" . $order['phone'] . "</td>";
                        echo "<td>" . $total. "</td>";
//                        echo '<td><form action="confirm_order.php" method="POST"><button type="submit" name="submit" value='.$file_name.'>Confirm</button></form>';
                        echo '<td><form action="delete_order.php" method="POST"><button type="submit" name="submit" value='.$file_name.'>DEL</button></form></td>';
                        echo "</tr>";
                    }
                }
                else  {
                    echo "<tr>";
                    echo "<td colspan='5'>" . "<div align='center'>NO ORDER</div>" . "</td>";
                    echo "</tr>";
                }
                ?>
		</table>
		<hr>
		<h1> Users </h1>
		<table>
			<?php
				$users = unserialize(file_get_contents("../private/passwd"));
				foreach ($users as $key => $val)
				{
					echo '<tr><form action="del_user.php" method="POST">';
					echo "<td>".$val["login"]."</td>";
					echo "<td>";
					if ($val["login"] !== "admin")
						echo '<button type="submit" name="submit" value='.$key.'>DEL</button></form></tr>';
					echo "</td>";
				}
			?>
		</table>
		<hr>
		<form action=logout.php method=$_POST>
			<input type="submit" name="submit" value="Log out">
		</form>
	</body>
</html>