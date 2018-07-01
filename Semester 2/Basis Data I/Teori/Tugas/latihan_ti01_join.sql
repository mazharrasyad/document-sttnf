# JOIN TABLE

# Inner Join

# Menampilkan data materi beserta nama diklatnya
select materi.id, materi.nama, materi.deskripsi, diklat.nama as diklat from materi
inner join diklat on materi.diklat_id = diklat.id;

select a.id, a.nama, a.deskripsi, b.nama as diklat from materi a
inner join diklat b on a.diklat_id = b.id;

# Menampilkan data pegawai dengan nama unit kerjanya	
select pegawai.nik, pegawai.nama, unit_kerja.id as unit_kerja_id from pegawai
inner join unit_kerja on pegawai.unit_kerja_id = unit_kerja.id;

select p.nik, p.nama, u.nama as unit_kerja from pegawai p
inner join unit_kerja u on p.unit_kerja_id = u.id;

select id, kode, nama from unit_kerja;

# Left Join
select diklat.id, diklat.nama as diklat, materi.nama as materi from diklat 
left join materi on diklat.id = materi.diklat_id;

# Right Join
select diklat.id, diklat.nama as diklat, materi.nama as materi from diklat 
right join materi on diklat.id = materi.diklat_id;

# Soal 8

# 1. Tampilkan data pengajar_diklat lengkap dengan relasi data nama pengajar, 
# nama diklat dan nama materi yang diajarkan
select 
narasumber.nama as nama_pengajar, 
diklat.nama as nama_diklat, 
materi.nama as nama_materi 
from pengajar_diklat
inner join narasumber on pengajar_diklat.narasumber_id = narasumber.id
inner join diklat on pengajar_diklat.peldiklat_id = diklat.id
inner join materi on pengajar_diklat.materi_id = materi.id;

# 2. Tampilkan data peserta_diklat lengkap dengan relasi data nama pegawai dan nama diklat yang diikuti
select * from peserta_diklat;
select * from pegawai;
select * from diklat;

select 
pegawai.nama as nama_pegawai, 
diklat.nama as nama_diklat 
from peserta_diklat
inner join pegawai on peserta_diklat.pegawai_nik = pegawai.nik
inner join diklat on peserta_diklat.peldiklat_id = diklat.id;

# 3. Tampilkan data absensi_diklat lengkap dengan relasi data nama pegawai dan nama diklat yang diikuti, 
# ganti nilai sesi_1 dan sesi_2 jika 1 : hadir, jika 0 : tidak hadir
select * from absensi_diklat;
select * from pegawai;
select * from diklat;

select 
pegawai.nama as nama_pegawai, 
diklat.nama as nama_diklat,
if(sesi_1 = 1, 'Hadir', 'Tidak Hadir') as sesi_1,
if(sesi_2 = 1, 'Hadir', 'Tidak Hadir') as sesi_2
from absensi_diklat
inner join pegawai on absensi_diklat.pegawai_nik = pegawai.nik
inner join diklat on absensi_diklat.peldiklat_id = diklat.id;

# Sub Query

select narasumber_id from pengajar_diklat where nilai > 85;
select id, nama from narasumber where id in (select narasumber_id from pengajar_diklat where nilai > 85);

# Soal 9

# 1. Tampilkan nama dan tmp_lahir data peserta_diklat yang mendapat total_nilai diatas 90
select pegawai_nik from peserta_diklat where total_nilai > 90;

select nama, tmp_lahir from pegawai where nik in 
(select pegawai_nik from peserta_diklat where total_nilai > 90);

# 2. Tampilkan seluruh data dari table peserta_diklat yang rata2nya total_nilainya diatas 85
select pegawai_nik from peserta_diklat where total_nilai > 85;

select * from pegawai where nik in 
(select pegawai_nik from peserta_diklat where total_nilai > 85);

# 3. Tampilkan seluruh data dari table peserta_diklat desain dan pengelolaan database yang rata2nya 
# total_nilainya dibawah 85
select pegawai_nik from peserta_diklat where peldiklat_id = 3 and total_nilai < 85;

select * from pegawai where nik in 
(select pegawai_nik from peserta_diklat where peldiklat_id = 3 and total_nilai < 85);

# 4. Tampilkan data pegawai yang mengikuti diklat dan dinyatakan tidak lulus
select pegawai_nik from peserta_diklat where status = 'Tidak Lulus';

select * from pegawai where nik in
(select pegawai_nik from peserta_diklat where status = 'Tidak Lulus');

# 5. Tampilkan data pegawai yang mengikuti diklat Kearsipan dinas dengan nilai diatas 85
select pegawai_nik from peserta_diklat where peldiklat_id = 1 and total_nilai > 85;

select * from pegawai where nik in
(select pegawai_nik from peserta_diklat where peldiklat_id = 1 and total_nilai > 85);

# View

CREATE VIEW vw_pegawai_unitkerja 
AS SELECT a.*,b.nama as unit_kerja FROM pegawai a 
INNER JOIN unit_kerja b ON a.unit_kerja_id=b.id;

CREATE or replace VIEW vw_pegawai_unitkerja 
AS SELECT a.*,b.nama as unit_kerja FROM pegawai a 
INNER JOIN unit_kerja b ON a.unit_kerja_id=b.id;

select * from vw_pegawai_unitkerja;