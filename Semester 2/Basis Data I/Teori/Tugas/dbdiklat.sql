-- phpMyAdmin SQL Dump
-- version 4.6.4
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Nov 01, 2017 at 12:39 AM
-- Server version: 10.1.9-MariaDB-log
-- PHP Version: 7.0.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `dtu2017v`
--

-- --------------------------------------------------------

--
-- Table structure for table `absensi_diklat`
--

CREATE TABLE `absensi_diklat` (
  `id` int(11) NOT NULL,
  `pegawai_nik` varchar(20) NOT NULL,
  `tanggal` date DEFAULT NULL,
  `sesi_1` int(11) DEFAULT NULL,
  `sesi_2` int(11) DEFAULT NULL,
  `peldiklat_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `absensi_diklat`
--

INSERT INTO `absensi_diklat` (`id`, `pegawai_nik`, `tanggal`, `sesi_1`, `sesi_2`, `peldiklat_id`) VALUES
(1, '03020786002', '2016-07-27', 1, 1, 2),
(2, '03101179001', '2016-07-27', 1, 1, 2),
(3, '03110780002', '2016-07-27', 1, 1, 2),
(4, '04100781001', '2016-07-27', 1, 1, 2),
(5, '04200576001', '2016-07-27', 1, 1, 2),
(6, '04010188005', '2016-07-27', 1, 1, 2),
(7, '04100384001', '2016-07-27', 1, 1, 2),
(8, '04200788001', '2016-07-27', 1, 1, 2),
(9, '04100292001', '2016-07-27', 1, 1, 2),
(10, '04150186001', '2016-07-27', 0, 1, 2),
(16, '03020786002', '2016-07-28', 1, 1, 2),
(17, '03101179001', '2016-07-28', 1, 1, 2),
(18, '03110780002', '2016-07-28', 1, 1, 2),
(19, '04100781001', '2016-07-28', 1, 1, 2),
(20, '04200576001', '2016-07-28', 0, 1, 2),
(21, '04010188005', '2016-07-28', 1, 1, 2),
(22, '04100384001', '2016-07-28', 1, 1, 2),
(23, '04200788001', '2016-07-28', 1, 1, 2),
(24, '04100292001', '2016-07-28', 1, 1, 2),
(25, '04150186001', '2016-07-28', 1, 1, 2),
(31, '03020786002', '2016-07-29', 1, 1, 2),
(32, '03101179001', '2016-07-29', 1, 1, 2),
(33, '03110780002', '2016-07-29', 1, 1, 2),
(34, '04100781001', '2016-07-29', 1, 1, 2),
(35, '04200576001', '2016-07-29', 1, 1, 2),
(36, '04010188005', '2016-07-29', 1, 1, 2),
(37, '04100384001', '2016-07-29', 1, 1, 2),
(38, '04200788001', '2016-07-29', 1, 1, 2),
(39, '04100292001', '2016-07-29', 1, 1, 2),
(40, '04150186001', '2016-07-29', 1, 1, 2);

-- --------------------------------------------------------

--
-- Table structure for table `anggaran_diklat`
--

CREATE TABLE `anggaran_diklat` (
  `id` int(11) NOT NULL,
  `tahun` int(11) DEFAULT NULL,
  `total_anggaran` double DEFAULT NULL,
  `total_realisasi` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `anggaran_diklat`
--

INSERT INTO `anggaran_diklat` (`id`, `tahun`, `total_anggaran`, `total_realisasi`) VALUES
(1, 2016, 2500000, 0);

-- --------------------------------------------------------

--
-- Table structure for table `diklat`
--

CREATE TABLE `diklat` (
  `id` int(11) NOT NULL,
  `nama` varchar(45) DEFAULT NULL,
  `deskripsi` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `diklat`
--

INSERT INTO `diklat` (`id`, `nama`, `deskripsi`) VALUES
(1, 'Kearsipan Dinas', 'kearsipan dinas'),
(2, 'Toefl iBT Preparation', 'toefl ibt'),
(3, 'Desain dan Pengelolaan Database', 'desain database'),
(4, 'Pemrograman Web Dinamis', 'pemrograman web');

-- --------------------------------------------------------

--
-- Table structure for table `materi`
--

CREATE TABLE `materi` (
  `id` int(11) NOT NULL,
  `nama` varchar(45) DEFAULT NULL,
  `deskripsi` text,
  `diklat_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `materi`
--

INSERT INTO `materi` (`id`, `nama`, `deskripsi`, `diklat_id`) VALUES
(1, 'Penataan Berkas', 'pemberkasan', 1),
(2, 'Program Arsip Vital', 'sistem informasi pemberkasan', 1),
(3, 'Retensi dan Penyusutan', 'retensi dan pemberkasan', 1),
(4, 'Desain Database', 'desain rdbms', 3),
(5, 'Pemrograman Database', 'sql', 3),
(6, 'Reading', 'reading', 2),
(7, 'Grammer', 'grammer', 2),
(8, 'Conversation', 'conversation', 2);

-- --------------------------------------------------------

--
-- Table structure for table `narasumber`
--

CREATE TABLE `narasumber` (
  `id` int(11) NOT NULL,
  `nama` varchar(45) DEFAULT NULL,
  `gender` char(1) DEFAULT NULL,
  `tmp_lahir` varchar(30) DEFAULT NULL,
  `tgl_lahir` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `narasumber`
--

INSERT INTO `narasumber` (`id`, `nama`, `gender`, `tmp_lahir`, `tgl_lahir`) VALUES
(1, 'Dona Katarina', 'P', 'Jakarta', '1980-01-01'),
(2, 'David Drinkwater', 'L', 'London', '1982-02-20'),
(3, 'Agus Riyadi', 'L', 'Klaten', '1982-03-11'),
(4, 'Faiz Fikri', 'L', 'Jakarta', '1983-04-14'),
(5, 'Alissa Milano', 'P', 'Milan', '1985-05-12'),
(6, 'Budiman Ahmad', 'L', 'Bogor', '1986-12-16');

-- --------------------------------------------------------

--
-- Table structure for table `pegawai`
--

CREATE TABLE `pegawai` (
  `nik` varchar(20) NOT NULL,
  `nama` varchar(45) DEFAULT NULL,
  `gender` char(1) DEFAULT NULL,
  `tmp_lahir` varchar(30) DEFAULT NULL,
  `tgl_lahir` date DEFAULT NULL,
  `email` varchar(45) DEFAULT NULL,
  `unit_kerja_id` int(11) NOT NULL,
  `gaji` double DEFAULT NULL,
  `jml_anak` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `pegawai`
--

INSERT INTO `pegawai` (`nik`, `nama`, `gender`, `tmp_lahir`, `tgl_lahir`, `email`, `unit_kerja_id`, `gaji`, `jml_anak`) VALUES
('03020786002', 'Glagah Putih', 'L', 'Klaten', '1986-07-02', 'glagahputih@yahoo.com', 1, 6500, 0),
('03101179001', 'Agung Sedayu', 'L', 'Yogyakarta', '1979-11-10', 'sedayu.agung79@gmail.com', 1, 6500, 3),
('03110780002', 'Sekar Mirah', 'P', 'Yogyakarta', '1980-07-11', 'sekarmirah@gmail.com', 1, 6500, 3),
('04010188005', 'Rara Wulan', 'P', 'Klaten', '1988-01-01', 'wulanr88@yahoo.com', 3, 6000, 0),
('04100292001', 'Raden Rangga', 'L', 'Jakarta', '1992-02-10', 'rangga92@gmail.com', 4, 5000, 1),
('04100384001', 'Faiz Fikri', 'L', 'Jakarta', '1984-03-10', 'faiz.fikri@yahoo.com', 3, 6000, 1),
('04100781001', 'Pandan Wangi', 'P', 'Solo', '1981-07-10', 'wangi76@gmail.com', 2, 5500, 2),
('04150186001', 'Suherman Burhan', 'L', 'Padang', '1986-01-15', 'suherman.burhan@gmail.com', 4, 5000, 2),
('04200576001', 'Swandaru Geni', 'L', 'Solo', '1976-05-20', 'swandaru.geni@gmail.com', 2, 5500, 2),
('04200788001', 'Annisa Dinar', 'P', 'Depok', '1988-07-20', 'dinar.nisa@gmail.com', 3, 6000, 0);

-- --------------------------------------------------------

--
-- Table structure for table `pelaksanaan_diklat`
--

CREATE TABLE `pelaksanaan_diklat` (
  `id` int(11) NOT NULL,
  `tgl_mulai` date DEFAULT NULL,
  `tgl_selesai` date DEFAULT NULL,
  `jamlat` int(11) DEFAULT NULL,
  `nik_pic` varchar(20) DEFAULT NULL,
  `budget` double DEFAULT NULL,
  `tahun` int(11) DEFAULT NULL,
  `angkatan` int(11) DEFAULT NULL,
  `jml_peserta` int(11) DEFAULT NULL,
  `max_peserta` int(11) DEFAULT NULL,
  `diklat_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `pelaksanaan_diklat`
--

INSERT INTO `pelaksanaan_diklat` (`id`, `tgl_mulai`, `tgl_selesai`, `jamlat`, `nik_pic`, `budget`, `tahun`, `angkatan`, `jml_peserta`, `max_peserta`, `diklat_id`) VALUES
(1, '2016-07-18', '2016-07-22', 52, '04010188005', 135000, 2016, 3, 27, 30, 2),
(2, '2016-07-25', '2016-07-29', 56, '4150186001', 155000, 2016, 3, 26, 30, 3),
(3, '2016-08-01', '2016-08-05', 48, '04200576001', 125000, 2016, 2, 25, 30, 1);

-- --------------------------------------------------------

--
-- Table structure for table `pengajar_diklat`
--

CREATE TABLE `pengajar_diklat` (
  `id` int(11) NOT NULL,
  `peldiklat_id` int(11) NOT NULL,
  `materi_id` int(11) NOT NULL,
  `narasumber_id` int(11) NOT NULL,
  `jamlat` int(11) DEFAULT NULL,
  `nilai` double DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `pengajar_diklat`
--

INSERT INTO `pengajar_diklat` (`id`, `peldiklat_id`, `materi_id`, `narasumber_id`, `jamlat`, `nilai`) VALUES
(1, 1, 7, 1, 20, 84),
(2, 1, 6, 1, 20, 89),
(3, 1, 8, 2, 12, 80),
(4, 2, 4, 3, 20, 88),
(5, 2, 5, 4, 36, 90),
(6, 3, 1, 5, 16, 80),
(7, 3, 2, 5, 20, 81),
(8, 3, 3, 6, 20, 88);

-- --------------------------------------------------------

--
-- Table structure for table `peserta_diklat`
--

CREATE TABLE `peserta_diklat` (
  `pegawai_nik` varchar(20) NOT NULL,
  `peldiklat_id` int(11) NOT NULL,
  `total_nilai` double DEFAULT NULL,
  `status` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `peserta_diklat`
--

INSERT INTO `peserta_diklat` (`pegawai_nik`, `peldiklat_id`, `total_nilai`, `status`) VALUES
('03020786002', 1, 80.67, 'Lulus'),
('03020786002', 2, 81.54, 'Lulus'),
('03020786002', 3, 81.54, 'Lulus'),
('03101179001', 1, 61.71, 'TIDAK LULUS'),
('03101179001', 2, 92.87, 'Lulus'),
('03101179001', 3, 81.54, 'Lulus'),
('03110780002', 1, 66.54, 'TIDAK LULUS'),
('03110780002', 2, 89.54, 'Lulus'),
('03110780002', 3, 81.54, 'Lulus'),
('04010188005', 1, 81.54, 'Lulus'),
('04010188005', 2, 81.54, 'Lulus'),
('04010188005', 3, 81.54, 'Lulus'),
('04100292001', 1, 76.25, 'Lulus'),
('04100292001', 2, 81.54, 'Lulus'),
('04100292001', 3, 96.61, 'Lulus'),
('04100384001', 1, 81.54, 'Lulus'),
('04100384001', 2, 81.54, 'Lulus'),
('04100384001', 3, 66.64, 'TIDAK LULUS'),
('04100781001', 1, 81.54, 'Lulus'),
('04100781001', 2, 81.54, 'Lulus'),
('04100781001', 3, 81.54, 'Lulus'),
('04150186001', 1, 81.54, 'Lulus'),
('04150186001', 2, 81.54, 'Lulus'),
('04150186001', 3, 81.54, 'Lulus'),
('04200788001', 1, 91.68, 'Lulus'),
('04200788001', 2, 68.33, 'TIDAK LULUS'),
('04200788001', 3, 89.54, 'Lulus');

-- --------------------------------------------------------

--
-- Table structure for table `unit_kerja`
--

CREATE TABLE `unit_kerja` (
  `id` int(11) NOT NULL,
  `kode` varchar(16) DEFAULT NULL,
  `nama` varchar(100) DEFAULT NULL,
  `alamat` varchar(100) DEFAULT NULL,
  `kota` varchar(30) DEFAULT NULL,
  `budget` double DEFAULT NULL,
  `nik_kepala` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `unit_kerja`
--

INSERT INTO `unit_kerja` (`id`, `kode`, `nama`, `alamat`, `kota`, `budget`, `nik_kepala`) VALUES
(1, 'DJP', 'Direktorat Jenderal Pajak', 'Jl. Jend. Gatot Subroto No. 40-42', 'Jakarta', 3000, '03101179001'),
(2, 'DJBC', 'Direktorat Jenderal Bea Cukai', 'Jl. Ahmad Yani By Pass, Rawamangun ', 'Jakarta', 3500, '04200576001'),
(3, 'DJPU', 'Direktorat Jenderal Pengelolaan Utang', 'Gd. Frans Seda, Jl. Dr. Wahidin Raya No. 1', 'Jakarta', 2500, '04100384001'),
(4, 'BPPK', 'Badan Pendidikan dan Pelatihan Keuangan', 'Jl. Purnawarman No. 99 Kebayoran Baru', 'Jakarta', 500, '04150186001');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `absensi_diklat`
--
ALTER TABLE `absensi_diklat`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_absensi_diklat_pegawai1_idx` (`pegawai_nik`),
  ADD KEY `fk_absensi_diklat_diklat1_idx` (`peldiklat_id`);

--
-- Indexes for table `anggaran_diklat`
--
ALTER TABLE `anggaran_diklat`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `diklat`
--
ALTER TABLE `diklat`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `materi`
--
ALTER TABLE `materi`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_materi_diklat1_idx` (`diklat_id`);

--
-- Indexes for table `narasumber`
--
ALTER TABLE `narasumber`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `pegawai`
--
ALTER TABLE `pegawai`
  ADD PRIMARY KEY (`nik`),
  ADD KEY `fk_pegawai_unit_kerja_idx` (`unit_kerja_id`);

--
-- Indexes for table `pelaksanaan_diklat`
--
ALTER TABLE `pelaksanaan_diklat`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_pelaksanan_diklat_diklat1_idx` (`diklat_id`);

--
-- Indexes for table `pengajar_diklat`
--
ALTER TABLE `pengajar_diklat`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_pengajar_diklat_diklat1_idx` (`peldiklat_id`),
  ADD KEY `fk_pengajar_diklat_materi1_idx` (`materi_id`),
  ADD KEY `fk_pengajar_diklat_narasumber1_idx` (`narasumber_id`);

--
-- Indexes for table `peserta_diklat`
--
ALTER TABLE `peserta_diklat`
  ADD PRIMARY KEY (`pegawai_nik`,`peldiklat_id`),
  ADD KEY `fk_pegawai_has_diklat_diklat1_idx` (`peldiklat_id`),
  ADD KEY `fk_pegawai_has_diklat_pegawai1_idx` (`pegawai_nik`);

--
-- Indexes for table `unit_kerja`
--
ALTER TABLE `unit_kerja`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `kode_UNIQUE` (`kode`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `absensi_diklat`
--
ALTER TABLE `absensi_diklat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=41;
--
-- AUTO_INCREMENT for table `anggaran_diklat`
--
ALTER TABLE `anggaran_diklat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `diklat`
--
ALTER TABLE `diklat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT for table `materi`
--
ALTER TABLE `materi`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
--
-- AUTO_INCREMENT for table `narasumber`
--
ALTER TABLE `narasumber`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT for table `pelaksanaan_diklat`
--
ALTER TABLE `pelaksanaan_diklat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- AUTO_INCREMENT for table `pengajar_diklat`
--
ALTER TABLE `pengajar_diklat`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
--
-- AUTO_INCREMENT for table `unit_kerja`
--
ALTER TABLE `unit_kerja`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `absensi_diklat`
--
ALTER TABLE `absensi_diklat`
  ADD CONSTRAINT `fk_absensi_diklat_diklat1` FOREIGN KEY (`peldiklat_id`) REFERENCES `pelaksanaan_diklat` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_absensi_diklat_pegawai1` FOREIGN KEY (`pegawai_nik`) REFERENCES `pegawai` (`nik`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `materi`
--
ALTER TABLE `materi`
  ADD CONSTRAINT `fk_materi_diklat1` FOREIGN KEY (`diklat_id`) REFERENCES `diklat` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `pegawai`
--
ALTER TABLE `pegawai`
  ADD CONSTRAINT `fk_pegawai_unit_kerja` FOREIGN KEY (`unit_kerja_id`) REFERENCES `unit_kerja` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `pelaksanaan_diklat`
--
ALTER TABLE `pelaksanaan_diklat`
  ADD CONSTRAINT `fk_pelaksanan_diklat_diklat1` FOREIGN KEY (`diklat_id`) REFERENCES `diklat` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `pengajar_diklat`
--
ALTER TABLE `pengajar_diklat`
  ADD CONSTRAINT `fk_pengajar_diklat_diklat1` FOREIGN KEY (`peldiklat_id`) REFERENCES `pelaksanaan_diklat` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_pengajar_diklat_materi1` FOREIGN KEY (`materi_id`) REFERENCES `materi` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_pengajar_diklat_narasumber1` FOREIGN KEY (`narasumber_id`) REFERENCES `narasumber` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `peserta_diklat`
--
ALTER TABLE `peserta_diklat`
  ADD CONSTRAINT `fk_pegawai_has_diklat_diklat1` FOREIGN KEY (`peldiklat_id`) REFERENCES `pelaksanaan_diklat` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_pegawai_has_diklat_pegawai1` FOREIGN KEY (`pegawai_nik`) REFERENCES `pegawai` (`nik`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

