use theater;

alter table [cast]
drop constraint numberzero;

go

alter table [cast]
add constraint numberzero check (number > 0);