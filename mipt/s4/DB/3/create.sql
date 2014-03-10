create database theater;
go
use theater;
go

create table gender
(
id int primary key identity(1,1),
description nvarchar(50) not null
);
go

create table line
(
id int primary key identity(1,1),
description nvarchar(50) not null
);
go

create table roleType
(
id int primary key identity(1,1),
description nvarchar(50) not null
)
go

create table author
(
id int primary key identity(1,1),
[name] nvarchar(50) not null,
birthDate datetime,
deathDate datetime
)

go

create table play
(
id int primary key identity(1,1),
[name] nvarchar(50) not null,
description nvarchar(500) not null
)

go

create table actorTitle
(
id int primary key identity(1,1),
description nvarchar(50) not null
)

go

create table actor
(
id int primary key identity(1,1),
[name] nvarchar(50) not null,
birthDate datetime,
title int foreign key references actorTitle(id),
gender int foreign key references gender(id)
)

go

create table actor_line
(
id int primary key identity(1,1),
actor_id int foreign key references actor(id),
line_id int foreign key references line(id)
)

go

create table [role]
(
id int primary key identity(1,1),
[name] nvarchar(50) not null,
description nvarchar(500),
gender int foreign key references gender(id),
line int foreign key references line(id),
[type] int foreign key references roleType(id)
)

go

create table director
(
id int primary key identity(1,1),
[name] nvarchar(50) not null
)

go

create table seatType
(
id int primary key identity(1,1),
description nvarchar(500) not null
)

create table room
(
id int primary key identity(1,1),
[name] nvarchar(500)
)

go

create table seat
(
id int primary key identity(1,1),
seat int not null,
row int not null,
room int foreign key references room(id),
[type] int foreign key references seatType(id)
)

go

create table staging
(
id int primary key identity(1,1),
director int foreign key references director(id)
)

go

create table role_staging
(
id int primary key identity(1,1),
[role] int foreign key references [role](id),
staging int foreign key references staging(id)
)

go

create table [cast]
(
id int primary key identity(1,1),
number int not null
)

go

create table actor_rolestaging
(
id int primary key identity(1,1),
actor int foreign key references actor(id),
role_staging int foreign key references role_staging(id),
beginDate datetime not null,
endDate datetime not null,
[cast] int foreign key references [cast](id)
)

go

create table play_author
(
id int primary key identity(1,1),
play int foreign key references play(id),
author int foreign key references author(id)
)

go

create table role_play
(
id int primary key identity(1,1),
[role] int foreign key references [role](id),
play int foreign key references play(id)
)

go

create table play_staging
(
id int primary key identity(1,1),
play int foreign key references play(id),
staging int foreign key references staging(id)
)

go

/* a replaces b */
create table castReplace
(
id int primary key identity(1,1),
a int foreign key references [cast](id),
b int foreign key references [cast](id)
)

go

create table cast_staging
(
id int primary key identity(1,1),
[cast] int foreign key references [cast](id),
staging int foreign key references staging(id),
)

go

create table performance
(
id int primary key identity(1,1),
[date] datetime not null,
staging int foreign key references staging(id),
cast_staging int foreign key references cast_staging(id),
)

go

create table actorrolestaging_performance
(
id int primary key identity(1,1),
actorrolestaging int foreign key references actor_rolestaging(id),
performance int foreign key references performance(id),
)

go

create table seat_performance
(
id int primary key identity(1,1),
seat int foreign key references seat(id),
performance int foreign key references performance(id)
)

go

use master;