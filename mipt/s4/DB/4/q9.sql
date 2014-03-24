use theater;

/*
Обновить имя автора и дату рождения
*/

select * from author

go

update author set name_first=N'Тест' where id = 4

go

--error (constraint)
update author set birthDate = '1994-01-01', deathDate = '1993-01-02' where id = 5

go

--no error
update author set birthDate = '1994-01-01', deathDate = '1995-01-02' where id = 5

go

select * from author