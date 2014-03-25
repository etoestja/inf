--create database theater;
--go
use theater;
go

create table gender
(
id int primary key identity(5000,1),
description nvarchar(50) not null
);
go

create table line
(
id int primary key identity(5000,1),
description nvarchar(50) not null
);
go

create table roleType
(
id int primary key identity(5000,1),
description nvarchar(50) not null
)
go

create table author
(
id int primary key identity(5000,1),
name_first nvarchar(50) not null,
surname nvarchar(50),
name_middle nvarchar(50),
birthDate datetime,
deathDate datetime,
constraint bdate check (birthDate <= deathDate)
)

go

create table play
(
id int primary key identity(5000,1),
[name] nvarchar(50) not null,
description nvarchar(500) not null
)

go

create table actorTitle
(
id int primary key identity(5000,1),
description nvarchar(50) not null
)

go

create table actor
(
id int primary key identity(5000,1),
name_first nvarchar(50) not null,
surname nvarchar(50),
name_middle nvarchar(50),
birthDate datetime,
title int foreign key references actorTitle(id) on delete no action on update cascade,
gender int foreign key references gender(id) on delete no action on update cascade
)

go

create table actor_actorTitle
(
id int primary key identity(5000,1),
actor int foreign key references actor(id) on delete cascade on update no action,
actorTitle int foreign key references actorTitle(id) on delete no action on update cascade
)

go

create table actor_line
(
--id int primary key identity(5000,1),
actor int foreign key references actor(id) on delete cascade on update cascade,
line int foreign key references line(id) on delete cascade on update cascade,
constraint id primary key (actor, line)
)

go

create table [role]
(
id int primary key identity(5000,1),
[name] nvarchar(50) not null,
description nvarchar(500),
gender int foreign key references gender(id) on delete no action on update cascade,
line int foreign key references line(id) on delete no action on update cascade,
[type] int foreign key references roleType(id) on delete no action on update cascade
)

go

create table director
(
id int primary key identity(5000,1),
name_first nvarchar(50) not null,
surname nvarchar(50),
name_middle nvarchar(50)
)

go

create table seatType
(
id int primary key identity(5000,1),
description nvarchar(500) not null
)

create table room
(
id int primary key identity(5000,1),
[name] nvarchar(500)
)

go

create table seat
(
id int primary key identity(5000,1),
seat int not null,
row int not null,
room int foreign key references room(id) on delete no action on update cascade,
[type] int foreign key references seatType(id) on delete no action on update cascade,
constraint seatzero check (seat >= 0),
constraint rowzero check (row >= 0)
)

go

create table staging
(
id int primary key identity(5000,1),
[name] nvarchar(50) not null,
description nvarchar(500),
director int foreign key references director(id) on delete no action on update cascade
)

go

create table role_staging
(
id int primary key identity(5000,1),
[role] int foreign key references [role](id) on delete cascade on update cascade,
staging int foreign key references staging(id) on delete cascade on update cascade
)

go

create table [cast]
(
id int primary key identity(5000,1),
number int not null,
constraint numberzero check (number >= 0)
)

go

create table actor_rolestaging
(
id int primary key identity(5000,1),
actor int foreign key references actor(id),
role_staging int foreign key references role_staging(id) on delete cascade on update cascade,
beginDate datetime,
endDate datetime,
[cast] int foreign key references [cast](id) on delete set null on update cascade,
constraint checkdates check (beginDate <= endDate)
)

go

create table play_author
(
id int primary key identity(5000,1),
play int foreign key references play(id) on delete cascade,
author int foreign key references author(id) on delete cascade
)

go

create table role_play
(
id int primary key identity(5000,1),
[role] int foreign key references [role](id) on delete cascade,
play int foreign key references play(id) on delete cascade
)

go

create table play_staging
(
id int primary key identity(5000,1),
play int foreign key references play(id) on delete cascade,
staging int foreign key references staging(id) on delete cascade
)

go

/* a replaces b */
create table castReplace
(
id int primary key identity(5000,1),
a int foreign key references [cast](id) on delete cascade,
b int foreign key references [cast](id),
constraint neq check (not (a = b))
)

go

create table cast_staging
(
id int primary key identity(5000,1),
[cast] int foreign key references [cast](id) on delete cascade on update cascade,
staging int foreign key references staging(id) on delete cascade on update cascade,
)

go

create table performance
(
id int primary key identity(5000,1),
[date] datetime not null,
staging int foreign key references staging(id) on delete no action on update cascade,
cast_staging int foreign key references cast_staging(id) on delete no action on update no action,
)

go

create table actorrolestaging_performance
(
id int primary key identity(5000,1),
actorrolestaging int foreign key references actor_rolestaging(id) on delete cascade on update no action,
performance int foreign key references performance(id) on delete cascade on update no action,
)

go

create table seat_performance
(
id int primary key identity(5000,1),
seat int foreign key references seat(id),
performance int foreign key references performance(id) on delete cascade on update cascade
)

go

use master;