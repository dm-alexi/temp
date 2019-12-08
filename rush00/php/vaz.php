<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link rel="stylesheet" href="../html/assets/css/style.css">
    <title>Shop</title>
</head>
<body>
<!-- Navbar -->
<form action="../php/add_box.php" method="post">
    <div class="container">
        <nav class="navbar navbar-expand-lg navbar-light bg-light">
            <a class="navbar-brand" href="../index.php">Car</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>

            <div class="collapse navbar-collapse" id="navbarSupportedContent">
                <ul class="navbar-nav mr-auto">
                    <li class="nav-item">
                        <a class="nav-link" href="ferrari.php">Ferrari</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="am.php">Aston Martin</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="vaz.php">VAZ</a>
                    </li>
                </ul>
                <ul class="nav justify-content-end" >
                    <li class="nav-item">
                    </li>
                    <li>
                    <a class="nav-link active" href="../php/add_box.php" role="button">Box</a>
                    </li>
                    <li class="nav-item">
                        <?php
                        if (!isset($_SESSION['activ'])) {
                           echo "<a class='nav-link active' href = '../html/register.html' role = 'button' > Register</a >";
                        }
                        else
                            echo "<span class='nav-link active' role = 'button' >" . $_SESSION['user'] . "</span >";
                        ?>
                    </li>
                    <li class="nav-item">
                        <?php
                        if (!isset($_SESSION['activ'])) {
                            echo "<a class=\"nav-link active\" href=\"../html/sign_in.html\" role=\"button\">Sign In</a>";
                        }
                        else
                            echo "<a class=\"nav-link active\" href=\"../php/logout.php\" role=\"button\">Log out</a>";
                        ?>
                    </li>
                </ul>
            </div>
        </nav>
        <br>

        <div id="carouselExampleControls" class="carousel slide" data-ride="carousel">
            <div class="carousel-inner">
                <div class="carousel-item active">
                    <img src="../html/assets/images/vaz1.jpg" class="d-block w-100" alt="#">
                </div>
                <div class="carousel-item">
                    <img src="../html/assets/images/vaz2.jpg" class="d-block w-100" alt="...">
                </div>
                <div class="carousel-item">
                    <img src="../html/assets/images/vaz3.jpg" class="d-block w-100" alt="...">
                </div>
            </div>
            <a class="carousel-control-prev" href="#carouselExampleControls" role="button" data-slide="prev">
                <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                <span class="sr-only">Previous</span>
            </a>
            <a class="carousel-control-next" href="#carouselExampleControls" role="button" data-slide="next">
                <span class="carousel-control-next-icon" aria-hidden="true"></span>
                <span class="sr-only">Next</span>
            </a>
        </div>
        <br>
        <div class="row">
            <div class="col-sm">
                <div class="card" style="width: 18rem; height: 22rem;">
                    <img src="../html/assets/images/vaz1.jpg" class="card-img-top" style="width: 17.9rem; height: 150px;" alt="...">
                    <div class="card-body">
                        <h5 class="card-title">Car 1</h5>
                        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
                        <!--                          <a href="cart.html" class="btn btn-primary">Add to cart</a>-->
                        <button type="submit" class="btn btn-primary" name="id" value="6">Add to cart</button>
                    </div>
                </div>
            </div>
            <div class="col-sm">
                <div class="card" style="width: 18rem; height: 22rem;">
                    <img src="../html/assets/images/vaz2.jpg" class="card-img-top" style="width: 17.9rem; height: 150px;" alt="...">
                    <div class="card-body">
                        <h5 class="card-title">Car 2</h5>
                        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
                        <!--                        <a href="cart.html" class="btn btn-primary">Add to cart</a>-->
                        <button type="submit" class="btn btn-primary" name="id" value="7">Add to cart</button>
                    </div>
                </div>
            </div>
            <div class="col-sm">
                <div class="card" style="width: 18rem; height: 22rem;">
                    <img src="../html/assets/images/vaz3.jpg" class="card-img-top" style="width: 17.9rem; height: 150px;" alt="...">
                    <div class="card-body">
                        <h5 class="card-title">Car 3</h5>
                        <p class="card-text">Some quick example text to build on the card title and make up the bulk of the card's content.</p>
                        <!--                          <a href="cart.html" class="btn btn-primary">Add to cart</a>-->
                        <button type="submit" class="btn btn-primary" name="id" value="8">Add to cart</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</form>
</body>
</html>
