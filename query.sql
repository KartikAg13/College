CREATE DATABASE user_db;

USE user_db;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    email VARCHAR(100) UNIQUE,
    password VARCHAR(255),
    age INT,
    gender VARCHAR(10)
);
