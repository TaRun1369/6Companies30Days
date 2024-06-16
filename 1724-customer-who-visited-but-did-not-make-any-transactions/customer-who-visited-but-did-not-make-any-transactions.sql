# Write your MySQL query statement below
select v.customer_id , Count(v.customer_id) as count_no_trans
from Visits as v 
left join Transactions as tr 
on v.visit_id = tr.visit_id
where tr.visit_id is NULL
group by v.customer_id
