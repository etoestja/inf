use theater

--impossible

set transaction isolation level serializable

begin transaction

select * from actor
select * from actor

commit