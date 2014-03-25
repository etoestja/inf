use theater;

go

IF OBJECT_ID ('view3', 'V') IS NOT NULL
DROP VIEW view3;

go

create view view3
as
select play.name, count(distinct role.id) as roles, count(distinct performance.id) as performances, max(performance.date) as latestPerformanceDate from play
left outer join role_play on role_play.play = play.id
left outer join [role] on [role].id = role_play.role
left outer join play_staging on play_staging.play = play.id
left outer join staging on staging.id = play_staging.staging
left outer join performance on performance.staging = staging.id
group by play.name

go

/*

Все пьесы, по которым не было спектаклей за последний год

*/

select * from view3 where latestPerformanceDate <= dateadd(year, -1, CURRENT_TIMESTAMP)