use theater;

go

IF OBJECT_ID ('view0', 'V') IS NOT NULL
DROP VIEW view0 ;

go
create view view0
as
select play.name as play, author.name_first, author.surname from play
join play_author on (play.id = play_author.play)
join author on (author.id = play_author.author)

go
select * from view0 order by play

go

update view0 set name_first = N'f' where play=N'Враги'