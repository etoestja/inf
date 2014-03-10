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

create table role
(
id int primary key identity(1,1),
[name] nvarchar(50) not null,
description nvarchar(500),
gender int foreign key references gender(id),
line int foreign key references line(id),
[type] int foreign key references roleType(id)
)

go

use master;