# 1. Tampilkan rata2 total_nilai dari data peserta_diklat untuk pegawai bernama 'Sekar Mirah'
select avg(total_nilai) as rata2 from peserta_diklat where pegawai_nik = 03110780002;

# 2. Tampilkan seluruh data pegawai unit_kerja 'DJP'
select * from pegawai where unit_kerja_id = 1;

# 3. Tampilkan seluruh data dari table peserta_diklat untuk pegawai 
# dengan nik '04150186001' dan '04200576001'
select * from peserta_diklat where pegawai_nik in (04150186001, 04200576001);

#Tampilkan seluruh data peserta_diklat untuk peserta dengan nilai tertinggi untuk peldiklat_id = 1
# 4. Tampilkan seluruh data peserta_diklat untuk peserta dengan nilai tertinggi untuk peldiklat_id = 1
select * from peserta_diklat where peldiklat_id = 1 order by total_nilai desc limit 1;

# 5. Tampilkan seluruh data materi apa saja yang diajarkan di diklat 'Toefl iBT preparation'
select * from materi where diklat_id = 2;

# 6. Tampilkan seluruh data pengajar_diklat yang mengajar pada diklat 'Desain dan pengelolaan database'
select * from pengajar_diklat where peldiklat_id = 2;
select * from materi;
select * from diklat;
select * from pengajar_Sdiklat;

# 7. Dari nama2 pegawai ini: Rara Wulan,Raden Rangga dan Pandan Wangi 
# urutkan mulai dari yang memiliki nilai tertinggi untuk peldiklat_id = 1
select * from peserta_diklat where pegawai_nik in (04010188005, 04100292001, 04100781001) 
and peldiklat_id = 1 order by total_nilai desc;

# 8. Tampilkan data pengajar_diklat : id, jamlat,nilai dan grade dari nilai 
# dengan kriteria : < 80 mendapat grade C, 80-90 grade B dan 90-100 gradenya A
select id,jamlat,nilai,
if(nilai < 80, 'C',
if(nilai < 90, 'B','A')) as grade
from pengajar_diklat;

# 9. Tampilkan seluruh data peserta_diklat yang mengikuti diklat 'Desain dan pengelolaan database'
select * from peserta_diklat where peldiklat_id = 2;

# 10. Dari table pengajar_diklat tampilkan 2 data yang mendapat nilai tertinggi
select * from pengajar_diklat order by nilai desc limit 2;
