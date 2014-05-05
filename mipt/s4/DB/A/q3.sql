use NWC;

create clustered index orderID on orders (orderID)
create nonclustered index customerID on orders (customerID)
create nonclustered index employeeID on orders (employeeID)
create nonclustered index shipVia on orders (shipVia)

create clustered index orderID on orderDetails (orderID)
create nonclustered index productID on orderDetails (productID)

create clustered index productID on products (productID)

create clustered index customerID on customers (customerID)

select * from orders, products, customers, orderDetails
where orders.customerID = customers.customerID
and orders.orderID = orderDetails.orderID
and orderDetails.productID = products.productID
and customers.customerID > N'N'
and employeeID = 9
and shipVia = 2