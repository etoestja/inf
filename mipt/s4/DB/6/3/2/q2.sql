use theater

--possible

set transaction isolation level repeatable read

begin transaction

select * from actor
select * from actor

commit