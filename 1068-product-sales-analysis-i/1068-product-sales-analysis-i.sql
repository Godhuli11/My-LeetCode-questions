# Write your MySQL query statement below

select a.product_name , b.year , b.price from 
Sales as b , Product as a 
where a.product_id = b.product_id;