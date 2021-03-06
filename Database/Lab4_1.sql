-- Creating Tables
CREATE DATABASE LAB4;

CREATE TABLE EMP (
	EMPLOYEE_ID INT PRIMARY KEY,
	FIRST_NAME VARCHAR(30),
	LAST_NAME VARCHAR(30),
	EMAIL VARCHAR(30),
	PHONE_NUMBER VARCHAR(30),
	HIRE_DATE DATE,
	JOB_ID VARCHAR(30),
	JOB_TITLE VARCHAR(30),
	COMMISSION_PCT FLOAT,
	MANAGER_ID INT,
	DEPARTMENT_ID INT,
	SALARY INT
);

CREATE TABLE DEPT (
	DEPARTMENT_ID INT, 
	DEPARTMENT_NAME VARCHAR(60),
	MANAGER_ID INT,
	LOCATION_ID INT,
	PRIMARY KEY (DEPARTMENT_ID)
);

CREATE TABLE LOCA (
	LOCATION_ID INT PRIMARY KEY,
	STREET_ADDRESS VARCHAR(60),
	POSTAL_CODE INT,
	CITY VARCHAR(30),
	STATE_PROVINCE VARCHAR(60),
	COUNTRY_ID INT
);

-- Adding References
ALTER TABLE DEPT
ADD FOREIGN KEY (LOCATION_ID) REFERENCES LOCA(LOCATION_ID);

-- Trucnate table
TRUNCATE TABLE EMP;
TRUNCATE TABLE DEPT;
TRUNCATE TABLE LOCA;

-- Inserting Data

INSERT INTO EMP
VALUES (163, 'Clara', 'Dutta', 'Clara@gmail.com', 9998887776, '1899-12-01', 1, 'IT_PROG', 100.0, 100, 1, 4000),
	(1, 'Aditya', 'Kumar', 'Aditya@gmail.com', 8449980904, '1997-01-31', 4, 'ST_PROG', 154.123, 1, 2, 8000),
	(2, 'Adarsh', 'Patel', 'Adarsh@gmail.com', 9876543210, '1999-04-30', 2, 'IT_PROG', 1231.12, 10, 9, 1000),
	(183, 'Ashutosh', 'Pandey Ji', 'Ashutosh@gmail.com', 9825609564, '1998-12-22', 3, 'ST_PROG', 1523.123, 1, 4, 1500),
	(5, 'Anoop', 'Kumar', 'Anoop@gmail.com', 9872346754, '1992-08-22', 3, 'IT_PROG', 10.1, 159, 5, 2500),
	(134, 'Karan', 'Purswani', 'Karan@gmail.com', 9872309876, '2014-09-12', 1, 'IT_PROG', 13.43, 154, 6, 3000),
	(7, 'Omkar', 'Sardesai', 'Omkar@gmail.com', 8712345671, '2019-07-07', 2, 'ST_PROG', 152.0, 9, 7, 3500),
	(159, 'Ravij', 'Sankar', 'Ravi@gmail.com', 9837123000, '2011-03-29', 3, 'IT_PROG', 878.0, 203, 8, 5000),
	(9, 'Ashutosh J', 'Singh', 'Ashutosh@gmail.com', 9890007776, '2013-12-19', 4, 'IT_PROG', 1213.213, 10, 1, 1000),
	(10, 'Arun', 'Shrivastava', 'Arun@gmail.com', 8778877899, '2002-04-19', 4, 'ST_PROG', 1213.213, 1, 1, 500),
	(121, 'Dhruv', 'Bodani', 'Dhruv@gmail.com', 9886552330, '1998-10-25', 4, 'IT_PROG', 199.99, 1, 11, 6300),
	(133, 'Jayadev', 'P', 'Jayadev@gmail.com', 7878676754, '1997-06-22', 4, 'ST_PROG', 200.05, 2, 3, 3000);

INSERT INTO DEPT
VALUES (1, 'Administration', 1, 1),
	(2, 'Marketing', 2, 2),
	(3, 'Purchasing', 3, 3),
	(4, 'Human  Resources', 4, 4),
	(5, 'Shipping IT', 5, 1),
	(6, 'Public Relations', 6, 2),
	(7, 'Sales', 7, 3),
	(8, 'Executive', 8, 4),
	(9, 'Finance', 9, 1),
	(10, 'Accounting', 10, 2),
	(11, 'Treasury', 1, 3),
	(12, 'Corporate Tax', 2, 4),
	(13, 'Control And Credit', 3, 1),
	(14, 'Shareholder Services', 4, 2),
	(15, 'Manufacturing', 5, 3),
	(16, 'Construction', 6, 4),
	(17, 'Contracting', 7, 1),
	(18, 'IT Support, ', 8, 2),
	(19, 'IT Helpdesk', 9, 3),
	(20, 'Government Sales', 10, 4),
	(21, 'Retail Sales', 1, 1),
	(22, 'Recruiting', 2, 2),
	(23, 'Payroll  ', 3, 3);

INSERT INTO LOCA
VALUES (1, 'Some street in Toronto', '2342', 'Toronto', 'USA', 1),
	(2, 'Some street in London', '5678', 'London', 'UK', 2),
	(3, 'Some street in Switzerland', '4321', 'Switzerland', 'Germany', 3),
	(4, 'Some street in San Jose', '1234', 'San Jose', 'USA', 4);

-- 1)
SELECT FIRST_NAME, LAST_NAME
FROM EMP
WHERE EMP.SALARY > (SELECT SALARY FROM EMP WHERE EMP.EMPLOYEE_ID = 163);

-- 2)
SELECT FIRST_NAME, LAST_NAME, SALARY, DEPARTMENT_ID, JOB_ID
FROM EMP
WHERE EMP.DEPARTMENT_ID = (SELECT DEPARTMENT_ID FROM EMP WHERE EMP.EMPLOYEE_ID = 163);

-- 3)
SELECT FIRST_NAME, LAST_NAME, SALARY, DEPARTMENT_ID
FROM EMP
WHERE SALARY = (SELECT MIN(SALARY) FROM EMP);

-- 4)
SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME
FROM EMP
WHERE SALARY > (SELECT AVG(SALARY) FROM EMP);

-- 5)
SELECT FIRST_NAME, LAST_NAME, EMPLOYEE_ID, SALARY
FROM EMP
WHERE EMP.MANAGER_ID = (SELECT EMPLOYEE_ID FROM EMP WHERE EMP.FIRST_NAME = 'Arun');

-- 6)
SELECT DEPT.DEPARTMENT_ID, EMP.FIRST_NAME, EMP.LAST_NAME, EMP.JOB_ID, DEPT.DEPARTMENT_NAME
FROM EMP
INNER JOIN
DEPT ON EMP.DEPARTMENT_ID = DEPT.DEPARTMENT_ID
WHERE DEPT.DEPARTMENT_NAME = 'Finance';

-- 7)
SELECT *
FROM EMP
WHERE SALARY = 3000 AND EMPLOYEE_ID = 121;

-- 8)
SELECT *
FROM EMP
WHERE EMPLOYEE_ID IN (134, 159, 183);

-- 9)
SELECT *
FROM EMP
WHERE SALARY BETWEEN 1000 AND 3000;

-- 10)
SELECT *
FROM EMP
WHERE SALARY BETWEEN (SELECT MIN(SALARY) FROM EMP) AND 2500;

-- 11)
SELECT *
FROM EMP
WHERE EMPLOYEE_ID NOT IN (SELECT MANAGER_ID FROM EMP WHERE MANAGER_ID BETWEEN 100 AND 200); 

-- 12)  
SELECT *
FROM EMP
WHERE EMPLOYEE_ID IN (SELECT EMPLOYEE_ID FROM EMP WHERE SALARY = (SELECT MAX(SALARY) FROM EMP WHERE SALARY != (SELECT MAX(SALARY) FROM EMP)));

-- 13)
SELECT FIRST_NAME, LAST_NAME, HIRE_DATE
FROM EMP
WHERE EMP.DEPARTMENT_ID = (SELECT DEPARTMENT_ID FROM EMP WHERE EMP.FIRST_NAME = 'Clara')
	AND EMP.FIRST_NAME != 'Clara';

-- 14)
SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME
FROM EMP
WHERE DEPARTMENT_ID IN (SELECT DEPARTMENT_ID FROM EMP WHERE FIRST_NAME LIKE '%T%' OR LAST_NAME LIKE '%T%');

-- 15)
SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME
FROM EMP
WHERE DEPARTMENT_ID IN (SELECT DEPARTMENT_ID FROM EMP WHERE FIRST_NAME LIKE '%J%' OR LAST_NAME LIKE '%J%')
	AND SALARY > (SELECT AVG(SALARY) FROM EMP);

-- 16)
SELECT FIRST_NAME, LAST_NAME, EMPLOYEE_ID, JOB_TITLE
FROM EMP
INNER JOIN DEPT
ON DEPT.DEPARTMENT_ID = EMP.DEPARTMENT_ID
INNER JOIN LOCA
ON LOCA.LOCATION_ID = DEPT.LOCATION_ID
WHERE LOCA.CITY = 'Toronto';

-- 17)
SELECT PHONE_NUMBER, FIRST_NAME, LAST_NAME, JOB_TITLE
FROM EMP
WHERE EMP.SALARY < ANY(SELECT SALARY FROM EMP WHERE JOB_TITLE = 'IT_PROG');

-- 18)
SELECT PHONE_NUMBER, FIRST_NAME, LAST_NAME, JOB_TITLE
FROM EMP
WHERE EMP.SALARY < ANY(SELECT SALARY FROM EMP WHERE JOB_TITLE = 'IT_PROG') AND JOB_TITLE != 'IT_PROG';

-- 19)
SELECT PHONE_NUMBER, FIRST_NAME, LAST_NAME, JOB_TITLE
FROM EMP
WHERE EMP.SALARY > ALL(SELECT SALARY FROM EMP WHERE JOB_TITLE = 'IT_PROG') AND JOB_TITLE != 'IT_PROG';

-- 20)
SELECT PHONE_NUMBER, FIRST_NAME, LAST_NAME, JOB_TITLE
FROM EMP
WHERE EMP.SALARY > ANY(SELECT AVG(SALARY) FROM EMP GROUP BY EMP.DEPARTMENT_ID);

-- 21)
SELECT *
FROM EMP
WHERE SALARY = (SELECT DISTINCT SALARY FROM EMP WHERE SALARY != (SELECT MIN(SALARY) FROM EMP) ORDER BY SALARY ASC LIMIT 1);

-- 22)
SELECT LOCA.CITY
FROM EMP
INNER JOIN DEPT
ON DEPT.DEPARTMENT_ID = EMP.DEPARTMENT_ID
INNER JOIN LOCA
ON LOCA.LOCATION_ID = DEPT.LOCATION_ID
WHERE EMPLOYEE_ID = 134;

-- 23)
SELECT EMP.FIRST_NAME, EMP.LAST_NAME, EMP.SALARY, EMP.DEPARTMENT_ID
FROM EMP
INNER JOIN DEPT
ON DEPT.DEPARTMENT_ID = EMP.DEPARTMENT_ID
INNER JOIN LOCA
ON LOCA.LOCATION_ID = DEPT.LOCATION_ID
WHERE LOCA.CITY = 'London';


-- 24)
SELECT EMP.FIRST_NAME, EMP.LAST_NAME, EMP.SALARY, EMP.DEPARTMENT_ID
FROM EMP
WHERE SALARY > (SELECT AVG(SALARY) FROM EMP)
ORDER BY SALARY DESC;

-- 25)
SELECT *
FROM EMP AS A
WHERE EXISTS(SELECT MANAGER_ID FROM EMP WHERE A.EMPLOYEE_ID = EMP.MANAGER_ID);

-- 26)
SELECT A.FIRST_NAME, A.LAST_NAME
FROM EMP AS A
WHERE SALARY > (SELECT SUM(SALARY) FROM EMP WHERE A.DEPARTMENT_ID = EMP.DEPARTMENT_ID) * 0.5;

-- 27)
SELECT DISTINCT *
FROM DEPT
WHERE (SELECT COUNT(EMPLOYEE_ID) FROM EMP WHERE EMP.DEPARTMENT_ID = DEPT.DEPARTMENT_ID) > 0;

-- 28)
SELECT EMP.FIRST_NAME, EMP.LAST_NAME, DEPT.DEPARTMENT_NAME
FROM EMP
INNER JOIN DEPT
ON EMP.DEPARTMENT_ID = DEPT.DEPARTMENT_ID
WHERE EXISTS(SELECT EMPLOYEE_ID FROM EMP WHERE SALARY > 3700);

-- 29)
SELECT DEPARTMENT_ID, DEPARTMENT_NAME
FROM DEPT
WHERE NOT EXISTS(SELECT EMPLOYEE_ID FROM EMP WHERE DEPT.DEPARTMENT_ID = EMP.EMPLOYEE_ID);