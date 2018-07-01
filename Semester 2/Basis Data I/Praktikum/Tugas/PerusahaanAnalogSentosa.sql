-- phpMyAdmin SQL Dump
-- version 4.8.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Jul 01, 2018 at 11:10 PM
-- Server version: 10.1.31-MariaDB
-- PHP Version: 5.6.35

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `PerusahaanAnalogSentosa`
--

-- --------------------------------------------------------

--
-- Table structure for table `departemen`
--

CREATE TABLE `departemen` (
  `ID` int(11) NOT NULL,
  `Nama` varchar(65) NOT NULL,
  `Lokasi` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `departemen`
--

INSERT INTO `departemen` (`ID`, `Nama`, `Lokasi`) VALUES
(1, 'Departemen Keuangan', 'Jakarta'),
(2, 'Departemen Kewirausahaan', 'Bogor'),
(3, 'Departemen Teknologi', 'Depok');

-- --------------------------------------------------------

--
-- Table structure for table `Direktur`
--

CREATE TABLE `Direktur` (
  `ID` int(11) NOT NULL,
  `Nama` varchar(50) NOT NULL,
  `Tempat` varchar(30) NOT NULL,
  `Tanggal_lahir` date NOT NULL,
  `JK` char(1) DEFAULT NULL,
  `alamat` varchar(20) DEFAULT NULL,
  `Nomor_HP` varchar(13) NOT NULL,
  `id_Departemen` int(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Direktur`
--

INSERT INTO `Direktur` (`ID`, `Nama`, `Tempat`, `Tanggal_lahir`, `JK`, `alamat`, `Nomor_HP`, `id_Departemen`) VALUES
(1, 'Muhammad Azhar', 'Cilodong', '1992-02-29', 'L', 'Cilodong', '089524952592', 1),
(2, 'Fachrur Rozzy', 'Depok', '1945-02-10', 'L', 'RTM', '089612382394', 2),
(4, 'Herlina', 'Bekasi', '2001-01-10', 'P', 'Margonda', '082142932394', 3);

-- --------------------------------------------------------

--
-- Stand-in structure for view `dp_pg`
-- (See below for the actual view)
--
CREATE TABLE `dp_pg` (
`ID` int(11)
,`Nama` varchar(65)
,`Lokasi` varchar(20)
);

-- --------------------------------------------------------

--
-- Stand-in structure for view `ES_BUAH`
-- (See below for the actual view)
--
CREATE TABLE `ES_BUAH` (
`Nama` varchar(50)
,`jumlah` varchar(35)
,`Proyek` varchar(45)
,`Direktur` varchar(50)
);

-- --------------------------------------------------------

--
-- Table structure for table `General_manager`
--

CREATE TABLE `General_manager` (
  `ID` int(11) NOT NULL,
  `Nama` varchar(50) NOT NULL,
  `Tempat` varchar(30) NOT NULL,
  `Tanggal_lahir` date NOT NULL,
  `JK` char(1) DEFAULT NULL,
  `Alamat` varchar(50) NOT NULL,
  `Nomor_HP` varchar(13) DEFAULT NULL,
  `id_Direktur` int(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `General_manager`
--

INSERT INTO `General_manager` (`ID`, `Nama`, `Tempat`, `Tanggal_lahir`, `JK`, `Alamat`, `Nomor_HP`, `id_Direktur`) VALUES
(1, 'Hera Karmila', 'Jogja', '1996-04-11', 'P', 'Citayam', '089623545829', 4),
(2, 'Shidqi R', 'Ambon', '1999-10-09', 'L', 'Jakarta', '082153819231', 1);

-- --------------------------------------------------------

--
-- Table structure for table `Investor`
--

CREATE TABLE `Investor` (
  `ID` int(11) NOT NULL,
  `Nama` varchar(50) NOT NULL,
  `jumlah` varchar(35) NOT NULL,
  `Nomer_Telfon` varchar(12) DEFAULT NULL,
  `Proyek_id` int(11) DEFAULT NULL,
  `Direktur_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Investor`
--

INSERT INTO `Investor` (`ID`, `Nama`, `jumlah`, `Nomer_Telfon`, `Proyek_id`, `Direktur_id`) VALUES
(1, 'Muhammad Fadhil Hilmi', 'Rp. 500.000.000', '089691565266', 1, 2),
(2, 'Muhammad Sholihin', 'Rp. 100.000.000', '085821248290', 3, 4),
(3, 'Ahmad Fathan S', 'Rp. 250.000.000', '082156720429', 3, 1),
(4, 'Ardith Luthfiawan', 'Rp. 450.000.000', '082153912495', 5, 1),
(5, 'Enrico Alkalas', 'Rp. 680.000.000', '083823010249', 4, 1);

-- --------------------------------------------------------

--
-- Table structure for table `pegawai`
--

CREATE TABLE `pegawai` (
  `ID` int(11) NOT NULL,
  `Nama` varchar(50) NOT NULL,
  `Tempat` varchar(30) NOT NULL,
  `Tanggal_lahir` date NOT NULL,
  `gaji` varchar(30) DEFAULT NULL,
  `JK` char(1) DEFAULT NULL,
  `Jabatan` varchar(25) NOT NULL,
  `Nomor_HP` varchar(13) NOT NULL,
  `Departemen_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `pegawai`
--

INSERT INTO `pegawai` (`ID`, `Nama`, `Tempat`, `Tanggal_lahir`, `gaji`, `JK`, `Jabatan`, `Nomor_HP`, `Departemen_id`) VALUES
(1, 'Nabilah Fajar Utami', 'Depok', '1998-11-24', 'Rp. 5.300.000', 'P', 'Pegawai Keuangan', '089662603830', 1),
(2, 'Raihan Sabiq R', 'Depok', '1998-10-10', 'Rp. 7.000.000', 'L', 'Pegawai Teknologi', '085779273169', 3),
(3, 'Muhammad Rizki Herfian', 'Depok', '1998-06-10', 'Rp. 5.000.000', 'L', 'Pegawai Kewirausahaan', '0895331637524', 2),
(4, 'Muhammad Syahputra', 'Bojonggede', '1996-10-20', 'Rp. 3.000.000', 'L', 'Pegawai Teknologi', '083129542930', 3),
(5, 'Muhammad Naufal Arif W', 'Depok', '1998-05-20', 'Rp. 8.920.000', 'L', 'Pegawai Keuangan', '085888782939', 1),
(6, 'Henry Hassan', 'Jakarta', '1997-04-05', 'Rp. 5.000.000', 'L', 'Pegawai Kewirausahaan', '089519020331', 2),
(7, 'Hanna Annisa', 'Bekasi', '1995-07-27', 'Rp. 7.000.000', 'P', 'Pegawai Keuangan', '085323405921', 1),
(8, 'Tria Handayani', 'Jakarta', '1997-08-10', 'Rp. 8.357.000', 'P', 'Pegawai Keuangan', '082106210693', 1);

-- --------------------------------------------------------

--
-- Table structure for table `Proyek`
--

CREATE TABLE `Proyek` (
  `ID` int(11) NOT NULL,
  `Nama` varchar(45) NOT NULL,
  `Tanggal_awal` datetime NOT NULL,
  `Tanggal_akhir` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Proyek`
--

INSERT INTO `Proyek` (`ID`, `Nama`, `Tanggal_awal`, `Tanggal_akhir`) VALUES
(1, 'Proyek Database', '2018-04-27 00:00:00', '2018-04-28 00:00:00'),
(2, 'Proyek Website', '2018-04-28 00:00:00', '2018-04-29 00:00:00'),
(3, 'Proyek Infrastruktur', '2018-05-01 00:00:00', '2018-06-30 00:00:00'),
(4, 'Proyek Produk Penambangan', '2018-05-01 00:00:00', '2018-10-31 00:00:00'),
(5, 'Proyek Aplikasi Keuangan', '2018-06-20 00:00:00', '2018-07-10 00:00:00');

-- --------------------------------------------------------

--
-- Stand-in structure for view `Proyek_Akhiran_N`
-- (See below for the actual view)
--
CREATE TABLE `Proyek_Akhiran_N` (
`ID` int(11)
,`Nama` varchar(45)
,`Tanggal_awal` datetime
,`Tanggal_akhir` datetime
);

-- --------------------------------------------------------

--
-- Stand-in structure for view `Proyek_Virtual`
-- (See below for the actual view)
--
CREATE TABLE `Proyek_Virtual` (
`ID` int(11)
,`Nama` varchar(45)
,`Tanggal_awal` datetime
,`Tanggal_akhir` datetime
);

-- --------------------------------------------------------

--
-- Structure for view `dp_pg`
--
DROP TABLE IF EXISTS `dp_pg`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `dp_pg`  AS  select `departemen`.`ID` AS `ID`,`departemen`.`Nama` AS `Nama`,`departemen`.`Lokasi` AS `Lokasi` from `departemen` where `departemen`.`ID` in (select `pegawai`.`Departemen_id` from `pegawai` where (`pegawai`.`gaji` between 'Rp. 3.000.000' and 'Rp. 7.000.000')) ;

-- --------------------------------------------------------

--
-- Structure for view `ES_BUAH`
--
DROP TABLE IF EXISTS `ES_BUAH`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `ES_BUAH`  AS  select `Investor`.`Nama` AS `Nama`,`Investor`.`jumlah` AS `jumlah`,`Proyek`.`Nama` AS `Proyek`,`Direktur`.`Nama` AS `Direktur` from ((`Investor` join `Proyek` on((`Investor`.`Proyek_id` = `Proyek`.`ID`))) join `Direktur` on((`Investor`.`Direktur_id` = `Direktur`.`ID`))) ;

-- --------------------------------------------------------

--
-- Structure for view `Proyek_Akhiran_N`
--
DROP TABLE IF EXISTS `Proyek_Akhiran_N`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `Proyek_Akhiran_N`  AS  select `Proyek`.`ID` AS `ID`,`Proyek`.`Nama` AS `Nama`,`Proyek`.`Tanggal_awal` AS `Tanggal_awal`,`Proyek`.`Tanggal_akhir` AS `Tanggal_akhir` from `Proyek` where (`Proyek`.`Nama` like '%n') ;

-- --------------------------------------------------------

--
-- Structure for view `Proyek_Virtual`
--
DROP TABLE IF EXISTS `Proyek_Virtual`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `Proyek_Virtual`  AS  select `Proyek`.`ID` AS `ID`,`Proyek`.`Nama` AS `Nama`,`Proyek`.`Tanggal_awal` AS `Tanggal_awal`,`Proyek`.`Tanggal_akhir` AS `Tanggal_akhir` from `Proyek` ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `departemen`
--
ALTER TABLE `departemen`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `Direktur`
--
ALTER TABLE `Direktur`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `Nomor_HP` (`Nomor_HP`),
  ADD KEY `id_Departemen` (`id_Departemen`);

--
-- Indexes for table `General_manager`
--
ALTER TABLE `General_manager`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `Nomor_HP` (`Nomor_HP`),
  ADD KEY `id_Direktur` (`id_Direktur`);

--
-- Indexes for table `Investor`
--
ALTER TABLE `Investor`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `No_Telp` (`Nomer_Telfon`),
  ADD KEY `Proyek_id` (`Proyek_id`),
  ADD KEY `Direktur_id` (`Direktur_id`);

--
-- Indexes for table `pegawai`
--
ALTER TABLE `pegawai`
  ADD PRIMARY KEY (`ID`),
  ADD UNIQUE KEY `Nomor_HP` (`Nomor_HP`),
  ADD KEY `Departemen_id` (`Departemen_id`);

--
-- Indexes for table `Proyek`
--
ALTER TABLE `Proyek`
  ADD PRIMARY KEY (`ID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Direktur`
--
ALTER TABLE `Direktur`
  ADD CONSTRAINT `Direktur_ibfk_1` FOREIGN KEY (`id_Departemen`) REFERENCES `departemen` (`ID`);

--
-- Constraints for table `General_manager`
--
ALTER TABLE `General_manager`
  ADD CONSTRAINT `General_manager_ibfk_1` FOREIGN KEY (`id_Direktur`) REFERENCES `Direktur` (`ID`);

--
-- Constraints for table `Investor`
--
ALTER TABLE `Investor`
  ADD CONSTRAINT `Investor_ibfk_1` FOREIGN KEY (`Proyek_id`) REFERENCES `Proyek` (`ID`),
  ADD CONSTRAINT `Investor_ibfk_2` FOREIGN KEY (`Proyek_id`) REFERENCES `Proyek` (`ID`),
  ADD CONSTRAINT `Investor_ibfk_3` FOREIGN KEY (`Proyek_id`) REFERENCES `Proyek` (`ID`),
  ADD CONSTRAINT `Investor_ibfk_4` FOREIGN KEY (`Direktur_id`) REFERENCES `Direktur` (`ID`);

--
-- Constraints for table `pegawai`
--
ALTER TABLE `pegawai`
  ADD CONSTRAINT `pegawai_ibfk_1` FOREIGN KEY (`Departemen_id`) REFERENCES `departemen` (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
