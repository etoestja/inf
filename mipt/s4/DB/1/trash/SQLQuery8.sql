select count(*),product.product_id from product, price
where
product.product_id = price.product_id
group by product.product_id