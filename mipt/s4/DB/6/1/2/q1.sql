use theater;

set transaction isolation level read uncommitted;

begin transaction

update actor set name_middle = N'NO' where id = 2

rollback