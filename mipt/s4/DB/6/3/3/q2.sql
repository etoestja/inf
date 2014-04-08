use theater;

set transaction isolation level repeatable read;

begin transaction

select middle_name from actor where id = 3

update actor set middle_name = N'd1' where id = 2

commit