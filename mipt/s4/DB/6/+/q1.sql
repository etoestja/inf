use theater;

update actor set name_middle = N'N12' where id = 2

select @@TRANCOUNT

begin transaction Out

update actor set name_middle = N'N13' where id = 2

--exec test1

begin try
		exec test1 
end try
begin catch
end catch

--commit

--select * from actor where id=2