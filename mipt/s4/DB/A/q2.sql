use NWC;

drop index customers.customerIDIndex
drop index customers.customerCity
drop index orders.customerIDIndex
drop index orders.shipcityindex

create clustered index customerIDIndex on customers (customerID)
create nonclustered index customerCity on customers (customerID, city)

create clustered index customerIDIndex on orders (customerID)
create nonclustered index shipCityIndex on orders (customerID, shipCity)

select customers.customerID, customers.city, orders.shipCity from customers, orders
where customers.customerID = orders.customerID
and customers.city = N'Berlin'
and orders.shipCity = N'Berlin'