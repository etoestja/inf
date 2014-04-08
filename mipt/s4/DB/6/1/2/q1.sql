use theater;

--possible

set transaction isolation level serializable;

begin transaction

update actor set name_middle = N'N1O' where id = 2

rollback