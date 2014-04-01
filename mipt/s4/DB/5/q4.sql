use theater;

go

IF OBJECT_ID ('view4', 'V') IS NOT NULL
DROP VIEW view4;

go

create view view4
as
select [role].[name], count(distinct performance.id) as performances, actor.name_first + ' ' + actor.surname as top_actor from [role]
left outer join role_staging on role_staging.[role] = [role].id
left outer join staging on role_staging.staging = staging.id
left outer join performance on performance.staging = staging.id
left outer join actor_rolestaging on actor_rolestaging.role_staging = role_staging.id
left outer join actor on actor.id = actor_rolestaging.actor

inner join (select a.[role] as [role], max(actor_count) as ac from
		(select [role].id as [role], count(actor.id) as actor_count from [role], staging, role_staging, actor, actor_rolestaging
			where [role].id = role_staging.[role]
			and role_staging.staging = staging.id
			and actor.id = actor_rolestaging.actor
			and actor_rolestaging.role_staging = role_staging.id
		group by [role].id, actor.id, actor.[name_first], actor.surname) as a
	group by a.[role]) b on b.[role] = [role].id
where CURRENT_TIMESTAMP <= DATEADD(year, 5, performance.date)

group by [role].id, [role].[name], actor.id, actor.name_first, actor.surname, b.ac
having count(actor.id) = b.ac

go

/*
всё представление
*/

select * from view4

go

select * from view4 where top_actor = N'Эмма Уотсон'