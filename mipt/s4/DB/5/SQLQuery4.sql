--create database tdb;

use tdb;

go

drop table t2

go
drop table t1;
go
create table t1(v1 int primary key);

go

drop table t2;
create table t2(v2 int foreign key references t1(v1));

go

IF OBJECT_ID ('v1', 'V') IS NOT NULL
DROP VIEW v1;

go

create view v1 as
(
select * from t1, t2
--where t1.v1 = t2.v2
)

go

insert into v1 (v1) values(1)
insert into v1 (v2) values(1)

go

select * from v1

/*
instead of, insert: можно добавить значения недостающим столбцам
*/