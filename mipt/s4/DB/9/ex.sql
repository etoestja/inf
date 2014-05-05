drop database temporaryDB;

go

create database temporaryDB;

go


use temporaryDB;

go

--drop table t1;

go

create table t1 (id int primary key identity(1,1), data datetime default CURRENT_TIMESTAMP)

go

IF OBJECT_ID ('tr1', 'TR') IS NOT NULL
DROP TRIGGER tr1;

go


go

create trigger tr1 on t1
for delete
as

select * from inserted

delete from t1
--insert into t1 values(CURRENT_TIMESTAMP)

--SET IDENTITY_INSERT t1 ON
--insert into t1(id, data) values(2, CURRENT_TIMESTAMP)
--insert into t1(data) values(CURRENT_TIMESTAMP)
--SET IDENTITY_INSERT t1 OFF

select * from inserted

go

insert into t1 values(NULL)
insert into t1 values(NULL)

delete from t1

go

use master;