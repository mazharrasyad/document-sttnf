create database dblatihan;

use dblatihan;

create table unit_kerja (
id integer auto_increment primary key,
kode varchar(16) unique not null,
nama varchar(100) not null,
alamat varchar(100),
kota varchar(30),
budget double default 0
);

alter table unit_kerja rename unit_organisasi;

alter table unit_organisasi change nama organisasi varchar(100);

alter table unit_organisasi add nik_kepala varchar(20);

alter table unit_organisasi rename unit_kerja;

alter table unit_kerja change organisasi nama varchar(100);

insert into unit_kerja values 
(default,'DJP','Direktorat Jenderal Pajak','Jl. Jend. Gatot Subroto No. 40-42','Jakarta',3000,'03101179001'),
(default,'DJBC','Direktorat Jenderal Bea Cukai','Jl. Ahmad Yani By Pass, Rawamangun','Jakarta',3500,'04200576001'),
(default,'DJPU','Direktorat Jenderal Pengelolaan Utang','Gd. Frans Seda, Jl. Dr. Wahidin 1','Jakarta',2500,'04100384001'),
(default,'BPPK','Badan Pendidikan dan Pelatihan Keuangan','Jl. Purnawarman No. 99 Kebayoran','Jakarta',500,'04150186001');

create table pegawai(
nik varchar(20) primary key,
nama varchar(45) not null,
gender char(1),
tmp_lahir varchar(30),
tgl_lahir date,
email varchar(45),
unit_kerja_id integer,
foreign key (unit_kerja_id) references unit_kerja(id) on update cascade on delete cascade
);

insert into pegawai values
('03020786002','Glagah Putih','L','Klaten','1986-07-02','glagahputih@yahoo.com',1),
('03101179001','Agung Sedayu','L','Yogyakarta','1979-11-10','sedayu.agung79@gmail.com',1),
('03110780002','Sekar Mirah','P','Yogyakarta','1980-07-11','sekarmirah@gmail.com',1),
('04010188005','Rara Wulan','P','Klaten','1988-01-01','wulanr88@yahoo.com',3),
('04100292001','Raden Rangga','L','Jakarta','1992-02-10','rangga92@gmail.com',4),
('04100384001','Faiz Fikri','L','Jakarta','1984-03-10','faiz.fikri@yahoo.com',3),
('04100781001','Pandan Wangi','P','Solo','1981-07-10','wangi76@gmail.com',2),
('04150186001','Suherman Burhan','L','Padang','1986-01-15','suherman.burhan@gmail.com',4),
('04200576001','Swandaru Geni','L','Solo','1976-05-20','swandaru.geni@gmail.com',2),
('04200788001','Annisa Dinar','P','Depok','1988-07-20','dinar.nisa@gmail.com',3);
