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
insert into roleType (id, description) values (5,  N'третья');
insert into roleType (id, description) values (6,  N'четвертая');
insert into roleType (id, description) values (7,  N'пятая');
insert into roleType (id, description) values (8,  N'периодическая');
insert into roleType (id, description) values (9,  N'четная');
insert into roleType (id, description) values (10,  N'нечетная');

SET IDENTITY_INSERT roleType OFF

go

SET IDENTITY_INSERT [role] ON

insert into [role](id, [name], gender, line, [type]) values (1,  N'техничка-шпионка', 2, 17, 4);
insert into [role](id, [name], gender, line, [type]) values (2,  N'Гамлет', 1, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (3,  N'Горацио', 1, 3, 1);

insert into [role](id, [name], gender, line, [type]) values (4,  N'Доктор', 1, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (5,  N'Клара', 2, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (6,  N'Эми', 2, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (7,  N'Рори', 1, 3, 2);

insert into [role](id, [name], gender, line, [type]) values (8,  N'Марк Бенфорд', 1, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (9,  N'Оливия', 2, 3, 2);

insert into [role](id, [name], gender, line, [type]) values (10,  N'Тофер', 1, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (11,  N'Адель', 2, 3, 2);
insert into [role](id, [name], gender, line, [type]) values (12,  N'Эко', 2, 3, 1);

insert into [role](id, [name], gender, line, [type]) values (13,  N'Реждина Миллс (злая королева)', 2, 3, 2);
insert into [role](id, [name], gender, line, [type]) values (14,  N'Генри', 1, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (15,  N'Эмма', 2, 3, 1);

insert into [role](id, [name], gender, line, [type]) values (16,  N'Гарри Поттер', 1, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (17,  N'Северус', 1, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (18,  N'Дамблдор', 1, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (19,  N'Малфой', 1, 3, 2);
insert into [role](id, [name], gender, line, [type]) values (20,  N'Сириус', 1, 3, 1);

insert into [role](id, [name], gender, line, [type]) values (21,  N'Подпространство', 1, 3, 1);
insert into [role](id, [name], gender, line, [type]) values (22,  N'Преобразование', 1, 3, 1);

insert into [role](id, [name], gender, line, [type]) values (23,  N'Джесси Пинкман', 1, 3, 1);

SET IDENTITY_INSERT [role] OFF

go

SET IDENTITY_INSERT author ON

insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (1, N'Михаил', N'Афанасьевич', N'Булгаков', 1891-05-03, 1940-03-10);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (2, N'Уильям', NULL, N'Шекспир', 1564-04-26, 1616-04-23);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (3, N'Николай', N'Васильевич', N'Гоголь', 1809-03-20, 1852-02-21);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (4, N'Максим', NULL, N'Горький', 1868-03-16, 1936-06-18);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (5, N'Антон', N'Павлович', N'Чехов', 1860-01-17, 1904-07-02);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (6, N'Джоан', N'К', N'Роулинг', 1900-01-01, NULL);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (7, N'Джосс', NULL, N'Уэдон', 1900-01-01, NULL);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (8, N'Вася', N'Иванович', N'Пупкин', 1900-01-01, NULL);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (9, N'Дмитрий', NULL, N'Беклемишев', 1900-01-01, NULL);
insert into author(id, name_first, name_middle, surname, birthDate, deathDate) values (10, N'Иван', NULL, N'Иванов', 1900-01-01, NULL);



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
insert into play(id, [name], description) values (8,  N'FlashForward', N'тексттекст')
insert into play(id, [name], description) values (9,  N'Доктор Кто', N'тексттекст')
insert into play(id, [name], description) values (10,  N'Dollhouse', N'тексттекст')
insert into play(id, [name], description) values (11,  N'Once Upon a Time', N'тексттекст')
insert into play(id, [name], description) values (12,  N'Гарри Поттер', N'тексттекст')
insert into play(id, [name], description) values (13,  N'Breaking Bad', N'тексттекст')


SET IDENTITY_INSERT play OFF

go

insert into play_author(play, author) values (1, 1);
insert into play_author(play, author) values (2, 1);
insert into play_author(play, author) values (3, 4);
insert into play_author(play, author) values (4, 4);
insert into play_author(play, author) values (5, 4);
insert into play_author(play, author) values (6, 5);
insert into play_author(play, author) values (7, 2);
insert into play_author(play, author) values (8, 10);
insert into play_author(play, author) values (9, 8);
insert into play_author(play, author) values (10, 7);
insert into play_author(play, author) values (11, 10);
insert into play_author(play, author) values (12, 6);
insert into play_author(play, author) values (1, 2);
insert into play_author(play, author) values (2, 3);
insert into play_author(play, author) values (3, 3);
insert into play_author(play, author) values (4, 5);
insert into play_author(play, author) values (5, 2);
insert into play_author(play, author) values (6, 7);
insert into play_author(play, author) values (7, 3);
insert into play_author(play, author) values (8, 9);
insert into play_author(play, author) values (9, 4);
insert into play_author(play, author) values (10, 3);
insert into play_author(play, author) values (11, 5);
insert into play_author(play, author) values (12, 1);
go

insert into role_play(role, play) values (1, 8)
insert into role_play(role, play) values (2, 7)
insert into role_play(role, play) values (3, 6)
insert into role_play(role, play) values (4, 3)
insert into role_play(role, play) values (5, 5)
insert into role_play(role, play) values (6, 4)
insert into role_play(role, play) values (7, 2)
insert into role_play(role, play) values (8, 1)
insert into role_play(role, play) values (9, 12)
insert into role_play(role, play) values (10, 11)
insert into role_play(role, play) values (11, 10)
insert into role_play(role, play) values (12, 9)
insert into role_play(role, play) values (13, 8)
insert into role_play(role, play) values (14, 7)
insert into role_play(role, play) values (15, 6)
insert into role_play(role, play) values (16, 5)
insert into role_play(role, play) values (17, 4)
insert into role_play(role, play) values (18, 3)
insert into role_play(role, play) values (19, 2)
insert into role_play(role, play) values (20, 1)
insert into role_play(role, play) values (21, 13)
insert into role_play(role, play) values (22, 13)
insert into role_play(role, play) values (23, 13)

go

SET IDENTITY_INSERT actorTitle ON

insert into actorTitle(id, description) values (1, N'Заслуженный артист РСФСР');
insert into actorTitle(id, description) values (2, N'Заслуженный артист Российской Федерации');
insert into actorTitle(id, description) values (3, N'Заслуженный артист Императорских театров');
insert into actorTitle(id, description) values (4, N'Народный артист СССР');
insert into actorTitle(id, description) values (5, N'Народный артист РСФСР');
insert into actorTitle(id, description) values (6, N'Народный артист Российской Федерации');
insert into actorTitle(id, description) values (7, N'Почетный титул Семи Королевств');
insert into actorTitle(id, description) values (8, N'Актер Года');
insert into actorTitle(id, description) values (9, N'Самое скучное выступление');
insert into actorTitle(id, description) values (10, N'Имеет Оскар');

SET IDENTITY_INSERT actorTitle OFF

go

SET IDENTITY_INSERT actor ON

insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (1, N'Джозеф', NULL, N'Файнс', 1970-05-27, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (2, N'Александр', NULL, N'Дербенев', 1994-01-01, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (3, N'Леонардо', NULL, N'Ди Каприо', 1994-01-01, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (4, N'Вася', NULL, N'Васильев', 1994-01-01, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (5, N'Иван', NULL, N'Иванов', 1994-01-01, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (6, N'Эмма', NULL, N'Уотсон', 1994-01-01, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (7, N'Мэтт', NULL, N'Смитт', 1994-01-01, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (8, N'Лана', NULL, N'Дел Рэй', 1994-01-01, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (9, N'Максим', NULL, N'Балашов', 1994-01-01, 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (10, N'Сергей', NULL, N'Сергеев', 1994-01-01, 1);

SET IDENTITY_INSERT actor OFF

go

insert into actor_actorTitle(actor, actorTitle) values (1, 10);
insert into actor_actorTitle(actor, actorTitle) values (2, 9);
insert into actor_actorTitle(actor, actorTitle) values (3, 8);
insert into actor_actorTitle(actor, actorTitle) values (4, 7);
insert into actor_actorTitle(actor, actorTitle) values (5, 6);
insert into actor_actorTitle(actor, actorTitle) values (6, 5);
insert into actor_actorTitle(actor, actorTitle) values (7, 4);
insert into actor_actorTitle(actor, actorTitle) values (8, 3);
insert into actor_actorTitle(actor, actorTitle) values (9, 2);
insert into actor_actorTitle(actor, actorTitle) values (10, 1);

insert into actor_actorTitle(actor, actorTitle) values (1, 1);
insert into actor_actorTitle(actor, actorTitle) values (2, 2);
insert into actor_actorTitle(actor, actorTitle) values (3, 3);
insert into actor_actorTitle(actor, actorTitle) values (4, 4);
insert into actor_actorTitle(actor, actorTitle) values (5, 5);
insert into actor_actorTitle(actor, actorTitle) values (6, 6);
insert into actor_actorTitle(actor, actorTitle) values (7, 7);
insert into actor_actorTitle(actor, actorTitle) values (8, 8);
insert into actor_actorTitle(actor, actorTitle) values (9, 9);
insert into actor_actorTitle(actor, actorTitle) values (10, 10);

go

SET IDENTITY_INSERT director ON

insert into director(id, name_first, name_middle, surname) values(1, N'Стивен', NULL, N'Моффат');
insert into director(id, name_first, name_middle, surname) values(2, N'Джосс', NULL, N'Уэдон');
insert into director(id, name_first, name_middle, surname) values(3, N'Вася', NULL, N'Пупкин');
insert into director(id, name_first, name_middle, surname) values(4, N'Роберт', NULL, N'Карлайл');
insert into director(id, name_first, name_middle, surname) values(5, N'Луи', NULL, N'Феррейра');
insert into director(id, name_first, name_middle, surname) values(6, N'Дэвид', NULL, N'Блю');
insert into director(id, name_first, name_middle, surname) values(7, N'Джо', NULL, N'Флэниган');
insert into director(id, name_first, name_middle, surname) values(8, N'Рэйчел', NULL, N'Латтрелл');
insert into director(id, name_first, name_middle, surname) values(9, N'Бенедикт', NULL, N'Камбербетч');
insert into director(id, name_first, name_middle, surname) values(10, N'Владимир', NULL, N'Вановский');

SET IDENTITY_INSERT director OFF

go

SET IDENTITY_INSERT staging ON
insert into staging(id, director, [name], description) values (1, 1, 'Доктор Кто (по сериалу)', NULL);
insert into staging(id, director, [name], description) values (2, 2, 'На дне (новая версия)', N'Другой сюжет');
insert into staging(id, director, [name], description) values (3, 3, 'Гамлет', NULL);
insert into staging(id, director, [name], description) values (4, 4, 'Dollhouse (по сериалу)', NULL);
insert into staging(id, director, [name], description) values (5, 3, 'Гарри Поттер', NULL);
insert into staging(id, director, [name], description) values (6, 2, 'Once Upon A Time', NULL);
insert into staging(id, director, [name], description) values (7, 1, 'Once Upon A Time in Wonderland', NULL);
insert into staging(id, director, [name], description) values (8, 5, 'Аналитическая Геометрия', NULL);
insert into staging(id, director, [name], description) values (9, 6, 'FlashForward', NULL);
insert into staging(id, director, [name], description) values (10, 7, 'Три Сестры', NULL);
insert into staging(id, director, [name], description) values (11, 1, 'Breaking Bad', NULL);
SET IDENTITY_INSERT staging OFF

go

insert into play_staging(play, staging) values(1, 1);
insert into play_staging(play, staging) values(2, 2);
insert into play_staging(play, staging) values(3, 3);
insert into play_staging(play, staging) values(4, 4);
insert into play_staging(play, staging) values(5, 5);
insert into play_staging(play, staging) values(6, 6);
insert into play_staging(play, staging) values(7, 7);
insert into play_staging(play, staging) values(8, 8);
insert into play_staging(play, staging) values(9, 9);
insert into play_staging(play, staging) values(10, 10);
insert into play_staging(play, staging) values(11, 1);
insert into play_staging(play, staging) values(12, 2);
insert into play_staging(play, staging) values(13, 3);

go

SET IDENTITY_INSERT role_staging ON
insert into role_staging(id, [role], staging) values (1, 1, 3);
insert into role_staging(id, [role], staging) values (2, 2, 4);
insert into role_staging(id, [role], staging) values (3, 3, 2);
insert into role_staging(id, [role], staging) values (4, 4, 1);
insert into role_staging(id, [role], staging) values (5, 5, 5);
insert into role_staging(id, [role], staging) values (6, 6, 6);
insert into role_staging(id, [role], staging) values (7, 7, 7);
insert into role_staging(id, [role], staging) values (8, 8, 8);
insert into role_staging(id, [role], staging) values (9, 9, 9);
insert into role_staging(id, [role], staging) values (10, 10, 10);
insert into role_staging(id, [role], staging) values (11, 11, 11);
insert into role_staging(id, [role], staging) values (12, 12, 10);
insert into role_staging(id, [role], staging) values (13, 13, 9);
insert into role_staging(id, [role], staging) values (14, 14, 8);
insert into role_staging(id, [role], staging) values (15, 15, 7);
insert into role_staging(id, [role], staging) values (16, 16, 6);
insert into role_staging(id, [role], staging) values (17, 17, 5);
insert into role_staging(id, [role], staging) values (18, 18, 4);
insert into role_staging(id, [role], staging) values (19, 19, 3);
insert into role_staging(id, [role], staging) values (20, 20, 2);
insert into role_staging(id, [role], staging) values (21, 21, 1);
insert into role_staging(id, [role], staging) values (23, 22, 11);
SET IDENTITY_INSERT role_staging OFF

go

SET IDENTITY_INSERT [cast] ON
insert into [cast](id, number) values (1, 1)
insert into [cast](id, number) values (2, 2)
insert into [cast](id, number) values (3, 308)
insert into [cast](id, number) values (4, 507)
insert into [cast](id, number) values (5, 506)
insert into [cast](id, number) values (6, 505)
insert into [cast](id, number) values (7, 504)
insert into [cast](id, number) values (8, 503)
insert into [cast](id, number) values (9, 502)
insert into [cast](id, number) values (10, 501)
SET IDENTITY_INSERT [cast] OFF

go

SET IDENTITY_INSERT actor_rolestaging ON
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (1, 1, 1, 2010-01-01, 2015-02-02, 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (2, 2, 1, 2010-01-01, 2015-02-02, 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (3, 3, 1, 2010-01-01, 2015-02-02, 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (4, 4, 2, 2010-01-01, 2015-02-02, 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (5, 5, 3, 2010-01-01, 2015-02-02, 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (6, 6, 4, 2010-01-01, 2015-02-02, 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (7, 7, 10, 2010-01-01, 2015-02-02, 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (8, 8, 5, 2010-01-01, 2015-02-02, 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (9, 9, 6, 2010-01-01, 2015-02-02, 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (10, 10, 7, 2010-01-01, 2015-02-02, 1)
SET IDENTITY_INSERT actor_rolestaging OFF

go

SET IDENTITY_INSERT cast_staging ON
insert into cast_staging(id, [cast], staging) values (1, 10, 1);
insert into cast_staging(id, [cast], staging) values (2, 9, 2);
insert into cast_staging(id, [cast], staging) values (3, 8, 3);
insert into cast_staging(id, [cast], staging) values (4, 7, 4);
insert into cast_staging(id, [cast], staging) values (5, 6, 5);
insert into cast_staging(id, [cast], staging) values (6, 5, 6);
insert into cast_staging(id, [cast], staging) values (7, 4, 7);
insert into cast_staging(id, [cast], staging) values (8, 3, 8);
insert into cast_staging(id, [cast], staging) values (9, 2, 9);
insert into cast_staging(id, [cast], staging) values (10, 1, 10);
SET IDENTITY_INSERT cast_staging OFF

go

SET IDENTITY_INSERT performance ON
insert into performance(id, [date], staging, cast_staging) values (1, 2014-01-01, 1, 1);
insert into performance(id, [date], staging, cast_staging) values (2, 2014-02-01, 1, 2);
insert into performance(id, [date], staging, cast_staging) values (3, 2014-03-01, 2, 1);
insert into performance(id, [date], staging, cast_staging) values (4, 2014-04-01, 3, 2);
insert into performance(id, [date], staging, cast_staging) values (5, 2014-05-01, 2, 3);
insert into performance(id, [date], staging, cast_staging) values (6, 2014-06-01, 1, 1);
insert into performance(id, [date], staging, cast_staging) values (7, 2014-07-01, 3, 5);
insert into performance(id, [date], staging, cast_staging) values (8, 2014-08-01, 4, 7);
insert into performance(id, [date], staging, cast_staging) values (9, 2014-09-01, 5, 9);
insert into performance(id, [date], staging, cast_staging) values (10, 2014-10-01, 5, 10);

SET IDENTITY_INSERT performance OFF

go

SET IDENTITY_INSERT castReplace ON

insert into castReplace(id, a, b) values (1, 1, 2);
insert into castReplace(id, a, b) values (2, 2, 3);
insert into castReplace(id, a, b) values (3, 3, 4);
insert into castReplace(id, a, b) values (4, 4, 5);
insert into castReplace(id, a, b) values (5, 5, 6);
insert into castReplace(id, a, b) values (6, 6, 7);
insert into castReplace(id, a, b) values (7, 7, 8);
insert into castReplace(id, a, b) values (8, 8, 9);
insert into castReplace(id, a, b) values (9, 9, 10);
insert into castReplace(id, a, b) values (10, 10, 1);
insert into castReplace(id, a, b) values (11, 10, 2);

SET IDENTITY_INSERT castReplace OFF

go

SET IDENTITY_INSERT room ON

insert into room(id, [name]) values (1, N'1');
insert into room(id, [name]) values (2, N'12');
insert into room(id, [name]) values (3, N'13');
insert into room(id, [name]) values (4, N'14');
insert into room(id, [name]) values (5, N'15');
insert into room(id, [name]) values (6, N'16');
insert into room(id, [name]) values (7, N'17');
insert into room(id, [name]) values (8, N'18');
insert into room(id, [name]) values (9, N'404');
insert into room(id, [name]) values (10, N'303');

SET IDENTITY_INSERT room OFF

go

SET IDENTITY_INSERT seatType ON

insert into seatType(id, [description]) values (1, N'T81');
insert into seatType(id, [description]) values (2, N'T11');
insert into seatType(id, [description]) values (3, N'T81');
insert into seatType(id, [description]) values (4, N'T21');
insert into seatType(id, [description]) values (5, N'T71');
insert into seatType(id, [description]) values (6, N'T61');
insert into seatType(id, [description]) values (7, N'T3451');
insert into seatType(id, [description]) values (8, N'T341');
insert into seatType(id, [description]) values (9, N'T13');
insert into seatType(id, [description]) values (10, N'T12');
insert into seatType(id, [description]) values (11, N'T1');


SET IDENTITY_INSERT seatType OFF

go

SET IDENTITY_INSERT seat ON

insert into seat(id, seat, row, room, [type]) values (1, 1, 1, 7, 1);
insert into seat(id, seat, row, room, [type]) values (2, 2, 2, 1, 2);
insert into seat(id, seat, row, room, [type]) values (3, 3, 3, 6, 3);
insert into seat(id, seat, row, room, [type]) values (4, 4, 1, 3, 3);
insert into seat(id, seat, row, room, [type]) values (5, 5, 5, 2, 3);
insert into seat(id, seat, row, room, [type]) values (6, 6, 10, 5, 5);
insert into seat(id, seat, row, room, [type]) values (7, 7, 9, 6, 10);
insert into seat(id, seat, row, room, [type]) values (8, 8, 2, 7, 6);
insert into seat(id, seat, row, room, [type]) values (9, 9, 7, 8, 1);
insert into seat(id, seat, row, room, [type]) values (10, 10, 5, 9, 2);

SET IDENTITY_INSERT seat OFF

go

SET IDENTITY_INSERT actorrolestaging_performance ON

insert into actorrolestaging_performance(id, actorrolestaging, performance) values (1, 1, 2);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (2, 2, 1);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (3, 3, 3);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (4, 4, 7);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (5, 5, 4);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (6, 6, 5);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (7, 7, 6);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (8, 8, 9);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (9, 9, 8);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (10, 9, 9);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (11, 8, 2);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (12, 7, 1);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (13, 6, 3);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (14, 5, 7);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (15, 4, 4);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (16, 3, 5);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (17, 2, 6);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (18, 1, 7);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (19, 1, 8);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (20, 1, 9);


SET IDENTITY_INSERT actorrolestaging_performance OFF

go

SET IDENTITY_INSERT seat_performance ON

insert into seat_performance(id, seat, performance) values (1, 1, 10);
insert into seat_performance(id, seat, performance) values (2, 2, 9);
insert into seat_performance(id, seat, performance) values (3, 3, 8);
insert into seat_performance(id, seat, performance) values (4, 4, 7);
insert into seat_performance(id, seat, performance) values (5, 5, 6);
insert into seat_performance(id, seat, performance) values (6, 6, 5);
insert into seat_performance(id, seat, performance) values (7, 7, 4);
insert into seat_performance(id, seat, performance) values (8, 8, 3);
insert into seat_performance(id, seat, performance) values (9, 9, 2);
insert into seat_performance(id, seat, performance) values (10, 10, 1);

SET IDENTITY_INSERT seat_performance OFF


go


use master