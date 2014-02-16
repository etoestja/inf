select top 5 sum(sales_order.total),product.product_id from sales_order, product, item
where sales_order.order_id = item.order_id
and item.product_id = product.product_id
and year(sales_order.ship_date)=1989
group by product.product_id
order by sum(sales_order.total) desc