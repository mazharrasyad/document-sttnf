-- Database

-- createdb dbolahraga -U ti1
-- dropdb dbolahraga -U ti1
-- psql dbolahraga -U ti1

-- Create Table Min 6 + Inheritance

drop table if exists pengguna cascade;
create table pengguna(
id serial primary key,
nama varchar(50) not null,
no_hp varchar(13) not null unique,
email varchar(25) not null unique
);

drop table if exists pengelola cascade;
create table pengelola(
no_rek varchar(20) not null unique,
nama_gor varchar(20) not null,
alamat_gor text not null,
penghasilan double precision default 0,
total_booking int default 0
)inherits(pengguna);

drop table if exists history_pengelola cascade;
create table history_pengelola(
id serial primary key,
pengelola_id int references pengguna(id),
tgl_pinjam timestamp not null,
tgl_selesai timestamp not null,
pendapatan double precision not null
);

drop table if exists cabor cascade;
create table cabor(
id serial primary key,
nama varchar(20) not null,
kapasitas int not null
);

drop table if exists fasilitas cascade;
create table fasilitas(
pengelola_id int references pengguna(id),
cabor_id int references cabor(id)
);

drop table if exists peringkat cascade;
create table peringkat(
id serial primary key,
nama varchar(10) not null,
diskon double precision
);

drop table if exists penyewa cascade;
create table penyewa(
kode varchar(20) not null unique,
peringkat_id int references peringkat(id),
budget double precision
)inherits(pengguna);

drop table if exists history_penyewa cascade;
create table history_penyewa(
id serial primary key,
penyewa_id int references pengguna(id),
tgl_pinjam timestamp not null,
tgl_selesai timestamp not null,
biaya double precision not null
);

drop table if exists booking cascade;
create table booking(
id serial primary key,
penyewa_id int references pengguna(id),
tgl_book date default now()
);

drop table if exists booking_detail cascade;
create table booking_detail(
booking_id int references booking(id),
fasilitas_pengelola_id int references pengguna(id),
fasilitas_cabor_id int references cabor(id),
tgl_pinjam timestamp not null,
tgl_selesai timestamp not null,
harga double precision default 0,
status varchar(10) default 'Pending'
);

-- Insert Table

insert into pengelola values
(1,'Ahmad','081290351971','ahmad@gmail.com','12345678901','GOR A','Depok',default,default),
(2,'Azhar','081290351972','azhar@gmail.com','12345678902','GOR B','Cibinong',default,default),
(3,'Rasyad','081290351973','rasyad@gmail.com','12345678903','GOR C','Citayam',default,default);

insert into cabor values
(1,'Basket',1),
(2,'Futsal',2),
(3,'Badminton',3);

insert into fasilitas values
(1,1),
(1,2),
(2,2),
(2,3),
(3,3),
(3,1);

insert into peringkat values
(1,'Perunggu',0.00),
(2,'Perak',0.05),
(3,'Emas',0.10);

insert into penyewa values
(4,'Rozzy','081290351974','rozzy@gmail.com',1,1000000),
(5,'Enricho','081290351975','enricho@gmail.com',1,2000000),
(6,'Alkalas','081290351976','alkalas@gmail.com',1,3000000);

select * from pengguna;
select * from pengelola;
select * from cabor;
select * from peringkat;
select * from penyewa;

-- Procedure Min 4

create or replace function
create_booking(int, int, int, date, date) returns void as
$$
	declare
		v_id int;
		v_penyewa_id alias for $1;
		v_fasilitas_pengelola_id alias for $2;
		v_fasilitas_cabor_id alias for $3;
		v_tgl_pinjam alias for $4;
		v_tgl_selesai alias for $5;
		v_harga double precision
	begin
		select into v_id id from booking order by id desc limit 1;

		if v_id is null then
			v_id = 1;
		else
			v_id = v_id + 1;
		end if;
		
		insert into booking values
		(v_id, v_penyewa_id, default);
		
		insert into pesan_detail values
		(v_id, v_fasilitas_pengelola_id, v_fasilitas_cabor_id, v_tgl_pinjam, v_tgl_selesai, v_harga, default);
	end
$$ language plpgsql;

-- Trigger Min 4 + 2 Otomatis

-- Transaction