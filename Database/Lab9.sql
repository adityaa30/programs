create database Lab9;
use Lab9;

-- 1)
create table EMP (
	EMPNO int not null,
	ENAME varchar(20),
	JOB varchar(10),
	DEPTNO int,
	SAL float(7,2),
	primary key (EMPNO)
) type=INNODB;

insert into EMP VALUES (1,'Aditya','Sysad',1,12000);

start transaction;

select * from EMP;
delete from EMP where EMPNO=1;
select * from EMP;
rollback;

select * from EMP;

-- 2)
create table Customer (
	CustId int not null,
	CustName varchar(20),
	primary key (CustId)
);

describe Customer;

create table Item (
	ItemId int not null,
	ItemName varchar(20),
	ItemPrice int,
	primary key (ItemId)
);

create table Sale (
	BillNo int not null,
	BillData datetime,
	CustId int not null,
	ItemId int not null,
	QtySold int, 
	primary key (BillNo),
	foreign key (CustId) references Customer(CustId),
	foreign key (ItemId) references Item(ItemId)
);

describe Sale;

insert into Customer 
	values (1,'Aditya'),
	(2,'Adarsh'),
	(3,'Mahesh'),
	(4,'Surya');

insert into Item
	values (1,'Toy',20),
	(2,'button',5),
	(3,'gun',500);	

insert into Sale 
	values (1,current_date,1,1,10),
	(2,current_date,2,1,10),
	(3,'2019-11-12',3,3,1);

select BillNo, CustName, ItemName 
from Customer c, Sale s, Item i 
where c.CustId=s.CustId 
	and i.ItemId=s.ItemId 
	and s.BillData=current_date;

select BillNo, QtySold, ItemPrice, (ItemPrice*QtySold) as total \
from Sale s, Item i where i.ItemId=s.ItemId;

select c.CustId, c.CustName 
from Customer c, Sale s, Item i
where i.ItemPrice > 200
	and i.Itemid=s.Itemid
	and c.CustId=s.CustId;

select sum(QtySold) from Sale group by CustId;

insert into Customer
 values (5,'new guy');
insert into Sale 
	values (102,current_date,5,1,10),
	(10,current_date,5,2,5);

select distinct(i.ItemName) 
from Sale s, Item i, Customer c
where c.CustId=s.CustId
	and i.ItemId=s.ItemId
	and s.CustId=5;

select s.ItemId , ItemName, ItemPrice
from Item i, Sale s
where s.ItemId=i.ItemId
	and BillData <= current_date;

create view sales as
select BillNo, BillData, s.CustId, s.ItemId, ItemPrice, QtySold, (QtySold*ItemPrice) as Amount 
from Sale s, Customer c, Item i 
where  c.CustId=s.CustId
	and i.ItemId=s.ItemId;

select * from sales;

insert into Sale 
	values (12,current_date-1,5,1,10),
	(13,current_date-8,5,1,10);

create view weeklysales as
select BillNo, BillData, s.CustId, s.ItemId, ItemPrice, QtySold, (QtySold*ItemPrice) as Amount 
from Sale s, Customer c, Item i 
where  c.CustId=s.CustId 
	and i.ItemId=s.ItemId 
	and BillData >= (current_date - 7) 
	and BillData <= (current_date) 
order by BillData asc;

-- 3)
create table Party (
	pid int not null auto_increment,
	pname varchar(20),
	leader varchar(20), 
	primary key (pid)
);

create table Constituency (
	cid int not null auto_increment,
	cname varchar(20),
	primary key (cid)
);

create table Contestant (
	ctid int not null auto_increment,
	ctname varchar(20),
	ctaddr varchar(50),
	primary key (ctid)
);

create table Election (
	ctid int not null auto_increment,
	numVotes int,
	pname varchar(20),
	cname varchar(20),
	primary key (ctid),
	foreign key (pname) references Party(pname),
	foreign key (cname) references Constituency(cname)
);

insert into Party 
	values (1,'notBJP','notModi'),
	(2,'notCongress','notSonia');
insert into Constituency 
	values (1,'lucknow'),
	(2,'tn');
insert into Contestant 
	values (1,'someDude','somePlace'),
	(2,'anotherDude','someOtherPlace');
insert into Election 
	values (1,15000,'notBJP','lucknow'),
	(2,9500,'notCongress','tn');

select ctname, ctaddr
from Contestant c, Election e
where e.numVotes > 10000
	and e.ctid=c.ctid;

select count(*)
from Election
group by cname;

select e.ctid, ctname, ctaddr
from Election e, Contestant c
where numVotes=(select max(numVotes) from Election where cname=e.cname) 
	and e.ctid=c.ctid;

select ctid,pname
from Election e 
where numVotes=(select max(numVotes) from Election where cname=e.cname);

select count(*), pname 
from Election e
where numVotes=(select max(numVotes) from Election where cname=e.cname) 
group by pname ;

select ctid, cname, pname
from Election e
where numVotes=(select max(numVotes) from Election where cname=e.cname) 
	and pname='notBJP';


insert into Election 
	values (5,11000,'notBJP','ranchi');
insert into Constituency 
	values (3,'ranchi');
insert into Contestant 
	values (5,'wiininDude','wiinerPlace');


create view winnnerCount as
select count(*) as count,pname 
from Election e 
where numVotes=(select max(numVotes) from Election where cname=e.cname) 
group by pname ;

select pname 
from winnnerCount 
where count=(select max(count) from winnnerCount);

insert into Contestant
 	values (6,'notModi','notGujarat');

select pname
from Contestant c, Party p
where p.leader = c.ctname;

select ctname
from Contestant c
where ctname not in (select leader from Party);

select ctname, numVotes 
from Election e, Contestant c 
where c.ctid=e.ctid;

select max(numVotes),pname, ctname 
from Election e 
inner join Contestant c 
where e.ctid=c.ctid 
group by cname; 

update Contestant 
set ctname='notModi' 
where ctid=1;

select max(numVotes), p.leader 
from Election e, Party p, Contestant c 
where e.ctid=c.ctid 
	and c.ctname=p.leader
	group by cname;

create view Contest as 
select ctid, cname, pname
from Election ;

select * from Contest;