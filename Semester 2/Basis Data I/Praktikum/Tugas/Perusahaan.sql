create database PT_Analog_Sentosa;

create table Departemen(
idDepartemen int primary key auto_increment,
Nama varchar(65) not null,
Lokasi varchar(20) not null
);

create table Direktur(
idDirektur int primary key auto_increment,
Nama varchar(50) not null,
Tempat varchar(30) not null,
Tanggal_Lahir date not null,
Jenis_Kelamin char(1) not null,
Alamat varchar(40) not null,
No_HP varchar(15) unique key
);

create table Investor(
idInvestor int primary key auto_increment,
Nama varchar(50) not null,
Jumlah varchar(35) not null,
No_Telp varchar(15) unique key
);

create table Proyek(
idProyek int primary key auto_increment,
Nama varchar(45) not null,
Tanggal_Awal datetime not null,
Tanggal_Akhir datetime not null
);

create table Pegawai(
idPegawai int primary key auto_increment,
Nama varchar(50) not null,
Tempat_Lahir varchar(30) not null,
Tanggal_Lahir date not null,
Gaji varchar(35) not null,
Jenis_Kelamin char(1) not null,
Jabatan varchar(25) not null,
Alamat varchar(40) not null,
No_HP varchar(15) unique key
);

create table General_Manager(
idGM int primary key auto_increment,
Nama varchar(50) not null,
Tempat_Lahir varchar(30) not null,
Tanggal_Lahir date not null,
Jenis_Kelamin char(1) not null,
Alamat varchar(15) not null,
No_HP varchar(45) unique key
);

rename table Departemen to Perusahaan;

rename table Pegawai to Karyawan;

rename table Proyek to Projek;

drop table Projek;

drop table Investor;

drop database PT_Analog_Sentosa;