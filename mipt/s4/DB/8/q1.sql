select name from theater.sys.sysobjects where uid = 1 and xtype = 'U'

go

select obj.name as [table], col.name as [column],
col.isnullable as isNullable,
typ.name as [type],
col.length as length
from theater.sys.syscolumns as col,
theater.sys.sysobjects as obj, 
theater.sys.types as typ
where obj.uid = 1 and obj.xtype = 'U' and col.id = obj.id
and typ.user_type_id = col.xusertype

go

select keys.name as [key], obj.name as [table], keys.xtype as type from theater.sys.sysobjects keys
left outer join theater.sys.sysreferences refs on (refs.constid = keys.id)
left outer join theater.sys.sysobjects obj on obj.id = keys.parent_obj
where (keys.xtype = 'PK' or keys.xtype = 'F')
and keys.uid = 1

go

select keys.name as key_name, o1.name as fkey_table, o2.name as parent_table from theater.sys.foreign_keys keys
left outer join theater.sys.objects o1 on keys.parent_object_id = o1.object_id
left outer join theater.sys.objects o2 on keys.referenced_object_id = o2.object_id
left outer join theater.sys.objects o3 on o2.parent_object_id = o3.object_id
left outer join theater.sys.sysobjects sobj on keys.object_id = sobj.id
where sobj.uid = 1

go

select v.name, m.definition from theater.sys.views v, theater.sys.sql_modules m, theater.sys.sysobjects sobj
where v.object_id = m.object_id
and sobj.id = v.object_id
and sobj.uid = 1

go

select t.name as [table], tr.name as [trigger] from theater.sys.sysobjects tr, theater.sys.sysobjects as t
where tr.xtype = 'TR'
and tr.parent_obj = t.id
and tr.uid = 1