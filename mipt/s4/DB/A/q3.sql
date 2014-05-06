use NWC;

drop index i1 on orders
drop index i2 on orders
drop index i3 on orders

drop index i4 on orderdetails
drop index i5 on orderdetails
drop index i6 on orderdetails

drop index i7 on products
drop index i8 on products
drop index i9 on products

drop index i10 on customers

create clustered index i1 on orders (orderID)
create nonclustered index i2 on orders (orderID, customerID)
create nonclustered index i3 on orders (customerID)

create clustered index i4 on orderDetails (orderID)
create nonclustered index i5 on orderDetails (orderID, productID)
create nonclustered index i6 on orderDetails (productID)

create clustered index i7 on products (productID)
create nonclustered index i8 on products (productID, unitPrice)
create nonclustered index i9 on products (unitPrice)

create nonclustered index i10 on customers (customerID)

select customers.customerID from orders, products, customers, orderDetails
where orders.customerID = customers.customerID
and orders.orderID = orderDetails.orderID
and orderDetails.productID = products.productID
and customers.customerID = N'WELLI'
and products.unitPrice = 13