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
insert into [role](id, [name], gender, line, [type]) values (2,  N'Гамлет', 1, 15, 3);
insert into [role](id, [name], gender, line, [type]) values (3,  N'Горацио', 1, 13, 2);

insert into [role](id, [name], gender, line, [type]) values (4,  N'Доктор', 1, 7, 1);
insert into [role](id, [name], gender, line, [type]) values (5,  N'Клара', 2, 2, 3);
insert into [role](id, [name], gender, line, [type]) values (6,  N'Эми', 2, 1, 5);
insert into [role](id, [name], gender, line, [type]) values (7,  N'Рори', 1, 3, 2);

insert into [role](id, [name], gender, line, [type]) values (8,  N'Марк Бенфорд', 1, 1, 7);
insert into [role](id, [name], gender, line, [type]) values (9,  N'Оливия', 2, 4, 2);

insert into [role](id, [name], gender, line, [type]) values (10,  N'Тофер', 1, 6, 7);
insert into [role](id, [name], gender, line, [type]) values (11,  N'Адель', 2, 5, 2);
insert into [role](id, [name], gender, line, [type]) values (12,  N'Эко', 2, 7, 9);

insert into [role](id, [name], gender, line, [type]) values (13,  N'Реждина Миллс (злая королева)', 2, 3, 6);
insert into [role](id, [name], gender, line, [type]) values (14,  N'Генри', 1, 1, 4);
insert into [role](id, [name], gender, line, [type]) values (15,  N'Эмма', 2, 2, 3);

insert into [role](id, [name], gender, line, [type]) values (16,  N'Гарри Поттер', 1, 2, 5);
insert into [role](id, [name], gender, line, [type]) values (17,  N'Северус', 1, 7, 2);
insert into [role](id, [name], gender, line, [type]) values (18,  N'Дамблдор', 1, 6, 1);
insert into [role](id, [name], gender, line, [type]) values (19,  N'Малфой', 1, 4, 2);
insert into [role](id, [name], gender, line, [type]) values (20,  N'Сириус', 1, 3, 7);

insert into [role](id, [name], gender, line, [type]) values (21,  N'Подпространство', 1, 7, 2);
insert into [role](id, [name], gender, line, [type]) values (22,  N'Преобразование', 1, 1, 6);

insert into [role](id, [name], gender, line, [type]) values (23,  N'Джесси Пинкман', 1, 7, 9);

insert into [role](id, [name], gender, line, [type]) values (24,  N'Кира Кэмерон', 2, 5, 10);
insert into [role](id, [name], gender, line, [type]) values (25,  N'Алек Сатлер', 1, 6, 9);
insert into [role](id, [name], gender, line, [type]) values (26,  N'Арагорн', 1, 3, 8);
insert into [role](id, [name], gender, line, [type]) values (27,  N'Дарт Вейдер', 1, 2, 5);
insert into [role](id, [name], gender, line, [type]) values (28,  N'Иван', 1, 1, 3);
insert into [role](id, [name], gender, line, [type]) values (29,  N'Джордан', 1, 5, 2);

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
insert into play(id, [name], description) values (8,  N'FlashForward', N'asdf')
insert into play(id, [name], description) values (9,  N'Доктор Кто', N'тексттекст')
insert into play(id, [name], description) values (10,  N'Dollhouse', N'тексттекст')
insert into play(id, [name], description) values (11,  N'Once Upon a Time', N'тексттекст')
insert into play(id, [name], description) values (12,  N'Гарри Поттер', N'тексттекст')
insert into play(id, [name], description) values (13,  N'Breaking Bad', N'тексттекст')
insert into play(id, [name], description) values (14,  N'Continuum', N'тексттекст')
insert into play(id, [name], description) values (15,  N'4400', N'тексттекст')
insert into play(id, [name], description) values (16,  N'Властелин Колец', N'тексттекст')
insert into play(id, [name], description) values (17,  N'Звездные войны', N'тексттекст')


SET IDENTITY_INSERT play OFF

go

insert into play_author(play, author) values (1, 1);
insert into play_author(play, author) values (2, 1);
insert into play_author(play, author) values (3, 4);
insert into play_author(play, author) values (4, 4);
insert into play_author(play, author) values (5, 4);
insert into play_author(play, author) values (6, 5);
insert into play_author(play, author) values (7, 2);
insert into play_author(play, author) values (8, 9);
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

insert into role_play(role, play) values (1, 14)
insert into role_play(role, play) values (1, 15)
insert into role_play(role, play) values (1, 10)
insert into role_play(role, play) values (1, 6)
insert into role_play(role, play) values (2, 7)
insert into role_play(role, play) values (3, 7)
insert into role_play(role, play) values (4, 9)
insert into role_play(role, play) values (5, 9)
insert into role_play(role, play) values (6, 9)
insert into role_play(role, play) values (7, 9)
insert into role_play(role, play) values (8, 8)
insert into role_play(role, play) values (9, 8)
insert into role_play(role, play) values (10, 10)
insert into role_play(role, play) values (11, 10)
insert into role_play(role, play) values (12, 10)
insert into role_play(role, play) values (13, 11)
insert into role_play(role, play) values (14, 11)
insert into role_play(role, play) values (15, 11)
insert into role_play(role, play) values (16, 12)
insert into role_play(role, play) values (17, 12)
insert into role_play(role, play) values (18, 12)
insert into role_play(role, play) values (19, 12)
insert into role_play(role, play) values (20, 12)
insert into role_play(role, play) values (23, 13)
insert into role_play(role, play) values (24, 14)
insert into role_play(role, play) values (25, 14)
insert into role_play(role, play) values (26, 16)
insert into role_play(role, play) values (27, 17)
insert into role_play(role, play) values (28, 1)
insert into role_play(role, play) values (29, 15)
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
insert into actorTitle(id, description) values (11, N'Не имеет Оскара');

SET IDENTITY_INSERT actorTitle OFF

go

SET IDENTITY_INSERT actor ON

insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (1, N'Джозеф', NULL, N'Файнс', '1970-05-27', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (2, N'Александр', NULL, N'Дербенев', '1934-06-03', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (3, N'Леонардо', NULL, N'Ди Каприо', '1964-03-06', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (4, N'Вася', NULL, N'Васильев', '1974-04-21', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (5, N'Иван', NULL, N'Иванов', '1914-09-12', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (6, N'Эмма', NULL, N'Уотсон', '1954-11-17', 2);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (7, N'Мэтт', NULL, N'Смитт', '1974-10-19', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (8, N'Лана', NULL, N'Дел Рей', '1994-06-16', 2);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (9, N'Максим', NULL, N'Балашов', '1964-12-13', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (10, N'Сергей', NULL, N'Сергеев', '1974-07-08', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (11, N'Элайза', NULL, N'Душку', '1934-03-09', 2);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (12, N'Саммер', NULL, N'Глау', '1916-06-14', 2);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (13, N'Артур', NULL, N'Дарвилл', '1915-06-14', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (14, N'Алессандра', NULL, N'Торресани', '1912-06-14', 2);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (15, N'Элисон', NULL, N'Скалиотти', '1999-06-14', 2);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (16, N'Карен', NULL, N'Гиллан', '1981-06-14', 2);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (17, N'Оливия', NULL, N'Уильямс', '1974-06-14', 2);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (18, N'Дэниел', NULL, N'Рэдклифф', '1944-06-14', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (19, N'Роберт', NULL, N'Карлайл', '1994-06-14', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (20, N'Алексей', NULL, N'Суханов', '1964-06-14', 1);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (21, N'Lana', NULL, N'Parilla', '1964-06-14', 2);
insert into actor(id, name_first, name_middle, surname, birthDate, gender) values (22, N'Nothing', NULL, N'Nothing', '1964-06-14', 2);

SET IDENTITY_INSERT actor OFF

go

insert into actor_actorTitle(actor, actorTitle) values (1, 10);
insert into actor_actorTitle(actor, actorTitle) values (2, 9);
insert into actor_actorTitle(actor, actorTitle) values (3, 11);
insert into actor_actorTitle(actor, actorTitle) values (4, 7);
insert into actor_actorTitle(actor, actorTitle) values (5, 6);
insert into actor_actorTitle(actor, actorTitle) values (6, 5);
insert into actor_actorTitle(actor, actorTitle) values (7, 4);
insert into actor_actorTitle(actor, actorTitle) values (8, 3);
insert into actor_actorTitle(actor, actorTitle) values (9, 2);
insert into actor_actorTitle(actor, actorTitle) values (10, 1);

insert into actor_actorTitle(actor, actorTitle) values (1, 1);
insert into actor_actorTitle(actor, actorTitle) values (2, 2);
insert into actor_actorTitle(actor, actorTitle) values (4, 4);
insert into actor_actorTitle(actor, actorTitle) values (5, 5);
insert into actor_actorTitle(actor, actorTitle) values (6, 6);
insert into actor_actorTitle(actor, actorTitle) values (7, 7);
insert into actor_actorTitle(actor, actorTitle) values (8, 8);
insert into actor_actorTitle(actor, actorTitle) values (9, 9);
insert into actor_actorTitle(actor, actorTitle) values (10, 10);
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
insert into staging(id, director, [name], description) values (1, 1, N'Доктор Кто (по сериалу)', NULL);
insert into staging(id, director, [name], description) values (2, 7, N'На дне (новая версия)', N'Другой сюжет');
insert into staging(id, director, [name], description) values (3, 10, N'Гамлет', NULL);
insert into staging(id, director, [name], description) values (4, 2, N'Dollhouse (по сериалу)', NULL);
insert into staging(id, director, [name], description) values (5, 8, N'Гарри Поттер', NULL);
insert into staging(id, director, [name], description) values (6, 9, N'Once Upon A Time', NULL);
insert into staging(id, director, [name], description) values (7, 9, N'Once Upon A Time in Wonderland', NULL);
insert into staging(id, director, [name], description) values (8, 3, N'Аналитическая Геометрия', NULL);
insert into staging(id, director, [name], description) values (9, 5, N'FlashForward', NULL);
insert into staging(id, director, [name], description) values (10, 10, N'Три Сестры', NULL);
insert into staging(id, director, [name], description) values (11, 2, N'Breaking Bad', NULL);
insert into staging(id, director, [name], description) values (12, 3, N'Continuum S3', NULL);
insert into staging(id, director, [name], description) values (13, 8, N'Иван Васильевич меняет профессию', NULL);
insert into staging(id, director, [name], description) values (14, 2, N'Адам и Ева', NULL);
insert into staging(id, director, [name], description) values (15, 3, N'Враги', NULL);
insert into staging(id, director, [name], description) values (16, 6, N'Егор Булычов и другие', NULL);
insert into staging(id, director, [name], description) values (17, 6, N'The 4400', NULL);
insert into staging(id, director, [name], description) values (18, 3, N'Властелин Колец: Возвращение Короля', NULL);
insert into staging(id, director, [name], description) values (19, 4, N'Звездные войны VI', NULL);
insert into staging(id, director, [name], description) values (20, 4, N'Звездные войны V', NULL);
insert into staging(id, director, [name], description) values (21, 4, N'Звездные войны IV', NULL);
insert into staging(id, director, [name], description) values (22, 5, N'Звездные войны III', NULL);
insert into staging(id, director, [name], description) values (23, 7, N'FlashForward S2', NULL);
insert into staging(id, director, [name], description) values (24, 1, N'Враги', N'совершенно новый сюжет');
insert into staging(id, director, [name], description) values (25, 2, N'На дне', N'инновационное видение');
insert into staging(id, director, [name], description) values (26, 1, N'Доктор Кто (old)', N'инновационное видение');
SET IDENTITY_INSERT staging OFF

go

insert into play_staging(staging, play) values(1, 9);
insert into play_staging(staging, play) values(2, 5);
insert into play_staging(staging, play) values(3, 7);
insert into play_staging(staging, play) values(4, 10);
insert into play_staging(staging, play) values(5, 12);
insert into play_staging(staging, play) values(6, 11);
insert into play_staging(staging, play) values(7, 11);
insert into play_staging(staging, play) values(9, 8);
insert into play_staging(staging, play) values(10, 6);
insert into play_staging(staging, play) values(11, 13);
insert into play_staging(staging, play) values(12, 14);
insert into play_staging(staging, play) values(13, 1);
insert into play_staging(staging, play) values(14, 2);
insert into play_staging(staging, play) values(15, 3);
insert into play_staging(staging, play) values(16, 4);
insert into play_staging(staging, play) values(17, 15);
insert into play_staging(staging, play) values(18, 16);
insert into play_staging(staging, play) values(19, 17);
insert into play_staging(staging, play) values(20, 17);
insert into play_staging(staging, play) values(21, 17);
insert into play_staging(staging, play) values(22, 17);
insert into play_staging(staging, play) values(23, 8);
insert into play_staging(staging, play) values(24, 3);
insert into play_staging(staging, play) values(25, 5);

go

SET IDENTITY_INSERT role_staging ON
insert into role_staging(id, [role], staging) values (1, 1, 5);
insert into role_staging(id, [role], staging) values (2, 1, 8);
insert into role_staging(id, [role], staging) values (3, 1, 18);
insert into role_staging(id, [role], staging) values (4, 1, 3);
insert into role_staging(id, [role], staging) values (5, 2, 3);
insert into role_staging(id, [role], staging) values (6, 3, 3);
insert into role_staging(id, [role], staging) values (7, 4, 1);
insert into role_staging(id, [role], staging) values (8, 5, 1);
insert into role_staging(id, [role], staging) values (9, 6, 1);
insert into role_staging(id, [role], staging) values (10, 7, 1);
insert into role_staging(id, [role], staging) values (11, 8, 9);
insert into role_staging(id, [role], staging) values (12, 8, 23);
insert into role_staging(id, [role], staging) values (13, 9, 9);
insert into role_staging(id, [role], staging) values (14, 9, 23);
insert into role_staging(id, [role], staging) values (15, 10, 4);
insert into role_staging(id, [role], staging) values (16, 11, 4);
insert into role_staging(id, [role], staging) values (17, 12, 4);
insert into role_staging(id, [role], staging) values (18, 13, 6);
insert into role_staging(id, [role], staging) values (19, 13, 7);
insert into role_staging(id, [role], staging) values (20, 14, 6);
insert into role_staging(id, [role], staging) values (21, 15, 6);
insert into role_staging(id, [role], staging) values (22, 15, 7);
insert into role_staging(id, [role], staging) values (23, 16, 5);
insert into role_staging(id, [role], staging) values (24, 17, 5);
insert into role_staging(id, [role], staging) values (25, 18, 5);
insert into role_staging(id, [role], staging) values (26, 19, 5);
insert into role_staging(id, [role], staging) values (27, 20, 5);
insert into role_staging(id, [role], staging) values (28, 21, 8);
insert into role_staging(id, [role], staging) values (29, 22, 8);
insert into role_staging(id, [role], staging) values (30, 23, 11);
insert into role_staging(id, [role], staging) values (31, 24, 12);
insert into role_staging(id, [role], staging) values (32, 25, 12);
insert into role_staging(id, [role], staging) values (33, 26, 18);
insert into role_staging(id, [role], staging) values (34, 27, 19);
insert into role_staging(id, [role], staging) values (35, 27, 20);
insert into role_staging(id, [role], staging) values (36, 27, 21);
insert into role_staging(id, [role], staging) values (37, 27, 22);
insert into role_staging(id, [role], staging) values (38, 28, 13);
insert into role_staging(id, [role], staging) values (39, 29, 17);

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
insert into [cast](id, number) values (10, 571)
insert into [cast](id, number) values (11, 561)
insert into [cast](id, number) values (12, 511)
insert into [cast](id, number) values (13, 131)
SET IDENTITY_INSERT [cast] OFF

go

SET IDENTITY_INSERT actor_rolestaging ON
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (28, 1, 11,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (29, 1, 11,  '2014-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (30, 1, 16,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (31, 1, 12,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (32, 1, 10,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (33, 5, 11,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (34, 5, 1,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (35, 5, 2,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (36, 2, 2,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (37, 9, 3,  '2010-01-01', '2011-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (38, 9, 4,  '2010-01-01', '2011-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (39, 9, 5,  '2010-01-01', '2011-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (40, 9, 6,  '2010-01-01', '2011-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (1, 8, 12,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (2, 14, 1,  '2010-01-01', '2015-02-02', 2)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (50, 14, 2,  '2010-01-01', '2015-02-02', 2)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (3, 17, 3,  '2010-01-01', '2010-02-02', 2)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (4, 4, 38,  '2010-01-01', '2015-02-02', 3)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (5, 5, 34,  '2010-01-01', '2015-02-02', 3)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (6, 5, 35,  '2010-01-01', '2015-02-02', 4)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (7, 5, 36,  '2010-01-01', '2015-02-02', 5)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (8, 6, 5,  '2010-01-01', '2015-02-02', 4)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (9, 7, 7,  '2010-01-01', '2015-02-02', 6)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (10, 8, 37,  '2010-01-01', '2015-02-02', 6)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (11, 9, 29,  '2010-01-01', '2015-02-02', 5)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (12, 10, 1,  '2010-01-01', '2015-02-02', 7)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (13, 11, 17,  '2010-01-01', '2015-02-02', 7)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (14, 12, 31,  '2010-01-01', '2015-02-02', 7)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (15, 13, 10,  '2010-01-01', '2015-02-02', 8)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (16, 14, 16,  '2010-01-01', '2015-02-02', 9)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (17, 15, 19,  '2010-01-01', '2015-02-02', 9)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (18, 21, 18,  '2010-01-01', '2015-02-02', 4)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (19, 21, 19,  '2010-01-01', '2015-02-02', 1)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (20, 16, 9,  '2010-01-01', '2015-02-02', 5)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (21, 17, 16,  '2010-01-01', '2015-02-02', 10)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (22, 18, 23,  '2010-01-01', '2015-02-02', 7)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (23, 19, 15,  '2010-01-01', '2015-02-02', 3)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (24, 20, 25,  '2010-01-01', '2015-02-02', 6)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (25, 6, 3,  '2010-01-01', '2015-02-02', 6)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (26, 7, 3,  '2010-01-01', '2015-02-02', 4)
insert into actor_rolestaging(id, actor, role_staging, beginDate, endDate, [cast]) values (27, 13, 2,  '2010-01-01', '2015-02-02', 8)

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
insert into performance(id, [date], staging, cast_staging) values (1, '2014-01-01', 1, NULL);
insert into performance(id, [date], staging, cast_staging) values (2, '2014-02-02', 1, 2);
insert into performance(id, [date], staging, cast_staging) values (3, '2014-03-03', 2, NULL);
insert into performance(id, [date], staging, cast_staging) values (4, '2014-04-04', 3, 2);
insert into performance(id, [date], staging, cast_staging) values (5, '2014-05-05', 2, NULL);
insert into performance(id, [date], staging, cast_staging) values (6, '2014-06-06', 1, 4);
insert into performance(id, [date], staging, cast_staging) values (7, '2014-07-07', 3, NULL);
insert into performance(id, [date], staging, cast_staging) values (8, '2014-08-08', 4, 10);
insert into performance(id, [date], staging, cast_staging) values (9, '2014-09-09', 5, NULL);
insert into performance(id, [date], staging, cast_staging) values (10, '2014-03-10', 6, 5);
insert into performance(id, [date], staging, cast_staging) values (11, '2013-10-11', 6, NULL);
insert into performance(id, [date], staging, cast_staging) values (12, '2013-07-12', 8, 2);
insert into performance(id, [date], staging, cast_staging) values (13, '2013-10-15', 9, 3);
insert into performance(id, [date], staging, cast_staging) values (14, '2013-10-14', 10, NULL);
insert into performance(id, [date], staging, cast_staging) values (15, '2013-10-13', 11, 9);
insert into performance(id, [date], staging, cast_staging) values (16, '2013-09-16', 12, NULL);
insert into performance(id, [date], staging, cast_staging) values (17, '2013-09-17', 13, 9);
insert into performance(id, [date], staging, cast_staging) values (18, '2013-12-18', 13, NULL);
insert into performance(id, [date], staging, cast_staging) values (19, '2013-10-19', 1, 10);
insert into performance(id, [date], staging, cast_staging) values (20, '2013-11-20', 16, 9);
insert into performance(id, [date], staging, cast_staging) values (21, '2012-05-21', 17, NULL);
insert into performance(id, [date], staging, cast_staging) values (22, '2010-02-22', 22, 2);
insert into performance(id, [date], staging, cast_staging) values (23, '2014-05-23', 25, NULL);
insert into performance(id, [date], staging, cast_staging) values (24, '2013-05-25', 24, 7);
insert into performance(id, [date], staging, cast_staging) values (25, '2012-05-24', 23, 6);
insert into performance(id, [date], staging, cast_staging) values (26, '2011-01-26', 10, NULL);
insert into performance(id, [date], staging, cast_staging) values (27, '2010-08-01', 22, 5);
insert into performance(id, [date], staging, cast_staging) values (28, '2014-07-02', 21, 4);
insert into performance(id, [date], staging, cast_staging) values (29, '2013-12-03', 20, NULL);
insert into performance(id, [date], staging, cast_staging) values (30, '2012-06-04', 19, 3);
insert into performance(id, [date], staging, cast_staging) values (31, '2011-01-05', 18, NULL);
insert into performance(id, [date], staging, cast_staging) values (32, '2010-02-06', 17, 1);
insert into performance(id, [date], staging, cast_staging) values (33, '2014-03-07', 16, NULL);
insert into performance(id, [date], staging, cast_staging) values (34, '2013-04-08', 15, 7);
insert into performance(id, [date], staging, cast_staging) values (35, '2012-06-09', 1, 7);
insert into performance(id, [date], staging, cast_staging) values (36, '2011-12-10', 17, NULL);
insert into performance(id, [date], staging, cast_staging) values (37, '2010-06-11', 12, NULL);
insert into performance(id, [date], staging, cast_staging) values (38, '2010-01-12', 16, 5);
insert into performance(id, [date], staging, cast_staging) values (39, '2011-08-13', 1, NULL);
insert into performance(id, [date], staging, cast_staging) values (40, '2012-09-14', 9, 2);
insert into performance(id, [date], staging, cast_staging) values (41, '2013-10-15', 3, 1);

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
insert into seat(id, seat, row, room, [type]) values (11, 11, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (12, 12, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (13, 13, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (14, 14, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (15, 15, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (16, 16, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (17, 17, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (18, 18, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (19, 19, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (20, 20, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (21, 21, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (22, 22, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (23, 23, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (24, 24, 5, 9, 2);
insert into seat(id, seat, row, room, [type]) values (25, 25, 5, 9, 2);

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
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (14, 5, 30);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (15, 6, 29);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (16, 7, 28);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (17, 10, 22);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (18, 1, 7);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (19, 1, 8);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (20, 1, 9);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (21, 10, 1);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (22, 12, 2);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (23, 11, 3);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (24, 14, 4);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (25, 17, 5);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (26, 16, 6);
insert into actorrolestaging_performance(id, actorrolestaging, performance) values (27, 17, 13);


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

insert into seat_performance(id, seat, performance) values (11, 1, 10);
insert into seat_performance(id, seat, performance) values (12, 1, 9);
insert into seat_performance(id, seat, performance) values (13, 1, 8);
insert into seat_performance(id, seat, performance) values (14, 1, 7);
insert into seat_performance(id, seat, performance) values (15, 1, 6);
insert into seat_performance(id, seat, performance) values (16, 1, 5);
insert into seat_performance(id, seat, performance) values (17, 1, 4);
insert into seat_performance(id, seat, performance) values (18, 1, 3);
insert into seat_performance(id, seat, performance) values (19, 1, 2);
insert into seat_performance(id, seat, performance) values (20, 1, 6);
insert into seat_performance(id, seat, performance) values (21, 2, 12);
insert into seat_performance(id, seat, performance) values (22, 3, 2);
insert into seat_performance(id, seat, performance) values (23, 4, 11);
insert into seat_performance(id, seat, performance) values (24, 5, 6);
insert into seat_performance(id, seat, performance) values (25, 6, 4);
insert into seat_performance(id, seat, performance) values (26, 7, 10);
insert into seat_performance(id, seat, performance) values (27, 8, 7);
insert into seat_performance(id, seat, performance) values (28, 9, 4);
insert into seat_performance(id, seat, performance) values (29, 10, 6);
insert into seat_performance(id, seat, performance) values (30, 11, 3);
insert into seat_performance(id, seat, performance) values (31, 12, 2);

SET IDENTITY_INSERT seat_performance OFF


go


--SET IDENTITY_INSERT actor_line OFF

insert into actor_line(actor, line) values(1, 16);
insert into actor_line(actor, line) values(2, 16);
insert into actor_line(actor, line) values(3, 15);
insert into actor_line(actor, line) values(4, 14);
insert into actor_line(actor, line) values(5, 13);
insert into actor_line(actor, line) values(6, 12);
insert into actor_line(actor, line) values(7, 11);
insert into actor_line(actor, line) values(8, 10);
insert into actor_line(actor, line) values(9, 9);
insert into actor_line(actor, line) values(10, 8);
insert into actor_line(actor, line) values(11, 7);
insert into actor_line(actor, line) values(12, 6);
insert into actor_line(actor, line) values(13, 1);
insert into actor_line(actor, line) values(14, 2);
insert into actor_line(actor, line) values(15, 3);
insert into actor_line(actor, line) values(16, 6);
insert into actor_line(actor, line) values(17, 7);
insert into actor_line(actor, line) values(18, 4);
insert into actor_line(actor, line) values(19, 5);
insert into actor_line(actor, line) values(20, 7);
insert into actor_line(actor, line) values(21, 8);
insert into actor_line(actor, line) values(22, 9);
insert into actor_line(actor, line) values(1, 10);
insert into actor_line(actor, line) values(10, 11);
insert into actor_line(actor, line) values(22, 12);
insert into actor_line(actor, line) values(5, 12);
insert into actor_line(actor, line) values(7, 14);
insert into actor_line(actor, line) values(3, 16);
insert into actor_line(actor, line) values(7, 16);
insert into actor_line(actor, line) values(2, 10);
insert into actor_line(actor, line) values(5, 7);
insert into actor_line(actor, line) values(6, 2);
insert into actor_line(actor, line) values(8, 6);
insert into actor_line(actor, line) values(9, 3);

--SET IDENTITY_INSERT actor_line OFF

use master