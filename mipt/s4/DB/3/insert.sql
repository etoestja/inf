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
insert into [role](id, [name], gender, line, [type]) values (3,  N'Горацио', 1, 3, 1);

SET IDENTITY_INSERT [role] OFF

go

SET IDENTITY_INSERT author ON

insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (1, N'Михаил', N'Афанасьевич', N'Булгаков', 1891-05-03, 1940-03-10);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (2, N'Уильям', NULL, N'Шекспир', 1564-04-26, 1616-04-23);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (3, N'Николай', N'Васильевич', N'Гоголь', 1809-03-20, 1852-02-21);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (4, N'Максим', NULL, N'Горький', 1868-03-16, 1936-06-18);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (5, N'Антон', N'Павлович', N'Чехов', 1860-01-17, 1904-07-02);



SET IDENTITY_INSERT author OFF

go

SET IDENTITY_INSERT play ON

insert into play(id, [name], description) values (1,  N'Иван Васильевич', N'Создана в 1934—1936 годах на основе пьесы «Блаженство». При жизни автора не ставилась и не публиковалась (впервые опубликована в 1965 году). Послужила основой фильма «Иван Васильевич меняет профессию».')
insert into play(id, [name], description) values (2,  N'Адам и Ева', N'«Адам и Ева» — пьеса Михаила Булгакова, в которой описан техногенный конец света в результате газовой войны. Пьесу не смогли опубликовать или поставить при жизни Булгакова и впервые она вышла в 1971 году, в Париже. В СССР её выпустили в октябре 1987 года.')
insert into play(id, [name], description) values (3,  N'Враги', N'Пьеса «Враги» была представлена читателям в 1906 году в сборнике товарищества «Знание» и была признана первым произведением, написанным в жанре социалистического реализма. В этот период Горький активно сотрудничал с различными революционными организациями, что и послужило толчком для написания данного произведения.')
insert into play(id, [name], description) values (4,  N'Егор Булычов и другие', N'Пьеса Максима Горького. Подзаголовок: Сцены.')
insert into play(id, [name], description) values (5,  N'На дне', N'Пьеса Максима Горького, написанная в конце 1901 — начале 1902 года. Первоначальные названия — «Без солнца», «Ночлежка», «Дно», «На дне жизни»[1].')
insert into play(id, [name], description) values (6,  N'Три сестры', N'Пьеса в четырёх действиях А. П. Чехова, написанная в 1900 году. Впервые была опубликована в журнале «Русская мысль», № 2 за 1901 год; с изменениями и поправками вышла отдельным изданием в том же году в издательстве А. Ф. Маркса[1].')
insert into play(id, [name], description) values (7,  N'Гамлет', N'трагедия Уильяма Шекспира в пяти актах, одна ')


SET IDENTITY_INSERT play OFF

go

insert into play_author(play, author) values (1, 1);
insert into play_author(play, author) values (2, 1);
insert into play_author(play, author) values (3, 4);
insert into play_author(play, author) values (4, 4);
insert into play_author(play, author) values (5, 4);
insert into play_author(play, author) values (6, 5);
insert into play_author(play, author) values (7, 2);

go

insert into role_play(role, play) values (2, 7)

go

SET IDENTITY_INSERT actorTitle ON

insert into actorTitle(id, description) values (1, N'Заслуженный артист РСФСР');
insert into actorTitle(id, description) values (2, N'Заслуженный артист Российской Федерации');
insert into actorTitle(id, description) values (3, N'Заслуженный артист Императорских театров');
insert into actorTitle(id, description) values (4, N'Народный артист СССР');
insert into actorTitle(id, description) values (5, N'Народный артист РСФСР');
insert into actorTitle(id, description) values (6, N'Народный артист Российской Федерации');

SET IDENTITY_INSERT actorTitle OFF

go

SET IDENTITY_INSERT actor ON

insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (1, N'Джозеф', NULL, N'Файнс', 1970-05-27, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (2, N'Александр', NULL, N'Дербенев', 1994-01-01, 1);

SET IDENTITY_INSERT actor OFF

go

insert into actor_actorTitle(actor, actorTitle) values (2, 6);

go

SET IDENTITY_INSERT director ON

insert into director(id, name_first, name_middle, surname) values(1, N'Стивен', NULL, N'Моффат');

SET IDENTITY_INSERT director OFF

go

SET IDENTITY_INSERT staging ON
insert into staging(id, director, [name], description) values (1, 1, 'Доктор Кто', NULL);
insert into staging(id, director, [name], description) values (2, 1, 'На дне (новая версия)', N'Другой сюжет');
insert into staging(id, director, [name], description) values (3, 1, 'Гамлет', NULL);
SET IDENTITY_INSERT staging OFF

go

insert into play_staging(play, staging) values(7, 3);

go

SET IDENTITY_INSERT role_staging ON
insert into role_staging(id, [role], staging) values (1, 2, 3);
SET IDENTITY_INSERT role_staging OFF

go

SET IDENTITY_INSERT [cast] ON
insert into [cast](id, number) values (1, 1)
insert into [cast](id, number) values (2, 2)
insert into [cast](id, number) values (3, 300)
insert into [cast](id, number) values (4, 500)
SET IDENTITY_INSERT [cast] OFF

go

SET IDENTITY_INSERT actor_rolestaging ON
--insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast])
SET IDENTITY_INSERT actor_rolestaging OFF

go

use master