<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "user_db";

// Create connection
$conn = new mysqli($servername, $username, $password, $database);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Insert into database
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $password = password_hash($_POST['password'], PASSWORD_DEFAULT);
    $age = $_POST['age'];
    $gender = $_POST['gender'];

    $stmt = $conn->prepare("INSERT INTO users (name, email, password, age, gender) VALUES (?, ?, ?, ?, ?)");
    $stmt->bind_param("sssds", $name, $email, $password, $age, $gender);

    if ($stmt->execute()) {
        echo "Signup successful!";
    } else {
        echo "Error: " . $stmt->error;
    }

    $stmt->close();
}
$conn->close();
?>
