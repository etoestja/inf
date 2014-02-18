select sum(sales_order.total - price.min_price * item.quantity) as s, product.description from sales_order, item, product, price
where sales_order.order_id = item.order_id
and item.product_id = product.product_id
and product.product_id = price.product_id
and year(sales_order.ship_date)=1989
group by product.product_id, product.description
order by s desc