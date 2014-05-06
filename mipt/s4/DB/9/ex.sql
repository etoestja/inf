drop database temporaryDB;

go

create database temporaryDB;

go


use temporaryDB;

go

--drop table t1;

go

create table t1 (id int primary key identity(1,1), data int)

go

IF OBJECT_ID ('tr1', 'TR') IS NOT NULL
DROP TRIGGER tr1;

go


go

create trigger tr1 on t1
for insert
as

select * from inserted
select * from deleted

go

insert into t1 values(1)