use theater;
select top 1 actor.name_first + ' ' + actor.surname as Name from [role], role_staging, actor_rolestaging, actor, performance, staging, gender
where
[role].id = role_staging.[role] and
role_staging.id = actor_rolestaging.role_staging and
actor_rolestaging.actor = actor.id and
performance.staging = staging.id and
role_staging.staging = staging.id and
[role].[name] = N'техничка-шпионка' and
actor.gender = gender.id and
gender.[description] = N'Ж'
group by actor.id, actor.name_first, actor.name_middle, actor.surname
order by count(actor.id) desc