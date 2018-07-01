# 1. Inner Join
select * from Investor;
select * from Proyek;
select * from Direktur;

select 
Investor.Nama, 
Investor.jumlah,
Proyek.Nama,
Direktur.Nama
from Investor
inner join Proyek on Investor.Proyek_id = Proyek.id
inner join Direktur on Investor.Direktur_id = Direktur.id;

# 2. Left Join
select * from Investor;
select * from Proyek;
select * from Direktur;

select 
Investor.Nama, 
Investor.jumlah,
Proyek.Nama,
Direktur.Nama
from Investor
left join Proyek on Investor.Proyek_id = Proyek.id
left join Direktur on Investor.Direktur_id = Direktur.id;

# 3. Right Join
select * from Investor;
select * from Proyek;
select * from Direktur;

select 
Investor.Nama, 
Investor.jumlah,
Proyek.Nama,
Direktur.Nama
from Investor
right join Proyek on Investor.Proyek_id = Proyek.id
right join Direktur on Investor.Direktur_id = Direktur.id;

# 4. Left Join NULL
select 
Investor.Nama, 
Investor.jumlah,
Proyek.Nama,
Direktur.Nama
from Proyek
left join Investor on Investor.Proyek_id = Proyek.id
left join Direktur on Investor.Direktur_id = Direktur.id;

# 5. Left Join Right Join
select 
Investor.Nama, 
Investor.jumlah,
Proyek.Nama,
Direktur.Nama
from Proyek
left join Investor on Investor.Proyek_id = Proyek.id
right join Direktur on Investor.Direktur_id = Direktur.id;

# 6. Inner Join Left Join
select 
Investor.Nama, 
Investor.jumlah,
Proyek.Nama,
Direktur.Nama
from Proyek
inner join Investor on Investor.Proyek_id = Proyek.id
left join Direktur on Investor.Direktur_id = Direktur.id;

# 7. Left Join Inner Join
select 
Investor.Nama, 
Investor.jumlah,
Proyek.Nama,
Direktur.Nama
from Proyek
left join Investor on Investor.Proyek_id = Proyek.id
inner join Direktur on Investor.Direktur_id = Direktur.id;

# 8. Right Join Inner Join
select 
Investor.Nama, 
Investor.jumlah,
Proyek.Nama,
Direktur.Nama
from Proyek
right join Investor on Investor.Proyek_id = Proyek.id
inner join Direktur on Investor.Direktur_id = Direktur.id;

# 9. Inner Join Right Join
select 
Investor.Nama, 
Investor.jumlah,
Proyek.Nama,
Direktur.Nama
from Proyek
inner join Investor on Investor.Proyek_id = Proyek.id
right join Direktur on Investor.Direktur_id = Direktur.id;

# Percobaan 1
select * from pegawai;
select * from departemen;

select
pegawai.Nama,
pegawai.gaji,
departemen.Nama
from pegawai
left join departemen on pegawai.Departemen_id = departemen.ID;

# Percobaan 2
select * from pegawai;
select * from departemen;

select
pegawai.Nama,
pegawai.gaji,
departemen.Nama as Departemen
from pegawai
left join departemen on pegawai.Departemen_id = null;

# Percobaan 3
select * from pegawai;
select * from departemen;

select
pegawai.Nama,
pegawai.Jabatan as lokasi,
departemen.Nama as Departemen,
pegawai.gaji as jumlah
from pegawai
left join departemen on pegawai.Departemen_id = null;

# Percobaan 4
select * from General_manager;
select * from Direktur;

select
General_manager.Nama,
General_manager.Alamat as Tempat,
Direktur.Nama,
Direktur.Tempat as alamat
from General_manager	
right join Direktur on General_manager.id_Direktur = Direktur.id;