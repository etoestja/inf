use theater;

--- actor.id=6

/*

Заменяем на любого актера, который играл такую же роль.

*/

--select * from actor where id=6

--select * from actor_rolestaging where actor_rolestaging.actor = 6

go

--select * from actor_rolestaging where actor_rolestaging.actor = 6

go

select actor_rolestaging.actor, [role].id as role_id, actor_rolestaging.role_staging as role_staging_id from actor_rolestaging, role_staging, [role]
where
actor_rolestaging.role_staging = role_staging.id
and actor_rolestaging.actor = 6
and role_staging.[role] = [role].id

go

select * from actor_rolestaging where actor_rolestaging.role_staging in (3, 5)

go

insert into actor_rolestaging (actor, role_staging, beginDate)
select max(actor.id) as actor, role_staging.id as role_staging, CURRENT_TIMESTAMP from actor, actor_rolestaging, role_staging, [role]
where
actor.id = actor_rolestaging.actor
and actor_rolestaging.role_staging = role_staging.id
and role_staging.[role] = [role].id
and role_staging.id in
(
 select role_staging.id from actor, actor_rolestaging, role_staging, [role]
 where
 actor.id = actor_rolestaging.actor
 and actor_rolestaging.role_staging = role_staging.id
 and actor_rolestaging.actor = 6
 and role_staging.[role] = [role].id
 and CURRENT_TIMESTAMP > actor_rolestaging.beginDate
 and CURRENT_TIMESTAMP < actor_rolestaging.endDate
)
and not (actor.id = 6)
and actor_rolestaging.endDate < CURRENT_TIMESTAMP
group by role_staging.id

go

update actor_rolestaging set endDate = CURRENT_TIMESTAMP where actor_rolestaging.actor = 6

go

select * from actor_rolestaging where actor_rolestaging.role_staging in (3, 5)

/*
в спектакле не играет другую роль
случайный, если нет
*/