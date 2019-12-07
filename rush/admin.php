<?php
include("manage.php");
session_start();
if ($_SESSION["user"] !== "admin")
{
    header("Location: index.php");
    echo "Permission denied.\n";
    exit;
}
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>A typical e-shop - administration</title>
	</head>
	<body>
		<form action="add_item.php" method="POST">
			Title: <input name="title" type="text" value="">
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
			<hr>
		<?php
			$arr = data_read();
			foreach ($arr as $key => $val)
			{
				$val = explode(";", $val);
				echo '<form action="del_item.php" method="POST">';
				echo '<div style="display:inline; width:100;">'.($key + 1)." ".$val[0]."</div>";
				echo '<button type="submit" name="submit" value='.$key.'>DEL</button><br /></form>';
			}
		?>
	</body>
</html>
