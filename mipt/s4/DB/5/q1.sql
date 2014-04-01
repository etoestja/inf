use theater;

go

IF OBJECT_ID ('view1', 'V') IS NOT NULL
DROP VIEW view1;

go

/*
неизменяемое (distinct)
*/

create view view1
as
select distinct play.[name] as play, director.name_first + ' ' + director.surname as director, actor.name_first + ' ' + actor.surname as actor_cast1 from play
left outer join play_staging on play_staging.staging = play.id
left outer join staging on staging.id = play_staging.staging
--left outer join performance on performance.staging = staging.id
left outer join director on director.id = staging.director
left outer join role_staging on role_staging.staging = staging.id
left outer join actor_rolestaging on actor_rolestaging.role_staging = role_staging.id
left outer join actor on actor.id = actor_rolestaging.actor
left outer join [cast] on actor_rolestaging.[cast] = [cast].id
where [cast].number = 1

go

/*
всё представление
*/
select * from view1

go

/*
пьеса Враги, режиссеры постановок пьесы, актеры первого состава в постановках
*/

select * from view1 where play = N'Враги'

go

--update view1 set play = N'Тест' where director = N'Враги'

/*
актеры первого состава в пьесе На дне
*/

select actor_cast1 from view1 where play = N'На дне'