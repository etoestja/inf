use theater;

go

IF OBJECT_ID ('performance_genders', 'V') IS NOT NULL
DROP VIEW performance_genders;

go

-- Распределение актеров по ролям в спектаклях performance_id: количество женских ролей fR в спектакле,
-- fRm - количество женских ролей, исполняемых мужчинами
-- p - спектаклю нужен суффикс <=> fR > 0 && fR = fRm

create view performance_genders
as
(select performance_id, fR, fRm, (case when (fR > 0 and fR = fRm) then 1 else 0 end) as p from
(
	select p.id as performance_id, sum(case when (rg.description = N'Ж') then 1 else 0 end) as fR,
	sum (case when (rg.description = N'Ж' and ag.description = N'М') then 1 else 0 end) as fRm
	from actorrolestaging_performance arsp
	join actor_rolestaging ars on ars.id = arsp.actorrolestaging
	join performance p on p.id = arsp.performance
	join role_staging rs on rs.id = ars.role_staging
	join [role] r on r.id = rs.[role]
	join gender rg on rg.id = r.gender
	join actor a on a.id = ars.actor
	join gender ag on a.gender = ag.id
	group by p.id
) t1
)

go

IF OBJECT_ID ('staging_suffix', 'V') IS NOT NULL
DROP VIEW staging_suffix;

go

-- Нужен ли суффикс данной постановке staging_id?
-- есть хотя бы одному спектаклю по данной постановке нужен суффикс, то он нужен постановке

create view staging_suffix
as
(select staging.id as staging_id, (case when max(p) is NULL then 0 else max(p) end) as suffixPresent from staging
left outer join performance on performance.staging = staging.id
left outer join performance_genders pg on pg.performance_id = performance.id
group by staging.id)

go

IF OBJECT_ID ('shakespeare', 'TR') IS NOT NULL
DROP TRIGGER shakespeare;

go

create trigger shakespeare on actorrolestaging_performance
after delete, insert, update
as
declare @suffix nvarchar(1000);
select @suffix = N' (в традициях времен Шекспира)'
--select * from t5 where substring(t, len(t) - len(@suffix) + 1, len(@suffix)) = @suffix

-- переменная типа table...
declare @shakespeareTmp table (id int)

-- ...в которой лежат id постановок, для которых существует спектакль, для которого назначение актера на роль было изменено
insert into @shakespeareTmp
select distinct s.id from
(select * from inserted
union
select * from deleted)
arsp
join performance p on p.id = arsp.performance
join staging s on s.id = p.staging

-- удаляем все суффиксы
-- для постановок, затронутых запросом
update staging
set name = substring(name, 1, len(name) - len(@suffix))
where
substring(name, len(name) - len(@suffix) + 1, len(@suffix)) = @suffix
and id in (select * from @shakespeareTmp)

-- добавляем тем постановкам, для которых нужен суффикс, и которые
-- затронуты запросом
update staging
set staging.name = staging.name + @suffix
from staging inner join staging_suffix ss on ss.staging_id = staging.id
where ss.suffixPresent = 1
and id in (select * from @shakespeareTmp)

go