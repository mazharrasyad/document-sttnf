# Percobaan 1 : Analisis

select * from departemen;

select * from Direktur;

select * from General_manager;

select * from pegawai;

insert into pegawai values
(6,'Henry Hassan','Jakarta',19970405,'Rp. 5.000.000','L','Pegawai Kewirausahaan','089519020331',2),
(7,'Hanna Annisa','Bekasi',19950727,'Rp. 7.000.000','P','Pegawai Keuangan','085323405921',1),
(8,'Tria Handayani','Jakarta',19970810,'Rp. 8.357.000','P','Pegawai Keuangan','082106210693',1);

select * from Proyek;

select * from Investor;

# Percobaan 2 : Query of Select

# No 1 : SQL SELECT DISTINCT

select DISTINCT id,nama,jabatan from pegawai;

# No 2 : SQL SELECT WHERE

select * from departemen where lokasi = 'Jakarta';

# No 3 : SQL AND, OR dan NOT Operator

select * from Proyek where Tanggal_awal = 20180427 and Tanggal_akhir = 20180428;

select * from Proyek where Tanggal_awal = 20180427 or Tanggal_awal = 20180501;

select * from Proyek where not Tanggal_awal = 20180427;

# No 4 : SQL SELECT ORDER BY

select * from Investor order by nama desc;

# No 5 : SQL MIN () dan MAX () Fungsi

select min(jumlah) from Investor;

select max(jumlah) from Investor;

# No 6 : SQL COUNT (), AVG () dan SUM () Fungsi

select count(jumlah) from Investor;

select avg(jumlah) from Investor;

select sum(gaji) from pegawai;

# No 7 : The SQL LIKE Operator

select nama from pegawai where nama like 'M%';

select nama from pegawai where nama like '%_i';

select nama,jabatan from pegawai where jabatan like '%Keuangan%';

# No 8 : SQL BETWEEN Operator

select nama,gaji from pegawai where gaji between 'Rp. 5.000.000' and 'Rp. 7.000.000';

select * from pegawai limit 4,5;
# atau
select * from pegawai limit 5 offset 4;