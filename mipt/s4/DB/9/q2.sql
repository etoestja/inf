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

insert into actorrolestaging_performance(actorrolestaging, performance) values(12, 2)


-- суффикс снова есть
select * from staging