use theater;

--possible

set transaction isolation level read uncommitted;

drop table actor1

create table actor1(name_middle nvarchar(50));

begin transaction

insert into actor1(name_middle)
select name_middle from actor where id = 2

go

select * from actor1

go

select * from actor
where id = 2

--go

--update actor1 set name_middle = N'Петров'

go

update actor set name_middle = (select top 1 name_middle from actor1)
where id = 2

commit;