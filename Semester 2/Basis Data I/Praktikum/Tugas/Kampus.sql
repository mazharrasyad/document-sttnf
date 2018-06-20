create database kampus;

create table Mahasiswa(
NIM varchar(10) primary key,
Nama varchar(50) NOT NULL,
Jurusan varchar(20) NOT NULL,
Angkatan int(4) NOT NULL,
Jk char(1),
Alamat varchar(50) NOT NULL,
Email varchar(45) NOT NULL,
No_Hape varchar(13) unique key
);

create table Dosen(
NIDN varchar(15) primary key,
Nama varchar(50) NOT NULL,
Status varchar(20),
Jk char(1),
Alamat varchar(50) NOT NULL,
Email varchar(45) NOT NULL,
No_Hape varchar(13) unique key
);

create table MataKuliah(
Kode_MK int primary key auto_increment,
Nama_MK varchar(45) NOT NULL,
SKS int(3) NOT NULL
);