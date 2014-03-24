use theater;

/*

Удалить актера (нельзя, если он где-то играет)

*/
go

select * from actor, actor_rolestaging
where actor.id = actor_rolestaging.actor
and actor.id = 1

go

delete from actor where id = 1;

go

select * from actor, actor_rolestaging
where actor.id = actor_rolestaging.actor
and actor.id = 1

go

select * from actor where id = 22

go

delete from actor where id = 22

go

select * from actor where id = 22