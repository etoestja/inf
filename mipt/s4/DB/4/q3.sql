use theater;

select distinct play.[name] from play, play_staging, staging, role_staging, actor_rolestaging, actor, gender, role
where
play.id = play_staging.play and
play_staging.staging = staging.id and
role_staging.staging = staging.id and
actor_rolestaging.role_staging = role_staging.id and
actor_rolestaging.actor = actor.id and
[role].id = role_staging.[role] and
actor.gender = gender.id
group by [role].id, [play].id, [play].name
having count(distinct gender.id) = 2