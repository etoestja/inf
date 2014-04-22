declare @dbsize int;
declare @logsize int;

select @dbsize = sum(size) from theater.sys.sysfiles
where status & 64 = 0

select @logsize = sum(size) from theater.sys.sysfiles
where status & 64 <> 0

select @dbsize, @logsize

declare @reservedpages int;

select @reservedpages = sum(a.total_pages)
from theater.sys.allocation_units a


select @reservedpages

select (@dbsize + @logsize) * 8192. / 1048576 as 'Size (MB)'
select (@dbsize - @reservedpages) * 8192 / 1048576. as 'Free (MB)'