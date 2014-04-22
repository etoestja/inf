select typ.name, col.name from theater.sys.syscolumns as col, theater.sys.types as typ
where typ.user_type_id = col.xusertype
select * from theater.sys.types
select * from theater.sys.syscolumns
select * from theater.sys.sysobjects
select * from theater.sys.sysreferences
select k.name, o.name, o1.name from theater.sys.foreign_keys as k, theater.sys.objects as o, theater.sys.objects as o1
where k.parent_object_id = o.object_id
and k.referenced_object_id = o1.object_id
select * from theater.sys.foreign_key_columns where 

select keys.name as key_name, o1.name as fkey_table, o2.name as parent_table from theater.sys.foreign_keys keys
left outer join theater.sys.objects o1 on keys.parent_object_id = o1.object_id
left outer join theater.sys.objects o2 on keys.referenced_object_id = o2.object_id
left outer join theater.sys.objects o3 on o2.parent_object_id = o3.object_id
left outer join theater.sys.sysobjects sobj on keys.object_id = sobj.id
where sobj.uid = 1

select v.name, m.definition from theater.sys.views v, theater.sys.sql_modules m, theater.sys.sysobjects sobj
where v.object_id = m.object_id
and sobj.id = v.object_id
and sobj.uid = 1

select t.name as [table], tr.name as [trigger] from theater.sys.sysobjects tr, theater.sys.sysobjects as t
where tr.xtype = 'TR'
and tr.parent_obj = t.id
and tr.uid = 1

select * from sys.roles

SELECT SCHEMA_NAME(schema_id) AS schema_name
    ,o.name AS object_name
    ,o.type_desc
    ,p.parameter_id
    ,p.name AS parameter_name
    ,TYPE_NAME(p.user_type_id) AS parameter_type
    ,p.max_length
    ,p.precision
    ,p.scale
    ,p.is_output
FROM sys.objects AS o
INNER JOIN sys.parameters AS p ON o.object_id = p.object_id
--WHERE o.object_id = OBJECT_ID('<schema_name.object_name>')
ORDER BY schema_name, o.name, p.parameter_id;