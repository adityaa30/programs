CREATE DATABASE LAB8;
USE LAB8;

create table EMP (
    EMPNO numeric (6),
    ENAME varchar (20),
	JOB varchar (10),
	DEPTNO numeric (3),
	SAL numeric (7,2),
	primary key (EMPNO),
	foreign key (DEPTNO) references DEPT(DEPTNO)
);

create table DEPT (
	DEPTNO numeric (2),
	DNAME varchar (30),
	LOC varchar (20)
);

insert into EMP
values (163, 'Clara Dutta', 'IT_PROG', 1, 1000.0),
	(1, 'Aditya Kumar', 'ST_PROG', 2, 1054.123),
	(2, 'Adarsh Patel', 'IT_PROG', 3, 10231.12),
	(183, 'Ashutosh Pandey', 'ST_PROG', 4, 10523.123),
	(5, 'Anoop Kumar', 'IT_PROG', 5, 100.1),
	(134, 'Karan Purswani', 'IT_PROG', 1, 103.43),
	(7, 'Omkar Sardesai', 'ST_PROG', 2, 1052.0),
	(159, 'Ravij Sankar', 'IT_PROG', 3, 8078.0),
	(9, 'Ashutosh Singh', 'IT_PROG', 4, 10213.213),
	(10, 'Arun Shrivastava', 'ST_PROG', 5, 10213.213),
	(121, 'Dhruv Bodani', 'IT_PROG', 1, 1099.99),
	(133, 'Jayadev P', 'ST_PROG', 5, 132000.05);

insert into DEPT
values (1, 'Administration', 'NIT Trichy'),
	(2, 'Marketing', 'Mumbai'),
	(3, 'Purchasing', 'IIT Bombay'),
	(4, 'Human Resources', 'IIT Bombay'),
	(5, 'Shipping IT', 'IIT Delhi'),
	(6, 'Public Relations', 'IIT Delhi'),
	(7, 'Sales', 'IIT Kharagpur'),
	(8, 'Executive', 'NIT Trichy'),
	(9, 'Finance', 'NIT Trichy'),
	(10, 'Accounting', 'IIT Delhi');

-- 1)
create procedure DisplayEmployeeDetails(in employeeNumber numeric (6))
SELECT *
FROM EMP
WHERE EMP.EMPNO = employeeNumber;

call DisplayEmployeeDetails(1);

-- 2)
create procedure AddEmployee(
	in empNo numeric (6),
	in empName varchar (20),
	in job varchar (10),
	in deptNo numeric (3),
	in sal numeric (7,2))
insert into EMP 
values (empNo, empName, job, deptNo, sal);

call AddEmployee(123, 'Mohan Kumar', 'IT_PROG', 6, 1000.95);
	
-- 3)
create procedure RaiseSalary(
	in empNo numeric (6),
	in raiseAmount numeric (7, 2))
update EMP set SAl=SAL + raiseAmount where EMP.EMPNO=empNo;

call RaiseSalary(2, 500.25);

-- 4)
create procedure RemoveEmployee(in empName varchar (20))
delete from EMP  where ENAME=empName;

call RemoveEmployee('Adarsh Patel');

-- 5)
create function MinSalary() returns numeric(7,2) DETERMINISTIC
begin
	declare minSal numeric(7,2);
	select min(SAL) into minSal from EMP;
	return minSal;
end

select MinSalary();

-- 6)
create function CountEmployees() returns int DETERMINISTIC
begin
	declare c int;
	select count(SAL) into c from EMP;
	return c;
end;

select CountEmployees();

-- 7)
create procedure DisplaySalary(in empNo numeric (6))
select SAL from EMP where EMP.EMPNO=empNo;

call DisplaySalary(5);

-- 8)
create function Average(deptNo numeric (2)) returns numeric(7,2) DETERMINISTIC
begin
	declare ans numeric(7,2);
	select avg(SAL) into ans from EMP where EMP.DEPTNO=deptNo;
	return ans;
end

select Average(5);

-- 9)
create procedure DisplayDeptEmployees(in deptNo numeric (2))
select ENAME
from EMP
where EMP.DEPTNO=deptNo;

call DisplayDeptEmployees(5);

-- 10)
create function HighestPaid(deptNo numeric (2)) returns numeric(7,2) DETERMINISTIC 
begin
	declare ans numeric(7,2);
	select max(SAL) into ans
	from EMP
	where EMP.DEPTNO=deptNo;
	return ans;
end

create procedure ShowAllSalary()
select HighestPaid(DEPTNO) from DEPT;

call ShowAllSalary();

-- 11)
create function HighPaidEmployees() returns int DETERMINISTIC
begin
	declare ans int;
	select count(empNo) into ans
	from EMP 
	where EMP.SAL > 30000;
	return ans;
end

select HighPaidEmployees();

-- 12)
create function MumbaiCount() returns int DETERMINISTIC
begin
	declare ans int;
	select count(empNo) into ans
	from EMP
	where EMP.DEPTNO = (select DEPTNO from DEPT where DEPT.LOC='Mumbai');
	return ans;
end

select MumbaiCount();