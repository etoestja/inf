select T1.description, T1.s, T1.rn from
(select
	T.*, dense_rank() over(order by T.s desc) as 
	from
		(select sum(sales_order.total - price.min_price * item.quantity) as s, product.description
			from sales_order, item, product, price

			where sales_order.order_id = item.order_id
			and item.product_id = product.product_id
			and product.product_id = price.product_id
			and year(sales_order.ship_date)=1989
			and sales_order.ship_date >= price.start_date
			and sales_order.ship_date <= price.end_date
			group by product.product_id, product.description
		) as T
) as T1
where T1.rn <= 5
order by T1.s desc