create table Activites (
	ActivityID int not null,
	ActivityName varchar(40),
	primary key (ActivityID)
);

create table Performers (
	PerformerID  int not null,
	PerformerName varchar(40),
	Street varchar(40),
	City varchar(40),
	State varchar(40),
	Zip int(6),
	ActivityID int,
	primary key (PerformerID),
	foreign key (ActivityID) references Activites(ActivityID)	
);

create table Arenas (
	ArenaID int not null,
	ArenaName varchar(40),
	City varchar(40),
	ArenaCapacity varchar(40),
	primary key (ArenaID)
);

create table Concerts (
	PerformerID int,
	ArenaID int,
	ConcertDate datetime,
	TicketPrice int,
	primary key (PerformerID, ArenaID),
	foreign key (PerformerID) references Performers(PerformerID),	
	foreign key (ArenaID) references Arenas(ArenaID)	
);


insert into Activites
values (1, "Dancing"),
	(2, "Swimming"),
	(3, "Athletics");

insert into Performers
values (1, "Ashutosh", "Thuvakudi", "Trichy", "Tamil Nadu", 620015, 1),
	(2, "Abhsishek", "Thuvakudi", "Trichy", "Tamil Nadu", 620015, 1),
	(3, "Dhruv", "Thuvakudi", "Trichy", "Tamil Nadu", 620015, 2);



delimiter //
CREATE TRIGGER deletePerformer 
BEFORE DELETE 
ON Performers 
FOR EACH ROW
BEGIN 
    IF (1 = (SELECT COUNT(PerformerID)
                    FROM Performers
                    WHERE Performers.ActivityID = old.ActivityId
                   )
        ) THEN
        CALL RAISE_APPLICATION_ERROR('Deletion is Not Allowed!');
    END IF;
END;
//
