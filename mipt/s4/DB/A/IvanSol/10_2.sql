---����� 2
---��������� SQL-������ � ������� Customers 
--� ������������ �� �������������� ��������� � ���������� ������ �����

declare @time as datetime
set @time = GetDate()

SELECT CustomerID, city, PostalCode FROM customers
WHERE CustomerID = 'FISSA'
and city = 'Madrid'
and PostalCode = 28034 

print Convert( varchar(50), GetDate() - @time, 14)

CREATE NONCLUSTERED INDEX I2 ON customers
(customerId, city, postalcode)

declare @time as datetime
set @time = GetDate()

SELECT CustomerID, city, PostalCode FROM customers
WHERE CustomerID = 'FISSA'
and city = 'Madrid'
and PostalCode = 28034 

print Convert( varchar(50), GetDate() - @time, 14)

DROP INDEX customers.I2
