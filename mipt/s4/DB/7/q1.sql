exec sp_revokedbaccess 'test'
go

exec sp_droplogin test

go

exec sp_addlogin @loginame = 'test', @passwd = 'czflamfqbm'

go

exec sp_grantdbaccess 'test'

go

use theater;
grant select, insert, update, delete on actor to test;
grant select (description), update (description) on gender to test;
grant select on play to test;
grant select, insert, update, delete on view1 to test;

go
exec sp_droprole role1
go

exec sp_addrole role1

go

grant update (line) on view2 to role1

go

exec sp_addrolemember role1, test
--exec sp_droprolemember