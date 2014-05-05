use NWC;

select * from customers
where substring(customerID, 1, 1) = N'L'
and city = N'Versailles'