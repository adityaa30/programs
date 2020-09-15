drop database Lab6;
create database Lab6;
use Lab6;

create table Product (
	BarCode int not null,
	PName varchar(40),
	Price int,
	QuantityInStock int,
	primary key (BarCode)
);

create table Sale (
	SaleId int not null,
	DeliveryAddress varchar(40),
	CreditCard int,
	primary key(SaleID)
);

create table SaleItem (
	SaleId int not null,
	BarCode int not null,
	Quantity int,
	primary key (BarCode, SaleId),
	foreign key (BarCode) references Product(BarCode)
);

create trigger updateAvailableQuantity
after insert
on SaleItem
for each row
update Product set Product.QuantityInStock = Product.QuantityInStock - new.Quantity where new.BarCode = Product.BarCode;

-- Insert data
insert into Product
values (1, "SSD", 5000, 20),
	(2, "HDD", 2000, 10);

insert into SaleItem
values (1, 1, 2);