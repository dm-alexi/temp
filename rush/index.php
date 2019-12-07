<?php
session_start();

?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>A typical e-shop</title>
	</head>
	<body>
        <!--<iframe name="login" src="login.php" height=550px width=100%></iframe>!-->
        <form action="login.php" method="POST">
			Username: <input name="login" value="">
			Password: <input name="passwd" type="password" value="">
			<input type="submit" name="submit" value="OK">
			<hr>
			<a href="create.html">Create new account</a>
			<a href="modif.html">Change password</a>
		</form>
	</body>
</html>