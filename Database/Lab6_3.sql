create table Employee (
	Emp_no int,
	Dept_no int,
	Job varchar(20),
	Salary int,
	primary key(Emp_no),
	foreign key (Dept_no) references Dept(Dept_no)
);

create table Dept (
	Dept_no int,
	Dept_name varchar(20),
	primary key(Dept_no)
);

insert into Employee
values (1, 1, 'student', 10000),
	(2, 2, 'prof', 100000);

insert into Dept
values (1, 'CSE'),
	(2, 'MME');


insert into Dept
values (null, 'Civil');

create trigger chkNull
after insert
on Dept
for each row
delete from Dept where new.Dept_no is null;


create trigger onDlt
after delete
on Dept
for each row
delete from Employee where Employee.Dept_no = new.Dept_no;


create trigger insUpd
before insert
on Dept
for each row
CALL RAISE_APPLICATION_ERR0R('auth error');