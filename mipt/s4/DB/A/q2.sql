use NWC;

create clustered index customerIDIndex on customers (customerID)
create nonclustered index customerCity on customers (city)

create clustered index customerIDIndex on orders (customerID)
create nonclustered index shipCityInex on orders (shipCity)

select * from customers, orders
where customers.customerID = orders.customerID
and customers.city = N'Berlin'
and orders.shipCity = N'Berlin'