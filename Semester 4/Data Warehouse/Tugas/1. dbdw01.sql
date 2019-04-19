-- Test Query

select * from Customer;

select FirstName, LastName, City from Customer;

select Id, FirstName, LastName, City, Country, Phone from Customer where Country = 'Sweden';

select CompanyName, ContactName, City, Country from Supplier order by CompanyName;

select CompanyName, ContactName, City, Country from Supplier order by CompanyName desc;

select Id, CompanyName, City, Country from Supplier where Country in ('USA', 'Japan', 'Germany') order by Country asc, CompanyName desc;

select distinct Country from Supplier order by Country;

select count(Id), Country from Customer group by Country having count(Id) > 10;

select count(Id), Country from Customer where Country <> 'USA' group by Country having count(Id) >= 9 order by count(Id) desc;

select avg(TotalAmount), FirstName, LastName from Orders O join Customer C on O.CustomerId = C.Id group by FirstName, LastName having avg(TotalAmount) between 1000 and 1200;

select count(C.Id) as TotalCustomers, C.Country as nation from Customer C group by C.Country;

select C.Id as Identifier, C.LastName + ', ' + C.FirstName as CustomerName, sum(O.TotalAmount) as TotalSpent from Orders O join Customer C on O.CustomerId = C.id group by C.id, C.LastName + ', ' + C.FirstName order by TotalSpent desc;

-- Join Table: 2 Table

select OrderNumber, TotalAmount, FirstName, LastName, City, Country 
from Customer join Orders 
on Orders.CustomerId = Customer.Id;

-- Join table: 3 table
-- list all orders with product names, quantities, and prices

select o.OrderNumber, convert(o.OrderDate, date) as Date, p.ProductName, i.Quantity, i.UnitPrice 
from Orders o 
join OrderItem i on o.Id = i.OrderID
join Product p on p.Id = i.ProductId
order by o.OrderNumber;

-- Left Join
-- list all customers, whether they place any order or not

select OrderNumber, TotalAmount, FirstName, LastName, City, Country
from Customer c 
left join Orders o on o.CustomerId = c.Id
order by TotalAmount;

-- Right Join
-- list customers that have not placed orders

select TotalAmount, FirstName, LastName, City, Country
from Orders o
right join Customer c on o.CustomerId = c.Id
where TotalAmount is null;

-- Self Join
-- list customers that are from the same city and country

select 
a.FirstName as FirstName1, a.LastName as LastName1, 
b.FirstName as FirstName2, b.LastName as LastName2,
a.City, a.Country
from Customer a, Customer b
where a.Id <> b.Id and a.City = b.City
and a.Country = b.Country order by a.Country;

-- Union Join
-- list all contact, i.e, supplier and customers

select 'Customer' as Type, 
	concat(FirstName, ' ', LastName) as ContactName, City, Country, Phone 
from Customer
union
select 'Supplier' as Type, 
	ContactName, City, Country, Phone 
from Supplier;

-- Sub Query
-- list products with order quantities greater than 100

select ProductName from Product
where Id in (select ProductId from OrderItem
where Quantity > 100);

-- Where ANY
-- list products were sold by the unit (i.e. quantity = 1)

select ProductName from Product
where Id = any(select ProductId from OrderItem where Quantity = 1);

-- Where All
-- list customers who placed orders that are larger than the average of each customers order

select distinct concat(FirstName, ' ', LastName) as CustomerName 
from Customer, Orders
where Customer.Id = Orders.CustomerId and TotalAmount > all
(select avg(TotalAmount) from Orders group by CustomerId);

-- Where Exist
-- find supplier with products over $100

select CompanyName from Supplier where exists
(select ProductName from Product where SupplierId = Supplier.Id and UnitPrice > 100);

-- Select Into
-- copy all suppliers from USA to a new SupplierUSA table

create table SupplierUSA select * from Supplier where Country = 'USA';
select * from SupplierUSA;

-- '' untuk auto increment
select '', 
date_add(OrderDate, interval 25 day), 
OrderNumber + 1000,
CustomerId,
TotalAmount + 20.3
from Orders 
where month(OrderDate) = 3;

-- Bulan April
insert into Orders(OrderDate,OrderNumber,CustomerId,TotalAmount)
select
date_add(OrderDate, interval 25 day), 
OrderNumber + 1000,
CustomerId,
TotalAmount + 20.3
from Orders 
where month(OrderDate) = 3;

-- Bulan Mei
insert into Orders (OrderDate,OrderNumber,CustomerId,TotalAmount)
select 
date_add(OrderDate, interval 65 day), 
OrderNumber + 2000,
CustomerId,
TotalAmount - 12.3
from Orders 
where month(OrderDate) = 3;

select * from Orders;
select distinct(month(OrderDate)) as Bulan from Orders where year(OrderDate) = 2019;


-- 1. Laporan statistik pesanan customer berdasarkan asal negara setiap bulannya, pada tahun 2019
create or replace view vw_laporan_pesanan as 
select
C.Country as Negara, 
month(O.OrderDate) as Bulan, 
year(O.OrderDate) as Tahun,
count(O.Id) as Jumlah, 
max(O.TotalAmount) as Max,
min(O.TotalAmount) as Min,
avg(O.TotalAmount) as AVG
from Customer C
inner join Orders O on O.CustomerId = C.Id
group by 
C.Country, 
month(O.OrderDate),
year(O.OrderDate)
order by 
C.Country, 
year(O.OrderDate),
month(O.OrderDate);

select * from vw_laporan_pesanan;
select * from vw_laporan_pesanan where Negara = 'Sweden';

-- Group By untuk mengurutkan berdasarkan negara, bulan, dan tahun

create database dbdwmaster;
create table dbdwmaster.laporan_pesanan select * from vw_laporan_pesanan;
select * from dbdwmaster.laporan_pesanan;