-- 1) Creating tables
create table Books (
     bookno int,
     title varchar(100),
     publication varchar(25),
     author varchar(25),
     price  float,
     quality int,
     edition int,
     primary key (bookno)
);

-- 2)
insert into Books
values (1,'Automate The Boring Stuff with Python','Aditya Kumar','Automate', 900.4, 3, 1),
	(2,'Database System','NCERT','Adarsh Patel', 500.0, 4, 2),
	(3,'Ferozan','Amazon','Omkar Sardesai', 1000, 7, 1),
	(4,'Concepts of C++','Netflix','Aditya Kumar', 700, 3, 5),
	(5,'Concepts of Python','TATA','Omkar Sardesai', 1200, 1, 5),
     (6,'History & Civics','TATA','Balaguruswamy', 1200, 2, 7),
     (7,'Database Concepts & Management','Nike','Ashutosh Singh', 1500, 4, 3);

-- 3)
SELECT TITLE, AUTHOR FROM Books;

-- 4)
SELECT AUTHOR FROM Books
WHERE TITLE = 'Database System';

-- 5)
SELECT AUTHOR FROM Books;

-- 6)
select *
from Books as B
where B.price > 800;

-- 7)

SELECT * FROM Books
WHERE AUTHOR = 'balaguruswamy' AND PUBLICATION = 'TATA' ;

-- 8)
SELECT * FROM Books
WHERE TITLE LIKE '%database concepts%';


