use theater;
select top 1 actor.id, count(actor.id) as a from [role], role_staging, actor_rolestaging, actor, performance, staging
where
[role].id = role_staging.[role] and
role_staging.id = actor_rolestaging.role_staging and
actor_rolestaging.actor = actor.id and
performance.staging = staging.id and
role_staging.staging = staging.id and
[role].[name] = N'техничка-шпионка'
group by actor.id