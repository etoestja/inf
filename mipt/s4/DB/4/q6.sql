use theater;

/*
количество исполнений роли актерами-мужчинами и актерами-женщинами
*/
--, count(actor.id), count(case when gender.[description] = N'М' then 1 else 0 end) as M, count(case when gender.[description] = N'Ж' then 1 else 0 end) as F
select [role].[name], sum(case when gender.[description] = N'М' then 1 else 0 end) as M,
sum(case when gender.[description] = N'Ж' then 1 else 0 end) as F
from [role], actor, role_staging, gender, actor_rolestaging
where actor.gender = gender.id and
actor.id = actor_rolestaging.actor and
actor_rolestaging.role_staging = role_staging.id and
role_staging.[role] = [role].id
--and role.id=9
group by role.id, role.[name]