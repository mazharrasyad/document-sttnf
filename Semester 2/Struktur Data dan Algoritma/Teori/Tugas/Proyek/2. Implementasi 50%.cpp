#include <iostream>

using namespace std;

int main()
{
  // <----- Deklarasi ----->
  int menu_utama;
  int menu_daftar;
  int menu_transaksi;
  int data;
  string data2;
  // <----- End Deklarasi ----->

  // <----- Menu Utama ----->
  menu_utama:
  cout << endl << "---------- Aplikasi Untuk Pemulung ----------" << endl << endl;

  cout << "1. Daftar Pemulung" << endl;
  cout << "2. Transaksi Barang" << endl;
  cout << "3. Keluar" << endl << endl;

  cout << "Masukkan Pilihan : ";
  cin >> menu_utama;

  switch (menu_utama)
  {
    // <----- Menu Daftar Pemulung ----->
    case 1:
      menu_daftar:
      cout << endl << "---------- Daftar Pemulung ----------" << endl << endl;

      cout << "< 'Data Pemulung' >" << endl << endl;

      cout << "1. Pencarian Data Pemulung" << endl;
      cout << "2. Pengurutan Data Pemulung" << endl;
      cout << "3. Kembali" << endl << endl;

      cout << "Masukkan Pilihan : ";
      cin >> menu_daftar;

      switch (menu_daftar)
      {
        case 1:
          cout << endl << "---------- Pencarian Data Pemulung ----------" << endl << endl;

          cout << "Masukkan Data Yang Dicari = ";
          cin >> data2;

          cout << endl << "< 'Data Yang Dicari' >" << endl << endl;

          cout << "Tekan Untuk Melanjutkan...";
          cin.ignore();
          cin.get();

          goto menu_daftar;
          break;

        case 2:
          cout << endl << "---------- Pengurutan Data Pemulung ----------" << endl << endl;

          cout << "Masukkan Data Yang Diurutkan = ";
          cin >> data2;

          cout << endl << "< 'Data Yang Diurutkan' >" << endl << endl;

          cout << "Tekan Untuk Melanjutkan...";
          cin.ignore();
          cin.get();

          goto menu_daftar;
          break;

        case 3:
          goto menu_utama;
          break;

        default:
          cout << endl << "---------- Pilihan Tidak Tersedia ----------" << endl << endl;
          cout << "Tekan Untuk Melanjutkan...";
          cin.ignore();
          cin.get();
          goto menu_daftar;
          break;
      }

      goto menu_daftar;
      break;
      // <----- End Menu Daftar Pemulung ----->

    // <----- Menu Transaksi Barang ----->
    case 2:
      menu_transaksi:
      cout << endl << "---------- Transaksi Barang ----------" << endl << endl;

      cout << "< 'Data Barang' >" << endl << endl;

      cout << "1. Perhitungan Data Barang" << endl;
      cout << "2. Pencarian Data Barang" << endl;
      cout << "3. Pengurutan Data Barang" << endl;
      cout << "4. Kembali" << endl << endl;

      cout << "Masukkan Pilihan : ";
      cin >> menu_transaksi;

      switch (menu_transaksi)
      {
        case 1:
          cout << endl << "---------- Perhitungan Data Barang ----------" << endl << endl;

          cout << "Masukkan Nama Barang = ";
          cin >> data2;

          cout << "Masukkan Berat Barang Dalam KG = ";
          cin >> data;

          cout << endl << "< 'Data Yang Dihitung' >" << endl << endl;

          cout << "Tekan Untuk Melanjutkan...";
          cin.ignore();
          cin.get();

          goto menu_transaksi;
          break;

        case 2:
          cout << endl << "---------- Pencarian Data Barang ----------" << endl << endl;

          cout << "Masukkan Data Yang Dicari = ";
          cin >> data2;

          cout << endl << "< 'Data Yang Dicari' >" << endl << endl;

          cout << "Tekan Untuk Melanjutkan...";
          cin.ignore();
          cin.get();

          goto menu_transaksi;
          break;

        case 3:
          cout << endl << "---------- Pengurutan Data Barang ----------" << endl << endl;

          cout << "Masukkan Data Yang Diurutkan = ";
          cin >> data2;

          cout << endl << "< 'Data Yang Diurutkan' >" << endl << endl;

          cout << "Tekan Untuk Melanjutkan...";
          cin.ignore();
          cin.get();

          goto menu_transaksi;
          break;

        case 4:
          goto menu_utama;
          break;

        default:
          cout << endl << "---------- Pilihan Tidak Tersedia ----------" << endl << endl;
          cout << "Tekan Untuk Melanjutkan...";
          cin.ignore();
          cin.get();
          goto menu_transaksi;
          break;
      }

      goto menu_transaksi;
      break;
      // <----- End Menu Transaksi Barang ----->

    // <----- Keluar Program ----->
    case 3:
      cout << endl << "---------- Terima Kasih ----------" << endl;
      break;
      // <----- End Keluar Program ----->

    // <----- Tidak Ada Pilihan ----->
    default:
      cout << endl << "---------- Pilihan Tidak Tersedia ----------" << endl << endl;
      cout << "Tekan Untuk Melanjutkan...";
      cin.ignore();
      cin.get();
      goto menu_utama;
      break;
      // <----- End Tidak Ada Pilihan ----->
  }
  // <----- End Menu Utama ----->
}
