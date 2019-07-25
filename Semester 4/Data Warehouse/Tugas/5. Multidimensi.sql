|    Customer    |   Product   |      Orders    |          OrderItem             |
----------------------------------------------------------------------------------
| City | Country | ProductName | month(OrderDate) | year | sum(UnitPrice * Quantity) | sum(Quantity) |

select 
c.City,
c.Country,
p.ProductName,
month(o.OrderDate) as Bulan,
year(o.OrderDate) as Tahun,
sum(i.UnitPrice * i.Quantity) as Total_Harga,
sum(i.Quantity) as Jumlah
from product p
inner join orderitem i on p.Id = i.ProductId
inner join orders o on o.Id = i.OrderId
inner join customer c on c.Id = o.CustomerId
group by 
c.City,
c.Country,
p.ProductName,
month(o.OrderDate),
year(o.OrderDate);

create or replace view vw_produk_transaksi_kota_customer as
select 
c.City,
c.Country,
p.ProductName,
month(o.OrderDate) as Bulan,
year(o.OrderDate) as Tahun,
sum(i.UnitPrice * i.Quantity) as Total_Harga,
sum(i.Quantity) as Jumlah
from product p
inner join orderitem i on p.Id = i.ProductId
inner join orders o on o.Id = i.OrderId
inner join customer c on c.Id = o.CustomerId
group by 
c.City,
c.Country,
p.ProductName,
month(o.OrderDate),
year(o.OrderDate);

select * from vw_produk_transaksi_kota_customer limit 5;
select * from vw_produk_transaksi_kota_customer where ProductName = "Konbu";