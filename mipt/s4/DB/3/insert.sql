use theater;

go

SET IDENTITY_INSERT gender ON

insert into gender (id, description) values (1, N'М');
insert into gender (id, description) values (2, N'Ж');

SET IDENTITY_INSERT gender OFF

go

SET IDENTITY_INSERT line ON

insert into line (id, description) values (1,  N'герой-любовник');
insert into line (id, description) values (2,  N'злодей');
insert into line (id, description) values (3,  N'герой');
insert into line (id, description) values (4,  N'героиня'); -- ?
insert into line (id, description) values (5,  N'молодой любовник');
insert into line (id, description) values (6,  N'король');
insert into line (id, description) values (7,  N'тиран');
insert into line (id, description) values (8,  N'отец');
insert into line (id, description) values (9,  N'наперсник');
insert into line (id, description) values (10, N'наперсница');
insert into line (id, description) values (11, N'лакей');
insert into line (id, description) values (12, N'наперсница');
insert into line (id, description) values (13, N'субретка');
insert into line (id, description) values (14, N'инженю');
insert into line (id, description) values (15, N'резонер');
insert into line (id, description) values (16, N'петиметр');
insert into line (id, description) values (17, N'простак');

SET IDENTITY_INSERT line OFF

go

SET IDENTITY_INSERT roleType ON

insert into roleType (id, description) values (1,  N'главная');
insert into roleType (id, description) values (2,  N'вторая');
insert into roleType (id, description) values (3,  N'эпизод');
insert into roleType (id, description) values (4,  N'статист');

SET IDENTITY_INSERT roleType OFF

go

SET IDENTITY_INSERT [role] ON

insert into [role](id, [name], gender, line, [type]) values (1,  N'техничка-шпионка', 2, 17, 4);
insert into [role](id, [name], gender, line, [type]) values (2,  N'Гамлет', 1, 3, 1);

SET IDENTITY_INSERT [role] OFF

go

SET IDENTITY_INSERT author ON

insert into author(id, [name], birthDate, deathDate) values (1, N'Шекспир', 2013-01-01, 2014-01-01)

SET IDENTITY_INSERT author OFF

go

SET IDENTITY_INSERT play ON

insert into play(id, [name], description) values (1,  N'Плохая пьеса', N'дескрипшен')

SET IDENTITY_INSERT play OFF

go

insert into play_author(play, author) values (1, 1)

go

insert into role_play(role, play) values (1, 1)

go

use master