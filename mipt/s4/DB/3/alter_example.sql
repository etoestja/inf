use theater;

/*

create table [cast]
(
id int primary key identity(5000,1),
number int not null,
constraint numberzero check (number >= 0)
)

*/

alter table castReplace
drop constraint neq;

go

alter table castReplace
drop constraint FK__castReplace__a__4B0D20AB;

go

alter table castReplace
drop constraint FK__castReplace__b__4C0144E4;

go

alter table castReplace
add constraint FK__castReplace__a__4B0D20AB foreign key (a) references [cast](id);

alter table castReplace
add constraint FK__castReplace__b__4C0144E4 foreign key (b) references [cast](id)

/*alter table [cast]
alter column id bigint;*/
/*
alter table [cast]
alter column id bigint;*/