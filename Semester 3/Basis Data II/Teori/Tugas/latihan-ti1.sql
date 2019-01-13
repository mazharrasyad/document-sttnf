-- Create Function

create function salam()
returns text as
$$
	declare
		say text;
	begin
		say := 'Assalamualaikum Teman';
		return say;
	end
$$ language plpgsql

-- Run Function

select salam();

-- Function with Parameter

create or replace function hello(text)
returns text as
$$
	declare
		nama alias for $1;
		pesan text;
	begin
		pesan := 'Hello ' || nama;
		return pesan;	
	end
$$ language plpgsql

-- Run Function

select hello('Azhar');

-- Create or Replace Function

create or replace function
luasSegitiga(real, real) returns real
as
$$
	declare
		alas alias for $1;
		tinggi alias for $2;
	begin
		return alas * tinggi * 0.5;
	end
$$ language plpgsql

-- Run Function

select luasSegitiga(4,7);

-- Tugas

-- 1. Buat fungsi untuk menghitung jumlah dua bilangan 

create or replace function
penjumlahan(int, int) returns int
as
$$
	declare
		bilangan1 alias for $1;
		bilangan2 alias for $2;
	begin
		return bilangan1 + bilangan2;
	end
$$ language plpgsql

select penjumlahan(2, 5);

-- 2. Buat fungsi untuk menghitung luas lingkaran

create or replace function
luasLingkaran(int) returns double precision
as
$$
	declare
		r alias for $1;
	begin
		return 3.14 * r * r;
	end
$$ language plpgsql

select luasLingkaran(7);

-- 3. Buat fungsi untuk nilai rata dari total 3 nilai yang diberikan

create or replace function
rata3(int, int, int) returns double precision
as
$$
	declare
		bil1 alias for $1;
		bil2 alias for $2;
		bil3 alias for $3;
	begin
		return (bil1 + bil2 + bil3) / 3;
	end
$$ language plpgsql

select rata3(1, 2, 3);

-- Function Condition

create or replace function 
kelulusan(varchar, varchar) 
returns text as
$$
	declare
		nilai double precision;
		nim_mhs alias for $1;
		kode_mk alias for $2;
	begin
		select into nilai total_nilai from nilai_ujian where nim = nim_mhs and kodemk = kode_mk;
	
		if nilai > 65 then 
			return 'Nilai: ' || nilai || ', Lulus';
		else
			return 'Nilai: ' || nilai || ', Tidak Lulus';
		end if;
	end
$$ language plpgsql;

-- Run Function Condition

select kelulusan('011011', 'NF001');
select kelulusan('012012', 'NF001');

-- Function Update Table

create or replace function
grade(varchar, varchar)
returns text as
$$
	declare
		nilai double precision;
		nim_mhs alias for $1;
		kode_mk alias for $2;
		grade_mhs varchar;
		status_lulus text;
	begin
		select into nilai total_nilai from nilai_ujian where nim = nim_mhs and kodemk = kode_mk;
		
		if 85.01 <= nilai and nilai <= 100.00 then
			grade_mhs := 'A';
			status_lulus := 'Lulus';
		elseif 80.01 <= nilai and nilai <= 85.00 then
			grade_mhs := 'A-';
			status_lulus := 'Lulus';
		elseif 75.01 <= nilai and nilai <= 80.00 then
			grade_mhs := 'B+';
			status_lulus := 'Lulus';
		elseif 70.01 <= nilai and nilai <= 75.00 then
			grade_mhs := 'B';
			status_lulus := 'Lulus';
		elseif 65.01 <= nilai and nilai <= 70.00 then
			grade_mhs := 'B-';
			status_lulus := 'Lulus';
		elseif 60.01 <= nilai and nilai <= 65.00 then
			grade_mhs := 'C+';
			status_lulus := 'Tidak Lulus';
		elseif 55.01 <= nilai and nilai <= 60.00 then
			grade_mhs := 'C';
			status_lulus := 'Tidak Lulus';
		else
			grade_mhs := '-';
			status_lulus := 'Tidak Ada';
		end if;				
		update nilai_ujian set grade = grade_mhs, status = status_lulus where nim = nim_mhs and kodemk = kode_mk;
		return 'Nilai: ' || nilai || ', Status: ' || status_lulus || ', Grade: ' || grade_mhs;
	end
$$ language plpgsql;

-- Run Function Update Table

select grade('011011','NF001');
select grade('012012','NF001');

-- Function Insert Log

create or replace function
tambah_mhs_log() returns trigger as
$$
	begin
		insert into log_table (nama_table,aksi,isi) 
		values('mahasiswa', 'INSERT', new.id || ' - ' || new.nama);
	
		return new;	
	end
$$ language plpgsql;

-- Trigger Insert Log

create trigger trig_log_input_mhs after
insert on mahasiswa for each row
execute procedure tambah_mhs_log();

-- Run Trigger

insert into mahasiswa(id,nama) values (default,'Ihsanul Fikri');

-- Display Table

select * from mahasiswa;
select * from log_table;

-- Function Update Log

create or replace function
update_mhs_log() returns trigger as
$$
	begin
		insert into log_table (nama_table,aksi,isi) 
		values('mahasiswa', 'UPDATE', old.id || ' - ' || old.nama);
	
		return old;
	end
$$ language plpgsql;

-- Trigger Update Log

create trigger trig_log_update_mhs after
update on mahasiswa for each row
execute procedure update_mhs_log();

-- Run Trigger

update mahasiswa set nama='Ihsanul Fikri Abiyyu' where id=1;

-- Display Table

select * from mahasiswa;
select * from log_table;

-- Function Update Grade

create or replace function
update_mhs_grade() returns trigger as
$$
	declare
		grade_mhs varchar;
		status_lulus text;
		nilai double precision;
	begin
		nilai := new.total_nilai;
		
		if 85.01 <= nilai and nilai <= 100.00 then
			grade_mhs := 'A';
			status_lulus := 'Lulus';
		elseif 80.01 <= nilai and nilai <= 85.00 then
			grade_mhs := 'A-';
			status_lulus := 'Lulus';
		elseif 75.01 <= nilai and nilai <= 80.00 then
			grade_mhs := 'B+';
			status_lulus := 'Lulus';
		elseif 70.01 <= nilai and nilai <= 75.00 then
			grade_mhs := 'B';
			status_lulus := 'Lulus';
		elseif 65.01 <= nilai and nilai <= 70.00 then
			grade_mhs := 'B-';
			status_lulus := 'Lulus';
		elseif 60.01 <= nilai and nilai <= 65.00 then
			grade_mhs := 'C+';
			status_lulus := 'Tidak Lulus';
		elseif 55.01 <= nilai and nilai <= 60.00 then
			grade_mhs := 'C';
			status_lulus := 'Tidak Lulus';
		else
			grade_mhs := '-';
			status_lulus := 'Tidak Ada';
		end if;				
		update nilai_ujian set grade = grade_mhs, status = status_lulus 
		where nim = new.nim and kodemk = new.kodemk;
	
		return new;	
	end
$$ language plpgsql;

-- Trigger Update Grade

create trigger trig_update_mhs_grade after
insert on nilai_ujian for each row
execute procedure update_mhs_grade();

-- Run Trigger

insert into nilai_ujian(id, kodemk, nim, total_nilai)
values(3,'NF002','013013',0);

insert into nilai_ujian(id, kodemk, nim, total_nilai)
values(4,'NF002','014014',85);

delete from nilai_ujian where id=3;

select * from nilai_ujian;

-- Latihan dbmart

-- 1. Function Update Stok

create or replace function 
update_stock_product(int, int)
returns text as
$$
	declare
		product_id alias for $1;
		jml_stock alias for $2;
		stok_product int;
		total_stok int;
		pesan text;
	begin
		select into stok_product stock from products where id = product_id;
		
		if stok_product < 20 then
			total_stok := stok_product + jml_stock;			
			update products set stock = total_stok where id = product_id;
			pesan = 'Product dengan ID ' || product_id || ' berhasil diupdate stoknya';
		else
			pesan = 'Product dengan ID ' || product_id || ' stoknya masih cukup';
		end if;
	
		return pesan;
	end
$$ language plpgsql;

-- Run Function Update Stok

select * from products;
select update_stock_product(2,10); -- Verifikasi
select update_stock_product(1,1);

update products set stock = 10 where id = 1;

-- 2. Trigger untuk mengurangi stock ketik ada data baru pada order_details

-- Function Kurangi Stok

create or replace function
kurangi_stock() returns trigger as
$$
	declare
		qty_order int;
		total_stok int;
		stock_saat_ini int;
	begin
		select into stock_saat_ini stock from products where id = new.products_id;
	
		qty_order := new.quantity_order;
	
		if stock_saat_ini < qty_order then
			total_stok := stock_saat_ini + qty_order;
			update products set stock = total_stok where id = new.products_id;
		else
			total_stok := stock_saat_ini;
		end if;
	
		total_stok := total_stok - qty_order;
		update products set stock = total_stok where id = new.products_id;
	
		return new;
	end
$$ language plpgsql;

-- Trigger Kurangi Stok

create trigger trig_kurangi_stock before
insert on order_details for each row
execute procedure kurangi_stock();

-- Run Trigger

select * from products;

insert into orders values(default, '2018-10-25', 1);
select * from orders;

insert into order_details (orders_id, products_id, quantity_order) values
(1,2,1);
select * from order_details;

-- Transaction

create table jenis_produk(
id int primary key,
nama varchar(45)
);

begin;
insert into jenis_produk values (10,'Assesoris');
insert into jenis_produk values (11,'Komputer');
select * from jenis_produk;
rollback;

select * from jenis_produk;

begin;
insert into jenis_produk values (12,'Makanan');
insert into jenis_produk values (13,'Minuman');
select * from jenis_produk;
commit;

select * from jenis_produk;

begin;
delete from jenis_produk where id = 12;
select * from jenis_produk;
savepoint sp1;
delete from jenis_produk where id = 13;
select * from jenis_produk;
rollback to savepoint sp1;
select * from jenis_produk;
commit;

select * from jenis_produk;

-- Latihan Transaction

-- 1. Buat table produk

create table produk(
id int primary key,
nama varchar(50),
stok int
);

-- 2. Jalankan sebuah transaction, lakukan
-- perintah DML (insert ke dalam table
-- produk sebanyak 3 data)
begin;
insert into produk values
(1,'Mobil',10),
(2,'Motor',20),
(3,'Sepeda',30);
select * from produk;

-- 3. Buat savepoint sp1
savepoint sp1;

-- 4. Lakukan perintah delete untuk 1 data
delete from produk where id = 1;
select * from produk;

-- 5. Lakukan rollback ke save point sp1
rollback to savepoint sp1;
select * from produk;

-- 6. Akhiri transaction dengan commit
commit;

select * from produk;

-- Latihan Transaction 2
-- ERD dbmart
-- Soal Cerita
-- 	Ayu adalah seorang kasir pada sebuah supermarket yang bertugas 
-- meng-entry data master maupun data transaksi
-- 	Ayu sedang melakukan proses query insert data ke tabel products
-- sebanyak 5 data/record. Setelah itu ada customer datang ingin
-- melakukan pembelian 2 produk masing-masing sebayak satu buah
-- 	Setelah data pembelian di-entry oleh Ayu, ternyata customer
-- tersebut membatalkan pembelian karena dompetnya tertinggal di rumah.
-- Karena pembelian batal, Ayu ingin kembali ke kondisi
-- setelah data produk di-entry
-- 	Buatlah rangkaian proses-proses tersebut ke dalam sebuah proses
-- transaction

-- Ringkasan
-- 1. insert data ke tabel products sebanyak 5 data/record
-- 2. customer melakukan pembelian 2 produk masing-masing sebayak satu buah
-- 3. data pembelian di-entry
-- 4. customer membatalkan maka kembali ke kondisi setelah data produk di-entry

-- Versi Azhar
begin;
select * from products;
-- 1. insert data ke tabel products sebanyak 5 data/record
insert into products values
(4,'Roti C','Rasa Coklat',10,1000),
(5,'Roti S','Rasa Stroberi',20,2000),
(6,'Roti K','Rasa Keju',30,3000),
(7,'Roti D','Rasa Durian',40,4000),
(8,'Roti B','Rasa Blueberry',50,5000);
select * from products;
savepoint sp1;
-- 2. customer melakukan pembelian 2 produk masing-masing sebayak satu buah
select * from customer;
-- 3. data pembelian di-entry
select * from orders;
insert into orders values
(4,current_date, 1);
select * from orders;
select * from order_details;
insert into order_details (orders_id, products_id, quantity_order) values
(4,4,1),
(4,5,1);
select * from order_details;
select * from products;
savepoint sp2;
-- 4. customer membatalkan maka kembali ke kondisi setelah data produk di-entry
rollback to savepoint sp1;
select * from products;
select * from orders;
select * from order_details;
-- commit;
-- rollback;

-- Versi P Edo
begin;
insert into products values
(default,'Product A','Makanan',100,13000),
(default,'Product B','Makanan',80,9000),
(default,'Product C','Minuman',140,25000),
(default,'Product D','Minuman',300,3000),
(default,'Product E','Makanan',30,11000);
savepoint sp1;
insert into orders values(default,'2018-11-29',1);
select * from orders;
insert into order_details values
(6,3,1,null),
(6,4,1,null);
rollback to savepoint sp1;
commit;
select * from orders;
select * from products;