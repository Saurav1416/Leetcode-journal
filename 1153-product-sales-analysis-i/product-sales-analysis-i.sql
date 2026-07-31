# Write your MySQL query statement below


select s.year,s.price,p.product_name 
from Sales s 
inner join Product p 
on  s.product_id = p.product_id;
