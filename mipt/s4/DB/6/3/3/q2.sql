use theater;

set transaction isolation level repeatable read;

begin transaction

select name_middle from actor where id = 3

update actor set name_middle = N'd11' where id = 2

commit