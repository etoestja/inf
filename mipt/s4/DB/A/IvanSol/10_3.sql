--ПУНКТ 3
--Построить SQL-запрос к связанным таблицам Customers и Orders 
--с фильтрациями по нескольким полям этих таблиц

--DATABASE CONSOLE COMMAND
DBCC DROPCLEANBUFFERS
declare @time as datetime
set @time = GetDate()

SELECT C.CustomerId, C.City, O.Freight
FROM  ORDERS O
 INNER JOIN customers C on O.customerId = C.customerId
WHERE 
 C.City = 'Berlin'
 AND O.Freight < 10

print Convert( varchar(50), GetDate() - @time, 14)


CREATE NONCLUSTERED INDEX index2 ON orders
(
	customerId, Freight
)
CREATE CLUSTERED INDEX index4 ON customers
(
	CustomerId,	City
)

set @time = GetDate()

SELECT C.CustomerId, C.City, O.Freight
FROM  ORDERS O
 INNER JOIN customers C on O.customerId = C.customerId
WHERE  
 C.customerID = 'ALFKI'
 AND C.City = 'Berlin'
 AND O.Freight < 10

print Convert( varchar(50), GetDate() - @time, 14)


DROP INDEX orders.index2
DROP INDEX customers.index4

SELECT count(*) from customers
