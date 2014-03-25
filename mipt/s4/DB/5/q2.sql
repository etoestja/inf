use theater;

go

IF OBJECT_ID ('view2', 'V') IS NOT NULL
DROP VIEW view2;

go
--ine.description, count(actor.id)
--line.description as line, actor.name_first + ' ' + actor.surname as actor, staging.id as staging, [role].name as role
create view view2
as
select line.description as line,
count(actor.id) as actors,
case when count(actor.id) > 0 then
  count(distinct (case when staging.id is not null then staging.id end)) * 100 / count(actor.id)
else 0 end as actorsPercentStaging,
count(distinct
(
  case when not ([role].line = actor_line.line) then actor_rolestaging.id end
)) as otherLineNumber
from line
left outer join actor_line on actor_line.line = line.id
left outer join actor on actor.id = actor_line.actor
left outer join actor_rolestaging on actor_rolestaging.actor = actor.id
left outer join role_staging on role_staging.id = actor_rolestaging.role_staging
left outer join [role] on [role].id = role_staging.role
left outer join staging on staging.id = role_staging.staging
group by line.description
--group by line.id, line.description

go

/*

выбрать амплуа, для которых количество исполнений актером роли другого амплуа ненулевое,
и более 50% актеров задействованы в постановках

*/

select distinct line from view2 where otherLineNumber >= 1 and actorsPercentStaging > 50