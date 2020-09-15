-- 1) Creating tables
CREATE TABLE EMP (
	EMPNO INT(6) PRIMARY KEY,
	ENAME VARCHAR(20),
	JOB VARCHAR(10),
	DEPT VARCHAR(10),
	DEPTNO INT(3), 
	SAL REAL(7,2)
);

-- 2)
INSERT INTO EMP
VALUES (1, 'Ashutosh', 'Student', 'CSE', 1, 10000),
	(2, 'Adarsh', 'Student', 'ECE', 3, 2000),
	(3, 'Ashutosh', 'Student', 'CSE', 1, 5000),
	(4, 'Aditya', 'Student', 'EEE', 4, 35000),
	(5, 'Anoop', 'Student', 'CSE', 1, 20000),
	(6, 'Karan', 'Master', 'CSE', 1, 3000),
	(7, 'Omkar', 'Teacher', 'CHEM', 2, 1000),
	(8, 'Arjun', 'Staff', 'CHEM', 2, 5000),
	(9, 'Solomon', 'Teacher', 'EEE', 4, 15000),
	(10, 'Arun', 'Staff', 'CSE',1, 25000);

-- 3)

SELECT * 
FROM EMP
WHERE ENAME LIKE '%A%';


-- 4)
SELECT * 
FROM EMP
WHERE ENAME NOT LIKE '%A%';

-- 5)
SELECT * 
FROM EMP
WHERE SAL > 15000 AND SAL < 30000;

-- 6)
SELECT SUM(SAL) AS Total, AVG(SAL) AS Average FROM EMP;

-- 7)
SELECT COUNT(EMPNO) FROM EMP;

-- 8)
SELECT MIN(SAL) AS min_salary ,MAX(SAL) AS max_salary FROM EMP;

-- 9)
SELECT MAX(SAL) - MIN(SAL) AS Difference FROM EMP;

-- 10)
SELECT COUNT(DISTINCT JOB) FROM EMP;

-- 11)
SELECT * 
FROM EMP
WHERE SAL > (SELECT MIN(SAL) FROM EMP) AND JOB LIKE 'M%';

-- 12)
SELECT * 
FROM EMP
WHERE SAL = (SELECT MAX(SAL) FROM EMP);

-- 13)
SELECT * FROM EMP
WHERE ENAME = 'Arjun' OR ENAME = 'Solomon' OR ENAME = 'Arun';

-- 14)
SELECT DEPT, COUNT(EMPNO) 
FROM EMP
GROUP BY DEPT;

-- 15)
SELECT substr(ENAME, 1, 5) FROM EMP;

-- 16)
SELECT substr(ENAME, LENGTH(ENAME) - 5, 3) FROM EMP;

