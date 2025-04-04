# Write your MySQL query statement below
select product_name, sum(unit) as unit
from Orders left outer join Products
on Orders.product_id = Products.product_id
where order_date like '2020-02-%'
group by Orders.product_id
having unit >=100;