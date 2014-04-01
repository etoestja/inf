use theater;

go

IF OBJECT_ID ('t_view', 'V') IS NOT NULL
DROP VIEW t_view;

go

create view t_view
as
(
select * from actor where gender = 1
)
--with check option

go
select * from t_view

go

update t_view set gender = 2