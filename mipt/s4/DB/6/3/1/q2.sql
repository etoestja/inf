use theater

--impossible

set transaction isolation level repeatable read

update actor set name_middle = N'v1' where id = 2

begin transaction

update actor set name_middle = N'v2' where id = 2

commit