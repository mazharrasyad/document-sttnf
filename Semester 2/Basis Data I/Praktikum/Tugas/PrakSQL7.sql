# Sub Query

# Percobaan 1
select * from Direktur;
select * from departemen;

select id_departemen from Direktur where Tanggal_lahir > 19450210;

select id, Nama from departemen where id in 
(select id_departemen from Direktur where Tanggal_lahir > 19450210);

# Percobaan 2
select * from pegawai;
select * from departemen;

# 3 Kolom
select id, Nama, gaji from pegawai where nama like 'M%';

select id, nama from departemen where id in
(select id, Nama, gaji from pegawai where nama like 'M%');

# 1 Kolom
select Departemen_id from pegawai where nama like 'M%'; 

select id, nama from departemen where id in
(select Departemen_id from pegawai where nama like 'M%');

# Percobaan 3
select id, nama, gaji from pegawai where gaji between 'Rp. 3.000.000' AND 'Rp. 7.000.000';

select * from departemen where id in 
(select Departemen_id from pegawai where gaji between 'Rp. 3.000.000' AND 'Rp. 7.000.000');

# View

# Percobaan 4
show tables;

create view dp_pg as 
select * from departemen where id in 
(select Departemen_id from pegawai where gaji between 'Rp. 3.000.000' AND 'Rp. 7.000.000');

select * from dp_pg;

# Latihan 1
select * from Direktur;
select * from Investor;

select Direktur_id from Investor where jumlah > 'Rp. 100.000.000';
select nama as Nama_dari__ from Direktur where id in
(select Direktur_id from Investor where jumlah > 'Rp. 100.000.000');

# Latihan 2
select * from departemen;
select * from pegawai;

select Departemen_id from pegawai where jabatan = 'Pegawai Teknologi';
select lokasi as lokasi_dari__ from departemen where id in
(select Departemen_id from pegawai where jabatan = 'Pegawai Teknologi');

# Latihan 3
select * from Investor;
select * from Proyek;
select * from Direktur;

select 
Investor.Nama,
Investor.jumlah,
Proyek.Nama as Proyek,
Direktur.Nama as Direktur
from Investor
inner join Proyek on Investor.Proyek_id = Proyek.id
inner join Direktur on Investor.Direktur_id = Direktur.id;

create view ES_BUAH as 
select 
Investor.Nama,
Investor.jumlah,
Proyek.Nama as Proyek,
Direktur.Nama as Direktur
from Investor
inner join Proyek on Investor.Proyek_id = Proyek.id
inner join Direktur on Investor.Direktur_id = Direktur.id;

show tables;

select * from ES_BUAH;