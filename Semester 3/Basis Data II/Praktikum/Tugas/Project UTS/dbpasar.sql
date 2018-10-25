-- Start Server

-- sudo su - apsql // Praktikum
-- /home/apsql/pg105/bin/pg_ctl -D /home/apsql/datapg/ -l logfile start // Praktikum

-- Create Database

-- createdb dbpasar -U ti1 // Teori
-- /home/apsql/pg105/bin/createdb dbpasar -U apsql -p5555 -h localhost // Praktikum

-- Login Database

-- psql dbpasar -U ti1 // Teori
-- /home/apsql/pg105/bin/psql dbpasar -U apsql -p5555 -h localhost // Praktikum

-- Create Table

create table tengkulak(
id serial primary key,
nama varchar(45) not null,
telp varchar(13) not null unique,
penghasilan double precision not null
);

create table history_tengkulak(
id serial primary key,
tengkulak_id int references tengkulak(id),
pendapatan double precision not null,
produk varchar(45) not null,
stok int not null,
tanggal timestamp default now() not null
);

create table persediaan(
id serial primary key,
nama_produk varchar(45) not null,
stok_perkg int not null,
harga_perkg double precision not null,
tengkulak_id int references tengkulak(id)
);

create table pedagang(
id serial primary key,
nama varchar(45) not null,
telp varchar(13) not null unique,
budget double precision not null
);

create table history_pedagang(
id serial primary key,
pedagang_id int references pedagang(id),
pengeluaran double precision not null,
produk varchar(45) not null,
stok int not null,
tanggal timestamp default now() not null
);

create table pesan(
id serial primary key,
pedagang_id int references pedagang(id),
tanggal timestamp default now() not null
);

create table pesan_detail(
pesan_id int references pesan(id) not null,
persediaan_id int references persediaan(id) not null,
jumlah int not null,
total double precision
);

-- Create Function

create or replace function
pesan_produk(int, int, int) returns void as
$$
	declare
		v_id int;
		v_pedagang_id alias for $1;
		v_persediaan_id alias for $2;
		v_jumlah alias for $3;
	begin
		select into v_id id from pesan order by id desc limit 1;

		if v_id is null then
			v_id = 1;
		else
			v_id = v_id + 1;
		end if;
		
		insert into pesan values
		(v_id, v_pedagang_id, default);
	
		insert into pesan_detail values
		(v_id, v_persediaan_id, v_jumlah, default);
	end
$$ language plpgsql;

create or replace function 
transaksi() returns trigger as
$$
	declare
		v_tengkulak_id int;
		v_pedagang_id int;	
		v_nama_produk varchar;
		v_stok_perkg int;
		v_harga_perkg double precision;
		v_budget double precision;
		v_total double precision;				
	begin		
		select into v_tengkulak_id tengkulak_id from persediaan where id = new.persediaan_id;	
		select into v_pedagang_id pedagang_id from pesan where id = new.pesan_id;
		select into v_nama_produk nama_produk from persediaan where id = new.persediaan_id;
		select into v_stok_perkg stok_perkg from persediaan where id = new.persediaan_id;
		select into v_harga_perkg harga_perkg from persediaan where id = new.persediaan_id;		
		select into v_budget budget from pedagang where id = v_pedagang_id;
		v_total = v_harga_perkg * new.jumlah;
			
		if 0 < new.jumlah and new.jumlah <= v_stok_perkg then		
			if v_total <= v_budget then		
				insert into history_tengkulak 
				values(default, v_tengkulak_id, v_total, v_nama_produk, 
				new.jumlah, default);
			
				insert into history_pedagang 
				values(default, v_pedagang_id, v_total, v_nama_produk, 
				new.jumlah, default);
			
				update tengkulak set penghasilan = penghasilan + v_total 
				where id = v_tengkulak_id;
			
				update pedagang set budget = budget - v_total
				where id = v_pedagang_id;
			
				update persediaan set stok_perkg = stok_perkg - new.jumlah 
				where id = new.persediaan_id;			
			
				update pesan_detail set total = v_total 
				where pesan_id = new.pesan_id;	
			else
				raise exception 'Budget Tidak Mencukupi';
			end if;
		else
			raise exception 'Stok Tidak Mencukupi';
		end if;
		return new;
	end
$$ language plpgsql;

-- Create Trigger

create trigger trig_transaksi after
insert on pesan_detail for each row
execute procedure transaksi();

-- Insert Table

insert into tengkulak values
(1,'Adil','08123450',0),
(2,'Iyan','08123451',0),
(3,'Fikri','08123452',0),
(4,'Fathan','08123453',0),
(5,'Shidqi','08123454',0);

insert into persediaan values
(1,'Beras',500,9450,1),
(2,'Gula',400,12500,2),
(3,'Garam',300,800,3),
(4,'Cabai',200,40000,4),
(5,'Tepung',100,19000,5);

insert into pedagang values
(1,'Messi','081234560',1000000),
(2,'Ronaldo','081234561',2000000),
(3,'Ronny','081234562',3000000),
(4,'Suaresz','081234563',4000000),
(5,'Lampard','081234564',5000000);

-- Contoh Pesan Produk

-- Verifikasi Jika Stok Kurang

select pesan_produk(1,5,101);

-- Verifikasi Jika Budget Kurang

select pesan_produk(1,2,400);

-- Verifikasi Jika Terpenuhi

select pesan_produk(1,2,10);

-- Select Table

select * from tengkulak;
select * from history_tengkulak;
select * from pedagang;
select * from history_pedagang;
select * from persediaan;
select * from pesan;
select * from pesan_detail;

-- Drop Table

drop table 
tengkulak,
history_tengkulak,
persediaan,
pedagang,
history_pedagang,
pesan,
pesan_detail
cascade;

-- Drop Function

drop function transaksi() cascade;
drop function pesan_produk(int, int, int);

-- Drop Trigger

drop trigger trig_transaksi on pesan_detail;

-- Drop database

-- dropdb dbpasar -U ti1 // Teori
-- /home/apsql/pg105/bin/dropdb dbpasar -U apsql -p5555 -h localhost // Praktikum
