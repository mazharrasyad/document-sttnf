# No 1
select nama_barang,jumlah from barang;

# No 2
select nama_barang from barang where nama_barang like '%e';

# No 3
select nama_barang from barang order by nama_barang desc;

# No 4
select * from barang where kd_jenis = 5;

# No 5
select * from barang limit 5,3;

# No 6
select * from barang limit 1,5;
# atau
select * from barang limit 5 offset 1;

# No 7
select DISTINCT kd_suplier from barang;
# atau
select DISTINCT kd_suplier from distributor;

# No 8
select * from barang limit 3,7;
# atau
select * from barang limit 7 offset 3;

# No 9
select avg(harga) from barang;

# No 10
select * from barang limit 4,5;
# atau
select * from barang limit 5 offset 4;

select * from barang where harga between 4500 and 18000;