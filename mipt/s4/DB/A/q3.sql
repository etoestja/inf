use NWC;

select * from orders, products, customers, orderDetails
where orders.customerID = customers.customerID
and orders.orderID = orderDetails.orderID
and orderDetails.productID = products.productID
and substring(customers.customerID, 1, 1) = N'R'
and employeeID = 9
and shipVia = 2