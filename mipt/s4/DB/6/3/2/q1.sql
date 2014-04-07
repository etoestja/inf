use theater

--possible

set transaction isolation level repeatable read

delete from actor where name_first = 'N1'
delete from actor where name_first = 'N3'

begin transaction

insert into actor(name_first, name_middle, surname, birthDate, gender) values ( N'N1', NULL, N'N2', '1970-05-27', 1);
insert into actor(name_first, name_middle, surname, birthDate, gender) values ( N'N3', NULL, N'N4', '1970-05-27', 1);

commit