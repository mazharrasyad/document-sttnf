-- Database

-- createdb dbolahraga -U ti1
-- dropdb dbolahraga -U ti1
-- psql dbolahraga -U ti1

-- Table

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
total_booking int default 0,
primary key(id)
)inherits(pengguna);

drop table if exists cabor cascade;
create table cabor(
id serial primary key,
nama varchar(20) not null
);

drop table if exists fasilitas cascade;
create table fasilitas(
id serial primary key,
pengelola_id int references pengelola(id),
cabor_id int references cabor(id),
harga_perjam double precision not null,
harga_perhari double precision not null,
jml_lapangan int not null
);

drop table if exists member cascade;
create table member(
id serial primary key,
nama varchar(10) not null,
cashback double precision
);

drop table if exists penyewa cascade;
create table penyewa(
budget double precision,
member_id int references member(id),
berhasil_booking int default 0,
gagal_booking int default 0,
primary key(id)
)inherits(pengguna);

drop table if exists booking cascade;
create table booking(
id serial primary key,
penyewa_id int references penyewa(id),
tgl_book timestamp default current_timestamp
);

drop table if exists history_penyewa cascade;
create table history_penyewa(
penyewa_id int references penyewa(id),
booking_id int references booking(id) unique,
member_id int references member(id),
biaya double precision not null
);

drop table if exists history_pengelola cascade;
create table history_pengelola(
pengelola_id int references pengelola(id),
booking_id int references booking(id) unique,
pendapatan double precision not null
);

drop table if exists history_fasilitas cascade;
create table history_fasilitas(
fasilitas_id int references fasilitas(id),
booking_id int references booking(id) unique,
status varchar(10) default 'Pinjam'
);

drop table if exists booking_detail cascade;
create table booking_detail(
booking_id int references booking(id),
fasilitas_id int references fasilitas(id),
tgl_pinjam timestamp not null,
tgl_selesai timestamp not null,
harga double precision default 0,
status varchar(10) default 'Pending'
);

-- Insert

insert into pengelola values
(default,'Ahmad','081290351971','ahmad@gmail.com','12345678901','GOR A','Depok',default,default),
(default,'Azhar','081290351972','azhar@gmail.com','12345678902','GOR B','Cibinong',default,default),
(default,'Rasyad','081290351973','rasyad@gmail.com','12345678903','GOR C','Citayam',default,default),
(default,'Rasaz','081290351974','rasaz@gmail.com','12345678904','GOR D','Cilebut',default,default),
(default,'Mazhar','081290351975','mazhar@gmail.com','12345678905','GOR E','Bogor',default,default);

insert into cabor values
(1,'Basket'),
(2,'Futsal'),
(3,'Badminton'),
(4,'Voli'),
(5,'Renang');

insert into fasilitas values
(default,1,1,10000,100000,1),
(default,1,2,20000,150000,2),
(default,2,3,30000,200000,3),
(default,2,4,40000,250000,4),
(default,3,5,50000,300000,5),
(default,3,1,60000,350000,1),
(default,4,2,70000,400000,2),
(default,4,3,80000,450000,3),
(default,5,4,90000,500000,4),
(default,5,5,100000,550000,5);

insert into member values
(1,'Perunggu',0.00),
(2,'Perak',0.05),
(3,'Emas',0.10);

insert into penyewa values
(default,'Rozzy','081290351974','rozzy@gmail.com',1000000,1,default),
(default,'Enricho','081290351975','enricho@gmail.com',2000000,2,default),
(default,'Alkalas','081290351976','alkalas@gmail.com',3000000,3,default),
(default,'Fachrur','081290351977','fachrur@gmail.com',4000000,1,default),
(default,'Dirza','081290351978','dirza@gmail.com',5000000,2,default);

-- Procedure

drop function if exists buat_booking(int, int, timestamp, timestamp) cascade;
create or replace function
buat_booking(int, int, timestamp, timestamp) 
returns text as
$$
	declare		
		v_penyewa_id alias for $1;
		v_fasilitas_id alias for $2;
		v_tgl_pinjam alias for $3;
		v_tgl_selesai alias for $4;
		v_id int;
		v_harga double precision;
		v_harga_perjam double precision;
		v_harga_perhari double precision;
		v_jml_lapangan int;
		hari double precision;
		jam double precision;
		v2_penyewa_id int;
		v2_fasilitas_id int;	
		i int;
		pesan text;
	begin
		select into v_id id from booking order by id desc limit 1;		
		select into v_harga_perjam harga_perjam from fasilitas where id = v_fasilitas_id;
		select into v_harga_perhari harga_perhari from fasilitas where id = v_fasilitas_id;
		select into v_jml_lapangan jml_lapangan from fasilitas where id = v_fasilitas_id;
	
		if date_part('day', (v_tgl_selesai - v_tgl_pinjam)) = 0 then		
			jam = date_part('hour', (v_tgl_selesai - v_tgl_pinjam));
				if 0 < jam then
					v_harga = v_harga_perjam * jam;
					pesan = jam || ' Jam';
				else
					raise exception 'Tanggal Booking Salah';
				end if;
		else			
			hari = date_part('day', (v_tgl_selesai - v_tgl_pinjam));
				if 0 < hari then
					hari = hari + 1;
					v_harga = v_harga_perhari * hari;
					pesan = hari || ' Hari';
				else
					raise exception 'Tanggal Booking Salah';
				end if;
		end if;			
		
		if v_id is null then
			v_id = 1;
		else
			v_id = v_id + 1;
		end if;	

		i = 0;
		loop
			select into v2_penyewa_id id from penyewa limit 1 offset i;						
			
			if v_penyewa_id = v2_penyewa_id then				
				exit;	
			elseif v2_penyewa_id is null then
				exit;
			end if;			
			
			i = i + 1;				
		end loop;		
	
		i = 0;
		loop
			select into v2_fasilitas_id id from fasilitas limit 1 offset i;						
			
			if v_fasilitas_id = v2_fasilitas_id then				
				exit;	
			elseif v2_fasilitas_id is null then
				exit;
			end if;			
			
			i = i + 1;				
		end loop;	

		if v_penyewa_id = v2_penyewa_id then
			insert into booking values
			(v_id, v_penyewa_id, default);
		
			if v_fasilitas_id = v2_fasilitas_id then			
				if 0 < v_jml_lapangan then 
					insert into booking_detail values
					(v_id, v_fasilitas_id, v_tgl_pinjam, v_tgl_selesai, v_harga, default);
					return 'Booking Berhasil Selama ' || pesan;
				else
					raise exception 'Lapangan Tidak Tersedia';
				end if;
			else
				raise exception 'ID Fasilitas Tidak Ada';
			end if;
		else
			raise exception 'ID Penyewa Tidak Ada';
		end if;	
	end
$$ language plpgsql;

drop function if exists transfer(int, varchar) cascade;
create or replace function
transfer(int, varchar) 
returns text as
$$
	declare	
		v_booking_id alias for $1;
		v_no_rek alias for $2;
		v_harga double precision;
		v_status text;
		v_penyewa_id int;
		v_budget int;
		v_pengelola_id int;
		v_fasilitas_id int;
		v_member_id int;
		v_cashback double precision;
		v2_booking_id int;
		v2_no_rek text;
		v2_pengelola_id int;
		v2_cashback double precision;
		i int;
	begin			
		select into v_status status from booking_detail where booking_id = v_booking_id;
		select into v_harga harga from booking_detail where booking_id = v_booking_id;		
		select into v_penyewa_id penyewa_id from booking where id = v_booking_id;
		select into v_budget budget from penyewa where id = v_penyewa_id;
		select into v_pengelola_id id from pengelola where no_rek = v_no_rek;
		select into v_fasilitas_id fasilitas_id from booking_detail where booking_id = v_booking_id;
		select into v2_pengelola_id pengelola_id from fasilitas where id = v_fasilitas_id;
		select into v_member_id member_id from penyewa where id = v_penyewa_id;
		select into v_cashback cashback from member where id = v_member_id;
				
		i = 0;
		loop
			select into v2_booking_id booking_id from booking_detail limit 1 offset i;			
			
			if v_booking_id = v2_booking_id then				
				exit;	
			elseif v2_booking_id is null then
				exit;
			end if;			
			
			i = i + 1;				
		end loop;	
	
		i = 0;
		loop
			select into v2_no_rek no_rek from pengelola limit 1 offset i;			
			
			if v_no_rek = v2_no_rek then				
				exit;	
			elseif v2_no_rek is null then
				exit;
			end if;			
			
			i = i + 1;				
		end loop;	

		if v_booking_id = v2_booking_id then
			if v_no_rek = v2_no_rek then
				if v_pengelola_id = v2_pengelola_id then
					if v_status = 'Pending' then
						if v_harga <= v_budget then						
							update penyewa set budget = budget - v_harga
							where id = v_penyewa_id;
						
							update pengelola set 
							penghasilan = penghasilan + v_harga,
							total_booking = total_booking + 1
							where id = v_pengelola_id;
						
							update fasilitas set jml_lapangan = jml_lapangan - 1
							where id = v_fasilitas_id;
						
							update booking_detail set status = 'Berhasil'
							where booking_id = v_booking_id;

							v2_cashback = v_harga * v_cashback;
						
							update penyewa set budget = budget + v2_cashback
							where id = v_penyewa_id;
						
							insert into history_penyewa values
							(v_penyewa_id, v_booking_id, v_member_id, v_harga - v2_cashback);
						
							insert into history_pengelola values
							(v_pengelola_id, v_booking_id, v_harga);
						
							insert into history_fasilitas values
							(v_fasilitas_id, v_booking_id, default);													
						
							return 'Transfer Berhasil';
						else
							raise exception 'Budget Tidak Mencukupi';
						end if;
					else
						raise exception 'ID Booking Tidak Berlaku';
					end if;	
				else
					raise exception 'No Rekening Salah Kirim';
				end if;
			else
				raise exception 'No Rekening Tidak Ada';
			end if;
		else
			raise exception 'ID Booking Tidak Ada';
		end if;	
	end
$$ language plpgsql;

drop function if exists tingkat_member() cascade;
create or replace function 
tingkat_member() returns trigger as
$$
	declare
		v_biaya double precision;
	begin		
		select into v_biaya sum(biaya) from history_penyewa where penyewa_id = new.penyewa_id;			
	
		if 1000000 < v_biaya then
			update penyewa set member_id = '3' where id = new.penyewa_id;
		elseif 500000 < v_biaya then
			update penyewa set member_id = '2' where id = new.penyewa_id;
		end if;
		
		return new;
	end
$$ language plpgsql;

create or replace function 
bonus() returns trigger as
$$
	begin			
		if new.member_id = old.member_id then
			return old;
		else 
			if new.member_id = 3 then
				update penyewa set budget = budget + 100000 where id = old.id;
			elseif new.member_id = 2 then
				update penyewa set budget = budget + 50000 where id = old.id;
			end if;
			
			return new;
		end if;
	end
$$ language plpgsql;

drop function if exists batal_booking() cascade; 
create or replace function 
batal_booking(int) returns text as
$$
	declare
		v_booking_id alias for $1;
		v2_booking_id int;
		v_status text;
		i int;
	begin
		i = 0;
		loop
			select into v2_booking_id booking_id from booking_detail limit 1 offset i;			
			
			if v_booking_id = v2_booking_id then				
				exit;	
			elseif v2_booking_id is null then
				exit;
			end if;			
			
			i = i + 1;				
		end loop;
		
		if v_booking_id = v2_booking_id then
			select into v_status status from booking_detail where booking_id = v_booking_id;
		
			if v_status = 'Pending' then
				delete from booking_detail where booking_id = v_booking_id;
				return 'Booking Berhasil Dibatalkan';
			else
				raise exception 'Status Booking Bukan Pending';
			end if;
		else
			raise exception 'ID Booking Tidak Ada';
		end if;
	end
$$ language plpgsql;

drop function if exists proses_batal_booking() cascade;
create or replace function 
proses_batal_booking() returns trigger as
$$
	begin
		delete from booking 
		where id = old.booking_id;
		return old;
	end
$$ language plpgsql;

drop function if exists batalin_booking() cascade;
create or replace function 
batalin_booking() returns trigger as
$$	
	begin							
		update penyewa set gagal_booking = gagal_booking + 1 
		where id = old.penyewa_id;
		return old;
	end
$$ language plpgsql;

drop function if exists selesai_booking(int) cascade; 
create or replace function 
selesai_booking(int) returns text as
$$
	declare
		v_booking_id alias for $1;
		v2_booking_id int;
		v_fasilitas_id int;
		v_penyewa_id int;
		v_status text;
		i int;
	begin
		i = 0;
		loop
			select into v2_booking_id booking_id from booking_detail limit 1 offset i;			
			
			if v_booking_id = v2_booking_id then				
				exit;	
			elseif v2_booking_id is null then
				exit;
			end if;			
			
			i = i + 1;				
		end loop;
		
		if v_booking_id = v2_booking_id then
			select into v_fasilitas_id fasilitas_id from booking_detail where booking_id = v_booking_id;
			select into v_status status from booking_detail where booking_id = v_booking_id;			
			select into v_penyewa_id penyewa_id from booking where id = v_booking_id;
		
			if v_status = 'Berhasil' then
				update history_fasilitas set status = 'Selesai' 
				where fasilitas_id = v_fasilitas_id and booking_id = v_booking_id;
			
				update penyewa set berhasil_booking = berhasil_booking + 1 
				where id = v_penyewa_id;			
			
				update fasilitas set jml_lapangan = jml_lapangan + 1 
				where id = v_fasilitas_id;
				return 'Booking Selesai';
			else
				raise exception 'Status Booking Bukan Selesai';
			end if;
		else
			raise exception 'ID Booking Tidak Ada';
		end if;
	end
$$ language plpgsql;

-- Trigger

drop trigger if exists trig_tingkat_member on history_penyewa;
create trigger trig_tingkat_member after
insert on history_penyewa for each row
execute procedure tingkat_member();

create trigger trig_bonus after
update on penyewa for each row
execute procedure bonus();

drop trigger if exists trig_proses_batal_booking on booking_detail;
create trigger trig_proses_batal_booking after
delete on booking_detail for each row
execute procedure proses_batal_booking();

drop trigger if exists trig_batalin_booking on booking;
create trigger trig_batalin_booking after
delete on booking for each row
execute procedure batalin_booking();

-- Select Table

select * from pengguna;
select * from pengelola;
select * from history_pengelola;
select * from cabor;
select * from fasilitas;
select * from member;
select * from penyewa;
select * from history_penyewa;
select * from booking;
select * from booking_detail;

-- Transaction

begin transaction

-- Verifikasi Buat Booking
savepoint sp1;
select * from penyewa;
select * from fasilitas;

-- select buat_booking(penyewa_id, fasilitas_id, tgl_pinjam, tgl_selesai);
select buat_booking(1,1,timestamp '2019-12-01 08:00:00',timestamp '2019-12-01 10:00:00');
select buat_booking(6,11,timestamp '2019-12-01 08:00:00',timestamp '2019-12-01 10:00:00');
select buat_booking(6,1,timestamp '2019-12-02 00:00:00',timestamp '2019-12-01 00:00:00');
rollback to savepoint sp1;

-- Testing Buat Booking
select buat_booking(6,1,timestamp '2019-12-01 08:00:00',timestamp '2019-12-01 10:00:00');
select buat_booking(7,2,timestamp '2019-12-02 00:00:00',timestamp '2019-12-30 00:00:00');
select buat_booking(8,3,timestamp '2019-12-03 00:00:00',timestamp '2019-12-04 00:00:00');
select buat_booking(9,4,timestamp '2019-12-04 13:00:00',timestamp '2019-12-04 17:00:00');
select buat_booking(10,5,timestamp '2019-12-05 08:00:00',timestamp '2019-12-05 12:00:00');
select * from booking;
select * from booking_detail;

-- Verifikasi Transfer 1
savepoint sp2;
select * from penyewa;
select * from pengelola;
select * from booking;
select booking_id,no_rek from booking_detail
inner join fasilitas on fasilitas_id = fasilitas.id
inner join pengelola on pengelola_id = pengelola.id;

-- select transfer(booking_id, no_rek);
select transfer(6,'12345678901');
select transfer(1,'12345678001');
select transfer(2,'12345678901');
select transfer(2,'12345678902');
rollback to savepoint sp2;

-- Testing Transfer
select transfer(3,'12345678902');
select transfer(4,'12345678902');
select transfer(5,'12345678903');
select * from fasilitas;
select * from booking_detail;
select * from history_penyewa;
select * from penyewa;
select * from history_pengelola;
select * from pengelola;
select * from history_fasilitas;
select * from fasilitas;

-- Verifikasi Transfer 2
savepoint sp3;
select transfer(3,'12345678902');
rollback to savepoint sp3;

-- Verifikasi Batal Booking
savepoint sp4;
select * from booking;
select * from booking_detail;
select batal_booking(3);
rollback to savepoint sp4;
	
-- Testing Batal Booking
select batal_booking(1);
savepoint sp5;	

-- Verifikasi Selesai Booking
select * from booking;
select * from booking_detail;
select selesai_booking(2);
rollback to savepoint sp5;

-- Testing Selesai Booking
select selesai_booking(3);
select * from history_fasilitas;
select * from fasilitas;
savepoint sp6;	

commit;
rollback;

begin transaction;
select buat_booking(6,2,timestamp '2019-12-01 08:00:00',timestamp '2019-12-01 10:00:00');
select buat_booking(7,3,timestamp '2019-12-01 00:00:00',timestamp '2019-12-30 00:00:00');
select buat_booking(8,4,timestamp '2019-12-01 00:00:00',timestamp '2019-12-04 00:00:00');
select transfer(5,'12345678902');
select * from booking;
select * from booking_detail;
select * from penyewa;
select * from history_penyewa;
select batal_booking(2);
select selesai_booking(1);
commit;
rollback;

-- Select Table

select 
penyewa.nama as penyewa,
pengelola.nama as pengelola,
nama_gor as gor,
alamat_gor as alamat,
cabor.nama as olahraga,
booking_detail.tgl_pinjam,
booking_detail.tgl_selesai,
biaya
from history_penyewa
inner join penyewa on penyewa.id = history_penyewa.penyewa_id
inner join booking_detail on booking_detail.booking_id = history_penyewa.booking_id
inner join fasilitas on fasilitas.id = booking_detail.fasilitas_id
inner join cabor on cabor.id = fasilitas.cabor_id
inner join pengelola on pengelola.id = fasilitas.pengelola_id;

-- Studi Kasus

begin transaction;

select * from penyewa;
select * from cabor;
select * from fasilitas;
select * from pengelola;
select buat_booking(6,1,timestamp '2019-12-01 08:00:00',timestamp '2019-12-01 10:00:00');
select * from booking_detail;
select batal_booking(2);
select buat_booking(6,2,timestamp '2019-12-01 08:00:00',timestamp '2019-12-01 10:00:00');
select transfer(1,'12345678901');
select * from member;
select * from booking_detail;
select * from history_fasilitas;
select * from selesai_booking(1);
rollback;