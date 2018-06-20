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

select * from unit_kerja order by budget;

select kode,nama,budget from unit_kerja;

select * from pegawai order by nama desc;

select nik,nama,email from pegawai;

select * from unit_kerja order by budget asc;

select * from unit_kerja where kode = 'DJPU';

select kode,nama,budget from unit_kerja where budget > 3000;

select * from pegawai where gender = 'P';

select nik,nama,tmp_lahir from pegawai where tmp_lahir <> 'Jakarta';

select * from unit_kerja where budget > 500 and budget < 3200;

select * from unit_kerja where kode = 'DJP' or kode = 'DJBC';

select * from unit_kerja where id = 3 or id = 4;

select * from unit_kerja where budget < 3000 and budget > 500;

select * from pegawai where tmp_lahir = 'Klaten' or tmp_lahir = 'Solo';

select * from pegawai order by tgl_lahir desc;

select * from pegawai where tmp_lahir = 'Jakarta' and gender = 'L';

select * from pegawai where nik = '03110780002' or nik = '04100781001' or nik = '04200788001';