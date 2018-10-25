-- Function Pertemuan 1
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

select salam();

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

select hello('Azhar');

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

select luasSegitiga(4,7);

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

select grade('011011','NF001');
select grade('012012','NF001');

-- Function Trigger Insert

create or replace function
tambah_mhs_log() returns trigger as
$$
	begin
		insert into log_table (nama_table,aksi,isi) 
		values('mahasiswa', 'INSERT', new.id || ' - ' || new.nama);
	
		return new;	
	end
$$ language plpgsql;

create trigger trig_log_input_mhs after
insert on mahasiswa for each row
execute procedure tambah_mhs_log();

select * from mahasiswa;
select * from log_table;

insert into mahasiswa(id,nama) values (default,'Ihsanul Fikri');

-- Function After Update

create or replace function
update_mhs_log() returns trigger as
$$
	begin
		insert into log_table (nama_table,aksi,isi) 
		values('mahasiswa', 'UPDATE', old.id || ' - ' || old.nama);
	
		return old;
	end
$$ language plpgsql;

create trigger trig_log_update_mhs after
update on mahasiswa for each row
execute procedure update_mhs_log();

update mahasiswa set nama='Ihsanul Fikri Abiyyu' where id=1;

select * from mahasiswa;
select * from log_table;

-- Function Update Grade

select * from nilai_ujian;

create or replace function
update_mhs_grade_log() returns trigger as
$$
	begin
		insert into log_table (nama_table, aksi, isi) 
		values('nilai_ujian', 'UPDATE', old.nim || ' - ' || old.kodemk || ' - ' || old.total_nilai || ' - ' || old.grade);
	
		return old;
	end
$$ language plpgsql;

-- Function trigger Grade

create trigger trig_log_update_mhs_grade after
update on nilai_ujian for each row
execute procedure update_mhs_grade_log();

-- Drop Trigger
drop trigger trig_log_update_mhs_grade on nilai_ujian;

update nilai_ujian set grade='A-' where id=1;

select * from nilai_ujian;
select * from log_table;

-- Otomatis Trigger

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

-- Trigger
create trigger trig_update_mhs_grade after
insert on nilai_ujian for each row
execute procedure update_mhs_grade();

drop trigger trig_update_grade_mhs on nilai_ujian;

-- Test trigger
insert into nilai_ujian(id, kodemk, nim, total_nilai)
values(3,'NF002','013013',0);

insert into nilai_ujian(id, kodemk, nim, total_nilai)
values(4,'NF002','014014',85);

delete from nilai_ujian where id=3;

select * from nilai_ujian;

-- TUGAS dbmart

select * from customer;
select * from products;
select * from orders;
select * from order_details;

-- 1. Buat fungsi update_stock_product(id_product, jumlah_stock) 
-- untuk meng-update data product yang stock nya kurang dari 20.

create or replace function
update_stock_product(int, int) returns int as
$$
	declare
		id_product alias for $1;
		jumlah_stock alias for $2;
		v_stock int;
	begin
		select into v_stock stock from products where id = id_product;
		
		if v_stock < 20 then
		
			v_stock = v_stock + jumlah_stock;
		
			if 20 < v_stock then
				update products set stock = stock + jumlah_stock where id = id_product;
				return v_stock;
			else
				raise exception 'Jumlah Stock Masih Kurang Dari 20';
			end if;
		else
			raise exception 'Stock Anda Tidak Kurang Dari 20';
		end if;
	end
$$ language plpgsql;

select * from products;
select update_stock_product(1,6);

-- 2. Buat trigger pada tabel order_details untuk mengurangi stock pada products. 
-- Trigger dieksekusi sebelum insert data dengan terlebih dahulu mengecek stock product. 
-- jika stock kurang dari quantity_order maka harus di update stock terlebih dahulu.

-- Menghitung Stock

create or replace function beli_product() returns trigger as
$$
	declare
		v_stock int;
	begin
		select into v_stock stock from products where id = new.products_id;
		
		if new.quantity_order <= v_stock then
			update products set stock = stock - new.quantity_order
			where id = new.products_id;
		
			return new;
		else
			raise exception 'Stock Tidak Mencukupi Maka Stock Perlu Diupdate';
		end if;	
	end
$$ language plpgsql;

create trigger trig_beli_product before
insert on order_details for each row
execute procedure beli_product();

-- Menghitung price_each

create or replace function update_product() returns trigger as
$$
	declare
		v_price double precision;
	begin
		select into v_price price from products where id = new.products_id;
				
		update order_details set price_each = new.quantity_order * v_price
		where orders_id = new.orders_id and products_id = new.products_id;
	
		return new;
	end
$$ language plpgsql;

create trigger trig_update_product after
insert on order_details for each row
execute procedure update_product();

-- Latihan dbmart

-- 1. Fungsi update stok

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

select * from products;
select update_stock_product(2,10); -- Verifikasi
select update_stock_product(1,1);

update products set stock = 10 where id = 1;

-- 2. Trigger untuk mengurangi stock ketik ada data baru pada order_details

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

create trigger trig_kurangi_stock before
insert on order_details for each row
execute procedure kurangi_stock();

select * from products;

insert into orders values(default, '2018-10-25', 1);
select * from orders;

insert into order_details (orders_id, products_id, quantity_order) values
(1,2,1);
select * from order_details;

drop trigger trig_beli_product on order_details;
