create table Course (
	CourseNum int,
	CourseName varchar(10),
	primary key(CourseNum)
);

create table OffSiteSection(
	Location varchar(10)
);

create table Student (
	StudentNum int,
	StudentName varchar(10),
	GPA numeric(2,1),
	primary key(StudentName)
);

create table professor (
	ProfNum int,
	ProfName varchar(10),
	primary key(profnum)
);

create table Section (
	SectionNum int,
	Term int,
	ProfNum int references Professor(ProfNum),
	StudentNum int references Student(StudentNum),
	primary key(SectionNum, ProfNum, StudentNum)
);

create table TaughtBy (
	ProfNum int references Professor(ProfNum),
	SectionNum int references Section(SectionNum),
	primary key(profnum)
);

create table Enrolledin (
	sectionnum int references section.sectionnum,
	mark int,
	studentnum int references student.student_num,
	primary key(student_num)
);

create table SectionOf (
	sectionnum int references section.sectionnum,
	coursenum int references course.course_num,
	primary key(coursenum)
);