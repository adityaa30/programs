create table Emp (
    emp_no int,
    ename varchar(100),
    job varchar(20),
    dept_no int,
    sal float,
    primary key (emp_no)
);

alter table Emp
add experience int;

alter table Emp
drop column experience;

create table Dept (
    dept_no int,
    d_name varchar(10),
    loc varchar(20),
    primary key (dept_no)
);