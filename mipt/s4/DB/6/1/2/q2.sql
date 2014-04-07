use theater;

set transaction isolation level read uncommitted;

begin transaction

select * from actor where id = 2;

select * from actor where id = 2;

commit;