-- 1
select * from properties natural join posts where property_type='House' and construction_date > '2000-01-01'
 and post_status='Active' and mode='Rent' and city = 'Suburbia';

-- 2
SELECT house_number,street,city,state,zip_code from properties,posts where posts.property_id = properties.property_id
 and posts.post_status = 'Active' and posts.price >= 3000000 and posts.price <= 5000000;

-- 3
select house_number,street,city,state,zip_code from properties natural join posts where property_type='House' and 
post_status='Active' and mode='Rent' and city='Beachtown';

-- 4
with total_sales(agent_id, total) as (select agent_id, sum(price) from posts group by agent_id)
select accountname, total from users inner join total_sales on users.username=total_sales.agent_id 
where total = (select max(total) from total_sales);

-- 5
select p.agent_id, avg(price), avg(datediff(sale_date, post_date))  from posts p natural join sales 
where sale_date >= '2022-01-01' and sale_date <= '2022-12-31'  group by agent_id;


select p.property_id, avg(price), avg(datediff(sale_date, post_date))  from posts p natural join sales 
where sale_date >= '2022-01-01' and sale_date <= '2022-12-31'  group by property_id;

-- 6
select properties.* , price from posts natural join properties where price = (select max(price) from posts 
natural join properties where property_type = 'House'); 

with countSold(agent_id,sold) as (select agent_id,count(*) from sales natural join posts where mode="SALE" group by agent_id)
select posts.agent_id,sold,count(*),avg(price),avg(datediff(sale_date, post_date)) from sales join posts on sales.post_id=posts.post_id join users on posts.agent_id=users.username
join countSold on countSold.agent_id=posts.agent_id group by posts.agent_id;
 