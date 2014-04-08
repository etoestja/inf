use theater;

--possible

set transaction isolation level repeatable read;

begin transaction

update actor set name_middle = N'Иванов' where id = 2

commit