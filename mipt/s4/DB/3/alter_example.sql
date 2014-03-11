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

alter table cast_staging
drop constraint FK__cast_stagi__cast__4FD1D5C8

go

alter table actor_rolestaging
drop constraint FK__actor_role__cast__3BCADD1B

go

alter table [cast]
drop constraint PK__cast__361203C5

alter table [cast]
alter column id int;

alter table [cast]
add constraint PK__cast__361203C5 primary key (id);

go

alter table castReplace
alter column a int

alter table castReplace
alter column b int

alter table actor_rolestaging
alter column [cast] int

alter table cast_staging
alter column [cast] int

go

alter table castReplace
add constraint FK__castReplace__a__4B0D20AB foreign key (a) references [cast](id) on delete cascade;

alter table castReplace
add constraint FK__castReplace__b__4C0144E4 foreign key (b) references [cast](id)

alter table castReplace
add constraint neq check (not (a = b))

go

alter table cast_staging
add constraint FK__cast_stagi__cast__4FD1D5C8 foreign key ([cast]) references [cast](id) on delete cascade on update cascade;

go

alter table actor_rolestaging
add constraint FK__actor_role__cast__3BCADD1B foreign key ([cast]) references [cast](id) on delete cascade on update cascade;