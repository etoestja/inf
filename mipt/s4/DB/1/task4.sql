select top 5 product.description
from sales_order, product, item
where sales_order.order_id = item.order_id
and item.product_id = product.product_id
and year(sales_order.ship_date)=1989
group by product.product_id, product.description
order by sum(sales_order.total) desc