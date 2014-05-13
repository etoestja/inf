use theater;

-- нет добавленного названия
select * from staging;

go

-- актер больше не играет в спектакле
delete from actorrolestaging_performance where performance = 2

--update actorrolestaging_performance set performance = 2

go

-- условие не выполняется, поэтому суффикс удаляется
select * from staging

go

insert into actorrolestaging_performance(actorrolestaging, performance) values (12, 2)


-- суффикс снова есть
select * from staging

go

select * from staging where id in (101, 102)

go

-- ex1. two stagings, both
-- 101: female role 

create table tta (a int, b int)
insert into tta values(101,101)
insert into tta values(10

delete from actorrolestaging_performance where actorrolestaging in (101,102)

insert into actorrolestaging_performance select 101, 101 union select 102,1