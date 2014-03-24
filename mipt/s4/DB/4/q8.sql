use theater;

/*
Снять всех актеров с постановок по Звездным Войнам (play.id=17)
*/

--select * from play

select * from actorrolestaging_performance, performance, staging, play_staging, play where
actorrolestaging_performance.performance = performance.id
and performance.staging = staging.id
and staging.id = play_staging.staging
and play_staging.play = play.id
and play.id = 17

go

select play.id, actor_rolestaging.id, performance.id from actor_rolestaging, play_staging, role_staging, staging, play, performance
where
performance.staging = staging.id and
actor_rolestaging.role_staging = role_staging.id
and role_staging.staging = staging.id
and play_staging.staging = staging.id
and play_staging.play = play.id
and play.id = 17
and role_staging.id = actor_rolestaging.role_staging

go

delete from actor_rolestaging
where id in
(
select actor_rolestaging.id from actor_rolestaging, play_staging, role_staging, staging, play, performance
where
performance.staging = staging.id and
actor_rolestaging.role_staging = role_staging.id
and role_staging.staging = staging.id
and play_staging.staging = staging.id
and play_staging.play = play.id
and play.id = 17
and role_staging.id = actor_rolestaging.role_staging
)