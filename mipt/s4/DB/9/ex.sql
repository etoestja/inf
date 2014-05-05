--create database temporaryDB;
use temporaryDB;

go

drop table t1;

go

create table t1 (id int primary key identity(1,1), data int)

go

IF OBJECT_ID ('tr1', 'TR') IS NOT NULL
DROP TRIGGER tr1;

go

create trigger tr1 on t1
after update
as
select * from inserted
select * from deleted
insert into t1 values(10)
select * from inserted
select * from deleted

go

insert into t1 values(1)
insert into t1 values(2)
update t1 set data = 5
select * from t1