use NWC;

select * from customers, orders
where customers.customerID = orders.customerID
and customers.city = N'Berlin'
and orders.ShipCity = N'Berlin'