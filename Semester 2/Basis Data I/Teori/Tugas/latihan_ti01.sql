# menampilkan data unit kerja
select * from unit_kerja;

# menampilkan data unit kerja
select * from pegawai;

# Tampilkan seluruh data table unit_kerja diurutkan berdasarkan budget mulai dari terkecil
SELECT * FROM unit_kerja ORDER BY budget;

# Tampilkan data kode,nama dan budget dari table unit_kerja
SELECT kode,nama,budget FROM unit_kerja;

# Tampilkan seluruh data pegawai diurutkan berdasarkan nama dari secara descending
SELECT * FROM pegawai ORDER BY nama DESC;

# Tampilkan nik,nama dan email dari table pegawai
SELECT nik,nama,email FROM pegawai; 

# Tampilkan seluruh data unit_kerja yang memiliki kode “DJPU”
SELECT * FROM unit_kerja WHERE kode='DJPU';

# Tampilkan data kode,nama,budget dari table unit_kerja yang budgetnya diatas 3ribu
SELECT kode,nama,budget FROM unit_kerja WHERE budget > 3000;

# Tampilkan seluruh data pegawai perempuan
SELECT * FROM pegawai WHERE gender = 'P';

# Tampilkan nik,nama dan tempat lahir dari table pegawai yang lahirnya bukan di Jakarta
SELECT nik,nama,tmp_lahir FROM pegawai WHERE tmp_lahir <> 'Jakarta';

# Tampilkan seluruh data unit kerja yang budgetnya diatas 500 dan kurang dari 3200
select * from unit_kerja where budget > 500 and budget < 3200;

# Tampilkan data unit kerja yang kodenya 'DJP' atau 'DJBC'
select * from unit_kerja where kode='DJP' or kode='DJBC';

# Soal 1

# 1. Tampilkan data unit_kerja yang idnya 3 dan 4
select * from unit_kerja where id = 3 or id = 4;

# 2. Tampilkan data unit_kerja yang budgetnya kurang dari 3000 tetapi lebih dari 500
select * from unit_kerja where budget < 3000 and budget > 500;

# 3. Tampilkan data pegawai yang tmp_lahirnya di kota Klaten dan Solo
select * from pegawai where tmp_lahir = 'Klaten' or tmp_lahir = 'Solo';

# 4. Tampilkan data pegawai mulai dari yang paling muda
select * from pegawai order by tgl_lahir desc;

# 5. Tampilkan pegawai yang lahirnya di Jakarta dan gendernya Laki-laki
select * from pegawai where tmp_lahir = 'Jakarta' and gender = 'L';

# 6. Tampilkan pegawai yang nik-nya 03110780002, 04100781001,04200788001
select * from pegawai where nik = '03110780002' or nik = '04100781001' or nik = '04200788001';

select * from pegawai where nik in('03110780002','04100781001','04200788001');

# Klausa IN dan NOT IN

# Tampilkan data unit_kerja yang ID-nya 1, 3 dan 4 : {1,3,4}
select * from unit_kerja where id in (1,3,4);

# Tampilkan data pegawai yg lahir nya bukan di jakarta dan yogyakarta
select * from pegawai where tmp_lahir not in ('Jakarta','Yogyakarta');

# Operator SQL

# Tampilkan hasil perkalian 5 x 5
select 5 * 5 as '5 x 5 =';

# Tampilkan data unit kerja jika budgetnya dinaikkan 30% dari budget semula
select kode,nama,budget as budget_awal, budget * 0.3 + budget as budget_akhir from unit_kerja;

# Fungsi Waktu

# Tampilkan nama dan tahun lahir pegawai
select nama,year(tgl_lahir) as tahun_lahir from pegawai;

# Tampilkan bulan saat ini
select month(current_date) as bulan;

# Klausa Between

# Tampilkan data unit kerja yang mempunyai budget antara 500 sampai 3000
select * from unit_kerja where budget between 500 and 3000;

# Soal 2

# 1. Tampilkan data pegawai yang lahirnya antara tahun 1980 sampai 1990
select * from pegawai where year(tgl_lahir) between 1980 and 1990;

# 2. Tampilkan data pegawai yang lahirnya tahun 1988
select * from pegawai where year(tgl_lahir) = 1988;

# 3. Tampilkan data pegawai yang bulan juli berulang tahun
select * from pegawai where month(tgl_lahir) = 07;

# 4. Tampilkan data pegawai : nama,tmp_lahir,tgl_lahir dan umur (selisih tahun sekarang dikurang tahun kelahiran)
select nama,tmp_lahir,tgl_lahir,year(current_date) - year(tgl_lahir) as umur from pegawai;

# 5. Tampilkan unit_kerja yang idnya antara 2 s.d 4
select * from unit_kerja where id between 2 and 4;

# Like dan Not Like

# Tampilkan data pegawai yang namanya berawal 'S'
select * from pegawai where nama like 's%';

# Tampilkan data pegawai yang namanya memiliki akhiran 'an'
select * from pegawai where nama like '%an';

# Tampilkan data pegawai yang namanya memiliki suku kata 'ra'
select * from pegawai where nama like '%ra%';

# Soal 3

# 1. Tampilkan pegawai yang nama awalnya huruf R dan huruf A
select * from pegawai where nama like 'R%' OR nama like 'A%';

# 2. Tampilkan pegawai yang nik awalnya bukan huruf ’04’
select * from pegawai where nik not like '04%';

# 3. Tampilkan data unit_kerja yang kode awalnya ‘DJ’
select * from unit_kerja where kode like 'DJ%';

# 4. Tampilkan pegawai yang kota kelahirannya mengandung huruf ‘ta'
select * from pegawai where tmp_lahir like '%ta%';

# 5. Tampilkan pegawai yang emailnya yahoo
select * from pegawai where email like '%yahoo%';

# 6. Tampilkan pegawai yang emailnya bukan gmail
select * from pegawai where email not like '%gmail%';

# 7. Tampilkan pegawai yang lahirnya bukan di Jakarta dan namanya mengandung huruf ‘ra‘
select * from pegawai where tmp_lahir not like '%Jakarta%' and nama like '%ra%';
select * from pegawai where tmp_lahir <> 'Jakarta' and nama like '%ra%';

# 8. Tampilkan pegawai yang karakter huruf ke – 2 dari NIK nya adalah 3
select * from pegawai where nik like '03%';
select * from pegawai where nik like '_3%';
select * from pegawai where left(nik,2)='03';

# Klausa Limit dan Offset
select * from pegawai order by nama;

# Tampilkan 3 data pertama dari table pegawai
select * from pegawai order by nama limit 3;

# Tampilkan 3 data pegawai dimulai dari data ke 3
select * from pegawai order by nama limit 3 offset 2;

# Soal 4

# 1. Tampilkan 2 data unit_kerja dengan budget terbesar
select * from unit_kerja order by budget desc limit 2;

# 2. Tampilkan unit_kerja dengan budget yang paling rendah
select * from unit_kerja order by budget limit 1;

# 3. Tampilkan 3 data pegawai diurutkan berdasarkan nama secara descending
select * from pegawai order by nama desc limit 3;

# 4. Tampikan 2 data pegawai diurutkan berdasarkan tempat lahir pegawai secara ascending
select * from pegawai order by tmp_lahir limit 2;

# 5. Tampilkan pegawai yang paling muda
select * from pegawai order by tgl_lahir desc limit 1;

# 6. Tampilkan pegawai yang paling tua
select * from pegawai order by tgl_lahir limit 1;

# Fungsi Aggregate

# Ada berapa jumlah data pegawai
select count(nik) as jml_pegawai from pegawai;

# Berapa rata-rata budget unit_kerja
select avg(budget) as rata2_budget from unit_kerja;

# Klausa Distinct
select tmp_lahir from pegawai;

# Tampilkan kota-kota tempat kelahiran pegawai
select distinct(tmp_lahir) as kota_kelahiran from pegawai;

# Soal 5

# 1. Berapa jumlah pegawai yang tahun lahirnya 1988
select count(nik) as jumlah_pegawai from pegawai where year(tgl_lahir) = 1988;

# 2. Berapa jumlah pegawai perempuan yang tempat lahirnya di Yogyakarta
select count(nik) as jumlah_pegawai from pegawai where gender = 'P' and tmp_lahir = 'Yogyakarta';

# 3. Berapa jumlah total budget semua unit_kerja yang ID nya 2 dan 4
select sum(budget) as jumlah_budget from unit_kerja where id in(2,4);
select sum(budget) as jumlah_budget from unit_kerja where id = 2 or id = 4;

# 4. Ada berapa pegawai yang mempunyai NIK awal 04
select count(nik) as jumlah_pegawai from pegawai where nik like '_4%';
select count(nik) as jumlah_pegawai from pegawai where nik like '04%';

# 5. Berapa budget rata-rata unit_kerja yang diatas 500
select avg(budget) as rata2_budget from unit_kerja where budget > 500;

# 6. Ada berapa pegawai yang emailnya menggunakan gmail
select count(nik) as jumlah_pegawai from pegawai where email like '%gmail%';

# 7. Ada berapa pegawai yang lahirnya di kota Yogyakarta
select count(nik) as jumlah_pegawai from pegawai where tmp_lahir like '%Yogyakarta%';

# 8. Berapa rata-rata umur pegawai
select avg(year(current_date)-year(tgl_lahir)) as rata2_umur from pegawai;

# Case
# Contoh
select case 1
	when 1 then 'satu'
	when 2 then 'dua'
    else 'lainnya'
end as contoh;

# Tampilkan data jenis kelamin pegawai: L => 'Laki-laki', P => 'Perempuan'
select nama, 
	case(gender) 
	when 'L' then 'Laki-laki' 
    else 'Perempuan' 
	end as jenis_kelamin 
from pegawai;

# IF(kondisi, jika benar, jika salah)
# Tampilkan status budget unit kerja jika minimal 3ribu dikatakan besar dan sebaliknya kecil
select id, kode, nama, budget, if(budget >= 3000, 'Besar', 'Kecil') as status from unit_kerja;

# IF NULL
# contoh
select ifnull(1,0);
select ifnull('Kosong',0);

# Soal 6

# 1. Tampilkan data pegawai : nik,nama,tmp_lahir dengan 
# informasi gender jika 'L' cetak Laki-Laki dan jika 'P' cetak Perempuan
select nama, 
	case(gender) 
	when 'L' then 'Laki-laki' 
	else 'Perempuan' 
	end as jenis_kelamin 
from pegawai;

# 2. Tampilkan data pegawai : nik,nama,umur, dan 
# kategori umur jika umur < 17 -> 'Remaja', 17-30 -> 'Muda', selainnya 'Dewasa'
select nik, nama, (year(current_date)-year(tgl_lahir)) as umur, 
if(year(current_date)-year(tgl_lahir) < 17, 'Remaja', 
if(year(current_date)-year(tgl_lahir) <= 30, 'Muda','Dewasa')) 
as kategori_umur from pegawai;

# 3. Tampilkan data pegawai : nik,nama,tmp_lahir, dan 
# status_pegawai untuk awal nik '03' -> 'Pusat', '04' -> 'Daerah' selain dari diatas 'Tidak Ada'
select nik, nama, tmp_lahir, 
	case(left(nik,2)) 
	when '03' then 'Pusat'
	when '04' then 'Daerah' 
    else 'Tidak Ada' 
    end as status_pegawai 
from pegawai;

# Group By
# Tampilkan statistik jumlah pegawai berdasarkan gender
select gender, count(*) as jumlah from pegawai group by gender;

# Tampilkan data statistik jumlah tempat lahir pegawai
select tmp_lahir, count(*) as jumlah from pegawai group by tmp_lahir;

# Tampilkan jumlah statistik pegawai yang memiliki email @gmail dan @yahoo
select 
	case right(email,9) 
    when 'gmail.com' then 'GMail' 
    else 'Yahoo' 
    end as email_peg, 
count(*) as jumlah from pegawai group by email_peg;

# Soal 7

# 1. Tampilkan data unit_kerja dengan budget dipotong 50%
select budget as budget_awal, budget - (budget * 0.5) as budget_akhir 
from unit_kerja group by budget_akhir;

# 2. Tampilkan usia masing-masing pegawai
select year(current_date)-year(tgl_lahir) as usia from pegawai group by usia;

# 3. Tampilkan rata-rata usia dari pegawai
select avg(year(current_date)-year(tgl_lahir)) as rata2_usia from pegawai;

# 4. Tampilkan total budget unit_kerja jika budget dipotong 40%
select kode, nama, budget - (budget * 0.4) as budget from unit_kerja;

# Update
select * from pegawai;
UPDATE pegawai SET nama='Annisa Pohan' WHERE nik='04200788001';
UPDATE pegawai SET tmp_lahir ='DIY Yogyakarta' WHERE nik in ('03101179001','03110780002');

# Delete
DELETE FROM pegawai WHERE nik='04200576001';