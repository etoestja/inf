use NWC;

create nonclustered index customerIDIndex on customers (customerID)
create nonclustered index cityIndex on customers (city)

select * from customers
where customerID > N'L'
and city < N'G'