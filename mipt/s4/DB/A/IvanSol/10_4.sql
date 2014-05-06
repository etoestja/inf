--ПУНКТ 4
--Построить SQL-запрос ко всем 4-м связанным таблицам Customers, Orders, OrderDetails и Products 
--с фильтрациями по нескольким полям этих таблиц.
select ord.orderid, cu.customerid,cu.city, pro.productid
from customers cu 
inner join orders ord on ord.customerid=cu.customerid 
inner join orderdetails orde on orde.orderid=ord.orderid
inner join products pro on orde.productid=pro.productid
where ( cu.customerid = 'QUEEN' 
	and cu.city='Sao Paulo' 
	and pro.ProductID between 1 and 10) 

CREATE NONCLUSTERED INDEX [index10] ON [dbo].[orders]
(
	[customerid], [orderid]
)


CREATE NONCLUSTERED INDEX [index20] ON [dbo].[customers]
(
	[customerid], [city]
)

CREATE NONCLUSTERED INDEX index30 ON [dbo].[products]
(
	[productid] ASC
)

CREATE NONCLUSTERED INDEX index40 ON [dbo].[orderdetails]
(
	[productid], [orderid]
)

select ord.orderid, cu.customerid,cu.city, pro.productid
from customers cu 
inner join orders ord on ord.customerid=cu.customerid 
inner join orderdetails orde on orde.orderid=ord.orderid
inner join products pro on orde.productid=pro.productid
where ( cu.customerid = 'QUEEN' 
	and cu.city='Sao Paulo' 
	and pro.ProductID between 1 and 10) 


drop index orders.index10
drop INDEX customers.index20
drop index products.index30
drop INDEX orderdetails.index40
