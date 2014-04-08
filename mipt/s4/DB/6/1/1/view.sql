use theater;

update actor set name_middle = N'Петров' where id = 2
update actor set name_middle = N'длодло' where id = 3

select * from actor where id IN (2,3)