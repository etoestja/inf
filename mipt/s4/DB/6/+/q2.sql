use theater;

go

drop proc test1

go

create proc test1
as
begin tran
update actor set name_middle = N'N11' where id = 2
rollback tran

go
/*
drop proc proc2

go

drop table t1

go

create table t1(id int primary key identity(1,1), a varchar(500))

go

--insert into t1(a)
--SELECT 'begin transaction aa' + SUBSTRING(SUBSTRING(definition, 38, 999),0, len(definition) - 54) + 'rollback transaction aa' FROM theater.sys.sql_modules s INNER JOIN theater.sys.procedures p ON [s].[object_id] = [p].[object_id] WHERE p.name = 'test1'

go

--update theater.sys.sql_modules set definition = (select a from t1 where id = 1)

--SELECT [s].object_id, [s].definition FROM theater.sys.sql_modules s INNER JOIN theater.sys.procedures p ON [s].[object_id] = [p].[object_id] WHERE p.name = 'test1'
*/