use theater;

--impossible

set transaction isolation level read committed;

begin transaction

select * from actor where id = 2;

select * from actor where id = 2;

commit;