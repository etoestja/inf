use theater;

--possible

set transaction isolation level read uncommitted;

--update actor set name_middle = N'Петров' where id = 2

drop table actor1

create table actor1(name_middle nvarchar(50));

begin transaction

insert into actor1(name_middle)
select name_middle from actor where id = 2

select * from actor1

select * from actor
where id = 2

--update actor1 set name_middle = N'Петров'

update actor set name_middle = (select top 1 name_middle from actor1)
where id = 2

commit;