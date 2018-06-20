create database dblatihan;

create database dbtesting;

drop database dbtesting;

use dblatihan;

create table unit_kerja (
id integer auto_increment primary key,
kode varchar(16) unique not null,
nama varchar(100) not null,
alamat varchar(100),
kota varchar(30),
budget double default 0
);

show tables;

desc unit_kerja;

alter table unit_kerja rename unit_organisasi;

alter table unit_organisasi change nama organisasi varchar(100);

show tables;

alter table unit_organisasi add nik_kepala varchar(20);

alter table unit_organisasi add website varchar(40) after kota;

alter table unit_organisasi drop website;

alter table unit_organisasi rename unit_kerja;

alter table uni	t_kerja change organisasi nama varchar(100);

insert into unit_kerja (id,kode,nama)
values (default,'DJP','Direktorat Jenderal Pajak');

insert into unit_kerja
values (default,'DJBC','Direktorat Jenderal Bea Cukai','Jl. A Yani','Jakarta',5000,'041232203');

insert into unit_kerja values 
(default,'DJPU','Direktorat Jenderal ...','Jl. XYX','Jakarta',4000,'0423212'),
(default,'BPPK','Badan Pendidikan ...','Jl. ABC','Jakarta',2000,'0441232');

select * from unit_kerja;

update unit_kerja set alamat='JL. Jend. Gatot Subroto No. 40-42', kota='Jakarta', budget=3000, nik_kepala='03101179001' where id = 1;

delete * from unit_kerja where id = 1;

insert into unit_kerja values 
(default,'DJP','Direktorat Jenderal Pajak','Jl. Jend. Gatot Subroto No. 40-42','Jakarta',3000,'03101179001'),
(default,'DJBC','Direktorat Jenderal Bea Cukai','Jl. Ahmad Yani By Pass, Rawamangun','Jakarta',3500,'04200576001'),
(default,'DJPU','Direktorat Jenderal Pengelolaan Utang','Gd. Frans Seda, Jl. Dr. Wahidin 1','Jakarta',2500,'04100384001'),
(default,'BPPK','Badan Pendidikan dan Pelatihan Keuangan','Jl. Purnawarman No. 99 Kebayoran','Jakarta',500,'04150186001');

update unit_kerja set id = 1 where id = 5;
update unit_kerja set id = 2 where id = 6;
update unit_kerja set id = 3 where id = 7;
update unit_kerja set id = 4 where id = 8;
