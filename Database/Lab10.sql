
create database Lab10;
use Lab10;

create table Country(
	name varchar(10),
	continent varchar(10),
	area numeric(7, 2),
	population numeric(10),
	gdp numeric(2, 1),
	primary key(name)
);

insert into Country 
values ("India", "Asia", 40000, 10000, 6.7),
	("China", "Asia", 70000, 12000, 8.2),
	("USA", "North America", 10000, 50000, 8.9),
	("Romania", "Europe", 7000, 2300, 4),
	("Pakishtan", "Asia", 5000, 1220, 0.1),
	("Australia", "Europe", 10000, 4000, 4.5);

select c.name 
from Country as c
where c.population > (select population from Country where name = "Romania");


select c.name 
from Country as c
where c.gdp > all(select gdp from Country where continent = 'Europe');

select continent, name, area
from Country as c1
where c1.population = (select max(population) from Country as c2 where c2.continent=c1.continent);