use theater;

--impossible

set transaction isolation level read committed;

begin transaction

update actor set name_middle = N'NO' where id = 2

rollback