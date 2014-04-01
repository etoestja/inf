use theater;

select * from view1

go

/*
не получится
*/

update view1 set play = N'sf1' where director = N'Стивен Моффат'