select year(order_date) as Y,
month(order_date) as M,
avg(total) as A
from sales_order
group by month(order_date), year(order_date)