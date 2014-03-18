use theater;
--, count(staging.id) as N
select actor.name_first, actor.name_middle, actor.surname from actor, actor_rolestaging, role_staging, staging
where
actor.id = actor_rolestaging.actor and
actor_rolestaging.role_staging = role_staging.id and
role_staging.staging = staging.id and
actor_rolestaging.beginDate <= CURRENT_TIMESTAMP and
actor_rolestaging.endDate >= CURRENT_TIMESTAMP
group by actor.id, actor.name_first, actor.name_middle, actor.surname
having count(staging.id) > 3