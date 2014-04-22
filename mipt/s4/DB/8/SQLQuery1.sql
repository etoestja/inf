--select * from theater.sys.objects
select o.name, c.name from theater.sys.objects o, theater.sys.columns c 
where o.object_id = c.object_id