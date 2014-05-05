use NWC;

drop index customers.index1
drop index customers.index2
create clustered index index1 on customers (customerID)
create nonclustered index index2 on customers (customerID, city)
--create nonclustered index cityIndex on customers (city)

select customerID, city from customers
where customerID >= N'G'
and customerID <= N'H'
and city < N'C'