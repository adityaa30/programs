-- Creating Tables
CREATE DATABASE LAB5;

CREATE TABLE ORDERR
(
	OrderId INT PRIMARY KEY,
	CustomerID INT,
	OrderDate DATE
);

CREATE TABLE CUSTOMER
(
	CustomerId INT PRIMARY KEY,
	CustomerName VARCHAR(50),
	ContactName VARCHAR(50),
	Country VARCHAR(30)
);


INSERT INTO ORDERR
VALUES
	(10308, 2, '1996-09-18'),
	(10309, 37, '1996-09-19'),
	(10310, 77, '1996-09-20'),
	(10213, 4, '2019-02-30'),
	(10264, 42, '2018-11-28'),
	(10677, 3, '2012-03-12'),
	(10352, 42, '2003-12-31'),
	(10754, 6, '1998-05-14');


INSERT INTO CUSTOMER
VALUES
	(1, 'Alfreds Futterkiste', 'Maria Anders', 'Germany'),
	(2, 'Ana Trujillo Emparedados y helados', 'Ana Trujillo', 'Mexico'),
	(3, 'Antonio Moreno Taqueira', 'Antonio Moreno', 'Mexico'),
	(4, 'Omkar Sardesai', 'Shivang Mangal', 'India'),
	(5, 'Akash Mani', 'Raj Yadav', 'India'),
	(6, 'Adarsh Patel', 'Shreyas Chauhan', 'India'),
	(7, 'Aditya Kumar', 'Ayush Bansal', 'USA'),
	(8, 'Ashutosh Pandey', 'Nikhil Anu', 'USA');

-- 2)
SELECT *
FROM CUSTOMER
	INNER JOIN ORDERR
	ON CUSTOMER.CustomerId=ORDERR.CustomerId;

-- 3)
SELECT *
FROM CUSTOMER
	LEFT JOIN ORDERR
	ON CUSTOMER.CustomerId=ORDERR.CustomerId;

-- 4)
SELECT *
FROM CUSTOMER
	RIGHT JOIN ORDERR
	ON CUSTOMER.CustomerId=ORDERR.CustomerId;

-- 5)
SELECT *
FROM CUSTOMER, ORDERR
WHERE CUSTOMER.CustomerId=ORDERR.CustomerId;
