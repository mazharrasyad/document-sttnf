#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct data_pemulung
{
	int nidp;
	string nama;
	string alamat;
	int poin;
	int peringkat;
	data_pemulung *next;
	data_pemulung *prev;
} *head_pemulung, *tail_pemulung, 
*baru_pemulung, *bantu_pemulung, 
*data1_pemulung, *data2_pemulung, *data3_pemulung,
*data4_pemulung, *data5_pemulung, *data6_pemulung,
*save_pemulung, *simpan_pemulung, *simpan_pemulung_temp, *temp_simpan_pemulung;

struct data_barang
{
	string kode;
	string nama_barang;
	int harga;
	int poin_barang;
	string tingkat;
	data_barang *next;
	data_barang *prev;
} *head_barang, *tail_barang, 
*baru_barang, *bantu_barang, 
*data1_barang, *data2_barang, *data3_barang,
*data4_barang, *data5_barang, *data6_barang,
*save_barang, *simpan_barang, *simpan_barang_temp, *temp_simpan_barang;

void gotoxy(int x, int y);
void Database_Pemulung();
void Relasi_Pemulung();
void Daftar_Pemulung();
void Tampil_Pemulung();
void Cari_Pemulung(int menu_data_cari);
void Sorting_Pemulung();
void Urut_Pemulung(int menu_data_urut, int menu_data_urut_order);
void Database_Barang();
void Relasi_Barang();
void Tampil_Barang();
void Cari_Barang(int menu_barang_cari);
void Sorting_Barang();
void Urut_Barang(int menu_barang_urut, int menu_barang_urut_order);
void Transaksi();

int nidp_isi = 3;
string nama_isi;
string alamat_isi;
int poin_isi;
int peringkat_isi;
int counter = 3;
string kode_isi;
string nama_barang_isi;
int poin_barang_isi;
string tingkat_isi;
int counter_barang = 3;

int main()
{
	Database_Pemulung();
	Relasi_Pemulung();
	Database_Barang();
	Relasi_Barang();

	int menu_utama;
	int menu_data;
	int menu_data_cari;
	int menu_data_urut;
	int menu_data_urut_order;
	int menu_barang;
	int menu_barang_cari;
	int menu_barang_urut;
	int menu_barang_urut_order;
	
	menu_utama:
	system("cls");
	cout << "---------------------------------------------" << endl;
	cout << "|          Aplikasi Untuk Pemulung          |" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "| 1. Data Pemulung                          |" << endl;
	cout << "| 2. Transaksi Barang                       |" << endl;
	cout << "| 3. Bantuan                                |" << endl;
	cout << "| 4. Keluar                                 |" << endl;
	cout << "---------------------------------------------" << endl << endl;

	cout << "Masukkan Pilihan : ";
	cin >> menu_utama;

	switch (menu_utama)
	{
		case 1:
			menu_data:
			system("cls");

			Tampil_Pemulung();

			cout << "---------------------------------------------" << endl;
			cout << "|             Menu Data Pemulung            |" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "| 1. Daftar Data Pemulung                   |" << endl;
			cout << "| 2. Pencarian Data Pemulung                |" << endl;
			cout << "| 3. Pengurutan Data Pemulung               |" << endl;
			cout << "| 4. Kembali                                |" << endl;
			cout << "---------------------------------------------" << endl << endl;

			cout << "Masukkan Pilihan : ";
			cin >> menu_data;

			switch (menu_data)
			{
				case 1:
					system("cls");

					Daftar_Pemulung();

					cout << endl << endl;
					cout << "----------------------------------------------" << endl;
					cout << "|          Data Berhasil Dimasukkan          |" << endl;
					cout << "----------------------------------------------" << endl << endl;
					cout << "Tekan Untuk Melanjutkan...";
					getch();

					goto menu_data;
					break;
					
				case 2:
					menu_data_cari:
					system("cls");
					cout << "---------------------------------------------" << endl;
					cout << "|          Pencarian Data Pemulung          |" << endl;
					cout << "---------------------------------------------" << endl;
					cout << "| 1. Cari NIDP                              |" << endl;
					cout << "| 2. Cari Nama                              |" << endl;
					cout << "| 3. Cari Alamat                            |" << endl;
					cout << "| 4. Cari Poin                              |" << endl;
					cout << "| 5. Cari Peringkat                         |" << endl;
					cout << "| 6. Kembali                                |" << endl;
					cout << "---------------------------------------------" << endl << endl;

					cout << "Masukkan Pilihan : ";
					cin >> menu_data_cari;

					switch(menu_data_cari)
					{
						case 1:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|          Pencarian Data Pemulung Berdasarkan NIDP          |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Pemulung(menu_data_cari);
							getch();
							goto menu_data_cari;
							break;

						case 2:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|          Pencarian Data Pemulung Berdasarkan Nama          |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Pemulung(menu_data_cari);
							getch();
							goto menu_data_cari;
							break;

						case 3:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|         Pencarian Data Pemulung Berdasarkan Alamat         |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Pemulung(menu_data_cari);
							getch();
							goto menu_data_cari;
							break;

						case 4:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|          Pencarian Data Pemulung Berdasarkan Poin          |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Pemulung(menu_data_cari);
							getch();
							goto menu_data_cari;
							break;

						case 5:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|       Pencarian Data Pemulung Berdasarkan Peringkat        |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Pemulung(menu_data_cari);
							getch();
							goto menu_data_cari;
							break;

						case 6:
							goto menu_data;
							break;
							
						default:
							cout << endl;
							cout << "--------------------------------------------" << endl;
							cout << "|          Pilihan Tidak Tersedia          |" << endl;
							cout << "--------------------------------------------" << endl << endl;
							
							cout << "Tekan Untuk Melanjutkan...";
							getch();
							goto menu_data_cari;
							break;
					}
					cout << "Tekan Untuk Melanjutkan...";
					getch();
					goto menu_data;
					break;
					
				case 3:
					menu_data_urut:
					system("cls");
					cout << "---------------------------------------------" << endl;
					cout << "|          Pengurutan Data Pemulung         |" << endl;
					cout << "---------------------------------------------" << endl;
					cout << "| 1. Urutkan NIDP                           |" << endl;
					cout << "| 2. Urutkan Nama                           |" << endl;
					cout << "| 3. Urutkan Alamat                         |" << endl;
					cout << "| 4. Urutkan Poin                           |" << endl;
					cout << "| 5. Urutkan Peringkat                      |" << endl;
					cout << "| 6. Kembali                                |" << endl;
					cout << "---------------------------------------------" << endl << endl;

					cout << "Masukkan Pilihan : ";
					cin >> menu_data_urut;

					switch(menu_data_urut)
					{
						case 1:
							menu_data_urut_order_nidp:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|          Pengurutan Data Pemulung Berdasarkan NIDP         |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
						
							cout << "Masukkan Pilihan : ";
							cin >> menu_data_urut_order;

							switch(menu_data_urut_order)
							{
									case 1:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                                Pengurutan Data Pemulung Berdasarkan NIDP Ascending                                 |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 2:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                                Pengurutan Data Pemulung Berdasarkan NIDP Descending                                |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 3:
										goto menu_data_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut_order_nidp;
										break;
							}
							getch();
							goto menu_data_urut;
							break;

						case 2:
							menu_data_urut_order_nama:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|          Pengurutan Data Pemulung Berdasarkan Nama         |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;

							cout << "Masukkan Pilihan : ";
							cin >> menu_data_urut_order;

							switch(menu_data_urut_order)
							{
									case 1:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                                Pengurutan Data Pemulung Berdasarkan Nama Ascending                                 |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 2:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                                Pengurutan Data Pemulung Berdasarkan Nama Descending                                |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 3:
										goto menu_data_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut_order_nama;
										break;
							}
							getch();
							goto menu_data_urut;
							break;

						case 3:
							menu_data_urut_order_alamat:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|         Pengurutan Data Pemulung Berdasarkan Alamat        |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;

							cout << "Masukkan Pilihan : ";
							cin >> menu_data_urut_order;

							switch(menu_data_urut_order)
							{
									case 1:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                               Pengurutan Data Pemulung Berdasarkan Alamat Ascending                                |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 2:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                               Pengurutan Data Pemulung Berdasarkan Alamat Descending                               |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 3:
										goto menu_data_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut_order_alamat;
										break;
							}
							getch();
							goto menu_data_urut;
							break;

						case 4:
							menu_data_urut_order_poin:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|          Pengurutan Data Pemulung Berdasarkan Poin         |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;

							cout << "Masukkan Pilihan : ";
							cin >> menu_data_urut_order;

							switch(menu_data_urut_order)
							{
									case 1:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                                Pengurutan Data Pemulung Berdasarkan Poin Ascending                                 |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 2:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                                Pengurutan Data Pemulung Berdasarkan Poin Descending                                |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 3:
										goto menu_data_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut_order_poin;
										break;
							}
							getch();
							goto menu_data_urut;
							break;

						case 5:
							menu_data_urut_order_peringkat:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|       Pengurutan Data Pemulung Berdasarkan Peringkat       |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;

							cout << "Masukkan Pilihan : ";
							cin >> menu_data_urut_order;

							switch(menu_data_urut_order)
							{
									case 1:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                              Pengurutan Data Pemulung Berdasarkan Peringkat Ascending                              |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 2:
										system("cls");
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                             Pengurutan Data Pemulung Berdasarkan Peringkat Descending                              |" << endl;
										cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
										Urut_Pemulung(menu_data_urut, menu_data_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut;
										break;
										
									case 3:
										goto menu_data_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_data_urut_order_peringkat;
										break;
							}
							getch();
							goto menu_data_urut;
							break;

						case 6:
							goto menu_data;
							break;
							
						default:
							cout << endl;
							cout << "--------------------------------------------" << endl;
							cout << "|          Pilihan Tidak Tersedia          |" << endl;
							cout << "--------------------------------------------" << endl << endl;
							cout << "Tekan Untuk Melanjutkan...";
							getch();
							goto menu_data_urut;
							break;
					}

					cout << "Tekan Untuk Melanjutkan...";
					getch();

					goto menu_data;
					break;
					
				case 4:
					goto menu_utama;
					break;
					
				default:
					cout << endl;
					cout << "--------------------------------------------" << endl;
					cout << "|          Pilihan Tidak Tersedia          |" << endl;
					cout << "--------------------------------------------" << endl << endl;
					cout << "Tekan Untuk Melanjutkan...";
					getch();
					goto menu_data;
					break;
			}
			goto menu_data;
			break;
			
		case 2:
			menu_barang:
			system("cls");

			Tampil_Barang();

			cout << "---------------------------------------------" << endl;
			cout << "|              Menu Data Barang             |" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "| 1. Perhitungan Data Barang                |" << endl;
			cout << "| 2. Pencarian Data Barang                  |" << endl;
			cout << "| 3. Pengurutan Data Barang                 |" << endl;
			cout << "| 4. Kembali                                |" << endl;
			cout << "---------------------------------------------" << endl << endl;

			cout << "Masukkan Pilihan : ";
			cin >> menu_barang;

			switch (menu_barang)
			{
				case 1:
					system("cls");
					
					Transaksi();

					goto menu_utama;
					break;
					
				case 2:
					menu_barang_cari:
					system("cls");
					cout << "---------------------------------------------" << endl;
					cout << "|           Pencarian Data Barang           |" << endl;
					cout << "---------------------------------------------" << endl;
					cout << "| 1. Cari Kode                              |" << endl;
					cout << "| 2. Cari Nama Barang                       |" << endl;
					cout << "| 3. Cari Harga                             |" << endl;
					cout << "| 4. Cari Poin Barang                       |" << endl;
					cout << "| 5. Cari Tingkat                           |" << endl;
					cout << "| 6. Kembali                                |" << endl;
					cout << "---------------------------------------------" << endl << endl;

					cout << "Masukkan Pilihan : ";
					cin >> menu_barang_cari;

					switch(menu_barang_cari)
					{
						case 1:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|          Pencarian Data Pemulung Berdasarkan Kode          |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Barang(menu_barang_cari);
							getch();
							goto menu_barang_cari;
							break;

						case 2:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|      Pencarian Data Pemulung Berdasarkan Nama Barang       |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Barang(menu_barang_cari);
							getch();
							goto menu_barang_cari;
							break;

						case 3:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|          Pencarian Data Pemulung Berdasarkan Harga         |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Barang(menu_barang_cari);
							getch();
							goto menu_barang_cari;
							break;

						case 4:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|       Pencarian Data Pemulung Berdasarkan Poin Barang      |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Barang(menu_barang_cari);
							getch();
							goto menu_barang_cari;
							break;

						case 5:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|         Pencarian Data Pemulung Berdasarkan Tingkat        |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;
							Cari_Barang(menu_barang_cari);
							getch();
							goto menu_barang_cari;
							break;

						case 6:
							goto menu_barang;
							break;
							
						default:
							cout << endl;
							cout << "--------------------------------------------" << endl;
							cout << "|          Pilihan Tidak Tersedia          |" << endl;
							cout << "--------------------------------------------" << endl << endl;
							cout << "Tekan Untuk Melanjutkan...";
							getch();
							goto menu_barang_cari;
							break;
					}
					cout << "Tekan Untuk Melanjutkan...";
					getch();
					goto menu_barang;
					break;
					
				case 3:
					menu_barang_urut:
					system("cls");
					cout << "---------------------------------------------" << endl;
					cout << "|           Pengurutan Data Barang          |" << endl;
					cout << "---------------------------------------------" << endl;
					cout << "| 1. Urutkan Kode                           |" << endl;
					cout << "| 2. Urutkan Nama Barang                    |" << endl;
					cout << "| 3. Urutkan Harga                          |" << endl;
					cout << "| 4. Urutkan Poin Barang                    |" << endl;
					cout << "| 5. Urutkan Tingkat                        |" << endl;
					cout << "| 6. Kembali                                |" << endl;
					cout << "---------------------------------------------" << endl << endl;
					
					cout << "Masukkan Pilihan : ";
					cin >> menu_barang_urut;

					switch(menu_barang_urut)
					{
						case 1:
							menu_barang_urut_order_kode:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|          Pengurutan Data Pemulung Berdasarkan Kode         |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;

							cout << "Masukkan Pilihan : ";
							cin >> menu_barang_urut_order;

							switch(menu_barang_urut_order)
							{
									case 1:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                            Pengurutan Data Barang Berdasarkan Kode Ascending                            |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 2:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                            Pengurutan Data Barang Berdasarkan Kode Descending                           |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 3:
										goto menu_barang_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut_order_kode;
										break;
							}
							getch();
							goto menu_barang_urut;
							break;

						case 2:
							menu_barang_urut_order_nama_barang:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|      Pengurutan Data Pemulung Berdasarkan Nama Barang      |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;

							cout << "Masukkan Pilihan : ";
							cin >> menu_barang_urut_order;

							switch(menu_barang_urut_order)
							{
									case 1:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                         Pengurutan Data Barang Berdasarkan Nama Barang Ascending                        |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 2:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                         Pengurutan Data Barang Berdasarkan Nama Barang Descending                       |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 3:
										goto menu_barang_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut_order_nama_barang;
										break;
							}
							getch();
							goto menu_barang_urut;
							break;

						case 3:
							menu_barang_urut_order_harga:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|         Pengurutan Data Pemulung Berdasarkan Harga         |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;

							cout << "Masukkan Pilihan : ";
							cin >> menu_barang_urut_order;

							switch(menu_barang_urut_order)
							{
									case 1:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                            Pengurutan Data Barang Berdasarkan Harga Ascending                           |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 2:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                            Pengurutan Data Barang Berdasarkan Harga Descending                          |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 3:
										goto menu_barang_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut_order_harga;
										break;
							}
							getch();
							goto menu_barang_urut;
							break;

						case 4:
							menu_barang_urut_order_poin_barang:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|      Pengurutan Data Pemulung Berdasarkan Poin Barang      |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;

							cout << "Masukkan Pilihan : ";
							cin >> menu_barang_urut_order;

							switch(menu_barang_urut_order)
							{
									case 1:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                         Pengurutan Data Barang Berdasarkan Poin Barang Ascending                        |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 2:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                         Pengurutan Data Barang Berdasarkan Poin Barang Descending                       |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 3:
										goto menu_barang_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut_order_poin_barang;
										break;
							}
							getch();
							goto menu_barang_urut;
							break;


						case 5:
							menu_barang_urut_order_tingkat:
							system("cls");
							cout << "--------------------------------------------------------------" << endl;
							cout << "|        Pengurutan Data Pemulung Berdasarkan Tingkat        |" << endl;
							cout << "--------------------------------------------------------------" << endl;
							cout << "| 1. Ascending                                               |" << endl;
							cout << "| 2. Descending                                              |" << endl;
							cout << "| 3. Kembali                                                 |" << endl;
							cout << "--------------------------------------------------------------" << endl << endl;

							cout << "Masukkan Pilihan : ";
							cin >> menu_barang_urut_order;

							switch(menu_barang_urut_order)
							{
									case 1:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                           Pengurutan Data Barang Berdasarkan Tingkat Ascending                          |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 2:
										system("cls");
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										cout << "|                           Pengurutan Data Barang Berdasarkan Tingkat Descending                          |" << endl;
										cout << "-----------------------------------------------------------------------------------------------------------" << endl;
										Urut_Barang(menu_barang_urut, menu_barang_urut_order);
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut;
										break;
										
									case 3:
										goto menu_barang_urut;
										break;
										
									default:
										cout << endl;
										cout << "--------------------------------------------" << endl;
										cout << "|          Pilihan Tidak Tersedia          |" << endl;
										cout << "--------------------------------------------" << endl << endl;
										cout << "Tekan Untuk Melanjutkan...";
										getch();
										goto menu_barang_urut_order_tingkat;
										break;
							}
							getch();
							goto menu_barang_urut;
							break;

						case 6:
							goto menu_barang;
							break;
							
						default:
							cout << endl;
							cout << "--------------------------------------------" << endl;
							cout << "|          Pilihan Tidak Tersedia          |" << endl;
							cout << "--------------------------------------------" << endl << endl;
							cout << "Tekan Untuk Melanjutkan...";
							getch();
							goto menu_barang_urut;
							break;
					}
					cout << "Tekan Untuk Melanjutkan...";
					getch();
					goto menu_barang;
					break;
					
				case 4:
					goto menu_utama;
					break;
					
				default:
					cout << endl;
					cout << "--------------------------------------------" << endl;
					cout << "|          Pilihan Tidak Tersedia          |" << endl;
					cout << "--------------------------------------------" << endl << endl;
					cout << "Tekan Untuk Melanjutkan...";
					getch();
					goto menu_barang;
					break;
			}
			goto menu_barang;
			break;
			
		case 3:
			system("cls");
			cout << "---------------------------------------------" << endl;
			cout << "|                  Bantuan                  |" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "| Peringkat 1 : 0    - 99   Poin (x1 Bonus) |" << endl;
			cout << "| Peringkat 2 : 100  - 499  Poin (x2 Bonus) |" << endl;
			cout << "| Peringkat 3 : 500  - 1499 Poin (x3 Bonus) |" << endl;
			cout << "| Peringkat 4 : 1500 - 2999 Poin (x4 Bonus) |" << endl;
			cout << "| Peringkat 5 : 3000 - ...  Poin (x5 Bonus) |" << endl;
			cout << "---------------------------------------------" << endl << endl;
			cout << "Tekan Untuk Melanjutkan...";
			getch();
			goto menu_utama;
			break;

		case 4:
			cout << endl << "---------- Terima Kasih ----------" << endl;
			break;
			
		default:
			cout << endl;
			cout << "--------------------------------------------" << endl;
			cout << "|          Pilihan Tidak Tersedia          |" << endl;
			cout << "--------------------------------------------" << endl << endl;
			cout << "Tekan Untuk Melanjutkan...";
			getch();
			goto menu_utama;
			break;
	}
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Database_Pemulung()
{
	data1_pemulung = new data_pemulung;
	data1_pemulung -> nidp = 1;
	data1_pemulung -> nama = "Muhammad Azhar Rasyad";
	data1_pemulung -> alamat = "JL. Cibinong Pondok Rajeg Jawa Barat";
	data1_pemulung -> poin = 90;
	data1_pemulung -> peringkat = 1;
	data1_pemulung -> next = NULL;
	data1_pemulung -> prev = NULL;

	data2_pemulung = new data_pemulung;
	data2_pemulung -> nidp = 2;
	data2_pemulung -> nama = "Hera Karmila";
	data2_pemulung -> alamat = "JL. Cilebut Cibinong Jawa Barat";
	data2_pemulung -> poin = 550;
	data2_pemulung -> peringkat = 3;
	data2_pemulung -> next = NULL;
	data2_pemulung -> prev = NULL;

	data3_pemulung = new data_pemulung;
	data3_pemulung -> nidp = 3;
	data3_pemulung -> nama = "Rizal Wicaksono";
	data3_pemulung -> alamat = "JL. Sukmajaya Depok Jawa Barat";
	data3_pemulung -> poin = 3100;
	data3_pemulung -> peringkat = 5;
	data3_pemulung -> next = NULL;
	data3_pemulung -> prev = NULL;
	
	data4_pemulung = new data_pemulung;
	data4_pemulung -> nidp = 1;
	data4_pemulung -> nama = "Muhammad Azhar Rasyad";
	data4_pemulung -> alamat = "JL. Cibinong Pondok Rajeg Jawa Barat";
	data4_pemulung -> poin = 90;
	data4_pemulung -> peringkat = 1;
	data4_pemulung -> next = NULL;
	data4_pemulung -> prev = NULL;

	data5_pemulung = new data_pemulung;
	data5_pemulung -> nidp = 2;
	data5_pemulung -> nama = "Hera Karmila";
	data5_pemulung -> alamat = "JL. Cilebut Cibinong Jawa Barat";
	data5_pemulung -> poin = 550;
	data5_pemulung -> peringkat = 3;
	data5_pemulung -> next = NULL;
	data5_pemulung -> prev = NULL;

	data6_pemulung = new data_pemulung;
	data6_pemulung -> nidp = 3;
	data6_pemulung -> nama = "Rizal Wicaksono";
	data6_pemulung -> alamat = "JL. Sukmajaya Depok Jawa Barat";
	data6_pemulung -> poin = 3100;
	data6_pemulung -> peringkat = 5;
	data6_pemulung -> next = NULL;
	data6_pemulung -> prev = NULL;
}

void Relasi_Pemulung()
{
	head_pemulung = data1_pemulung;
	tail_pemulung = data3_pemulung;
	head_pemulung -> next = data2_pemulung;
	data2_pemulung -> next = tail_pemulung;
	data2_pemulung -> prev = head_pemulung;
	tail_pemulung -> prev = data2_pemulung;
	
	simpan_pemulung_temp = data4_pemulung;
	temp_simpan_pemulung = data6_pemulung;
	simpan_pemulung_temp -> next = data5_pemulung;
	data5_pemulung -> next = temp_simpan_pemulung;
	data5_pemulung -> prev = simpan_pemulung_temp;
	temp_simpan_pemulung -> prev = data5_pemulung;
}

void Daftar_Pemulung()
{
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                                   Data Pemulung                                                    |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| NIDP |              Nama              |                         Alamat                        |  Poin  | Peringkat |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cin.get();
	nidp_isi++;
	poin_isi = 0;
	peringkat_isi = 1;
	counter++;

	gotoxy(0,5); cout << "|      |                                |                                                       |        |           |" << endl;
	gotoxy(3,5); cout << nidp_isi;
	gotoxy(9,5); getline(cin, nama_isi);
	gotoxy(42,5); getline(cin, alamat_isi);
	gotoxy(99,5); cout << poin_isi;
	gotoxy(111,5); cout << peringkat_isi;

	baru_pemulung = new data_pemulung;
	baru_pemulung -> nidp = nidp_isi;
	baru_pemulung -> nama = nama_isi;
	baru_pemulung -> alamat = alamat_isi;
	baru_pemulung -> poin = poin_isi;
	baru_pemulung -> peringkat = peringkat_isi;
	baru_pemulung -> next = NULL;
	baru_pemulung -> prev = NULL;
	
	if(head_pemulung == NULL)
	{
		head_pemulung = baru_pemulung;
		tail_pemulung = baru_pemulung;
	}
	else
	{
		bantu_pemulung = tail_pemulung;
		tail_pemulung -> next = baru_pemulung;
		tail_pemulung = baru_pemulung;
		tail_pemulung -> prev = bantu_pemulung;
	}
	
	save_pemulung = new data_pemulung;
	save_pemulung -> nidp = nidp_isi;
	save_pemulung -> nama = nama_isi;
	save_pemulung -> alamat = alamat_isi;
	save_pemulung -> poin = poin_isi;
	save_pemulung -> peringkat = peringkat_isi;
	save_pemulung -> next = NULL;
	save_pemulung -> prev = NULL;

	if(simpan_pemulung_temp == NULL)
	{
		simpan_pemulung_temp = save_pemulung;
		temp_simpan_pemulung = save_pemulung;
	}
	else
	{
		simpan_pemulung = temp_simpan_pemulung;
		temp_simpan_pemulung -> next = save_pemulung;
		temp_simpan_pemulung = save_pemulung;
		temp_simpan_pemulung -> prev = simpan_pemulung;
	}
}

void Tampil_Pemulung()
{
	if(simpan_pemulung_temp == NULL)
	{
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                   Data Pemulung                                                    |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| NIDP |              Nama              |                         Alamat                        |  Poin  | Peringkat |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                    Data Kosong                                                     |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
	else
	{
		int y = 5;
		simpan_pemulung = simpan_pemulung_temp;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                   Data Pemulung                                                    |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| NIDP |              Nama              |                         Alamat                        |  Poin  | Peringkat |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

		while(simpan_pemulung != NULL)
		{
			gotoxy(0,y); cout << "|      |                                |                                                       |        |           |" << endl;
			gotoxy(3,y); cout << simpan_pemulung -> nidp;
			gotoxy(9,y); cout << simpan_pemulung -> nama;
			gotoxy(42,y); cout << simpan_pemulung -> alamat;
			gotoxy(99,y); cout << simpan_pemulung -> poin;
			gotoxy(111,y); cout << simpan_pemulung -> peringkat;
			simpan_pemulung = simpan_pemulung -> next;
			y++;
		}
		cout << "\n----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
}

void Cari_Pemulung(int menu_data_cari)
{
	int temp_nidp[counter];
	string temp_nama[counter];
	string temp_alamat[counter];
	int temp_poin[counter];
	int temp_peringkat[counter];

	int i;
	int temp_data = 0;
	int data_angka;
	string data_huruf;
	bantu_pemulung = head_pemulung;

	if(menu_data_cari == 1)
	{
		cout << "Masukkan NIDP Yang Ingin Dicari = ";
		cin >> data_angka;
		cout << endl;

		for(i = 1; i <= counter; i++)
		{
			if (bantu_pemulung -> nidp == data_angka)
			{
				temp_data++;
				temp_nidp[temp_data] = bantu_pemulung -> nidp;
				temp_nama[temp_data] = bantu_pemulung -> nama;
				temp_alamat[temp_data] = bantu_pemulung -> alamat;
				temp_poin[temp_data] = bantu_pemulung -> poin;
				temp_peringkat[temp_data] = bantu_pemulung -> peringkat;
			}

			bantu_pemulung = bantu_pemulung -> next;
		}
	}
	else if(menu_data_cari == 2)
	{
		cout << "Masukkan Nama Yang Ingin Dicari = ";
		cin.get();
		getline(cin, data_huruf);
		cout << endl;

		for(i = 1; i <= counter; i++)
		{
			if (bantu_pemulung -> nama == data_huruf)
			{
				temp_data++;
				temp_nidp[temp_data] = bantu_pemulung -> nidp;
				temp_nama[temp_data] = bantu_pemulung -> nama;
				temp_alamat[temp_data] = bantu_pemulung -> alamat;
				temp_poin[temp_data] = bantu_pemulung -> poin;
				temp_peringkat[temp_data] = bantu_pemulung -> peringkat;
			}

			bantu_pemulung = bantu_pemulung -> next;
		}
	}
	else if(menu_data_cari == 3)
	{
		cout << "Masukkan Alamat Yang Ingin Dicari = ";
		cin.get();
		getline(cin, data_huruf);
		cout << endl;

		for(i = 1; i <= counter; i++)
		{
			if (bantu_pemulung -> alamat == data_huruf)
			{
				temp_data++;
				temp_nidp[temp_data] = bantu_pemulung -> nidp;
				temp_nama[temp_data] = bantu_pemulung -> nama;
				temp_alamat[temp_data] = bantu_pemulung -> alamat;
				temp_poin[temp_data] = bantu_pemulung -> poin;
				temp_peringkat[temp_data] = bantu_pemulung -> peringkat;
			}

			bantu_pemulung = bantu_pemulung -> next;
		}
	}
	else if(menu_data_cari == 4)
	{
		cout << "Masukkan Poin Yang Ingin Dicari = ";
		cin >> data_angka;
		cout << endl;

		for(i = 1; i <= counter; i++)
		{
			if (bantu_pemulung -> poin == data_angka)
			{
				temp_data++;
				temp_nidp[temp_data] = bantu_pemulung -> nidp;
				temp_nama[temp_data] = bantu_pemulung -> nama;
				temp_alamat[temp_data] = bantu_pemulung -> alamat;
				temp_poin[temp_data] = bantu_pemulung -> poin;
				temp_peringkat[temp_data] = bantu_pemulung -> peringkat;
			}

			bantu_pemulung = bantu_pemulung -> next;
		}
	}
	else if(menu_data_cari == 5)
	{
		cout << "Masukkan Peringkat Yang Ingin Dicari = ";
		cin >> data_angka;
		cout << endl;

		for(i = 1; i <= counter; i++)
		{
			if (bantu_pemulung -> peringkat == data_angka)
			{
				temp_data++;
				temp_nidp[temp_data] = bantu_pemulung -> nidp;
				temp_nama[temp_data] = bantu_pemulung -> nama;
				temp_alamat[temp_data] = bantu_pemulung -> alamat;
				temp_poin[temp_data] = bantu_pemulung -> poin;
				temp_peringkat[temp_data] = bantu_pemulung -> peringkat;
			}

			bantu_pemulung = bantu_pemulung -> next;
		}
	}

	if(temp_data > 0)
	{
		for(i = 1; i <= temp_data; i++)
		{
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "|                                                   Data Ditemukan                                                   |" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " NIDP      : " << temp_nidp[i] << endl;
			cout << " Nama      : " << temp_nama[i] << endl;
			cout << " Alamat    : " << temp_alamat[i] << endl;
			cout << " Poin      : " << temp_poin[i] << endl;
			cout << " Peringkat : " << temp_peringkat[i] << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
		}
		
		cout << "Tekan Untuk Melanjutkan...";
		getch();
	}
	else
	{
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                Data Tidak Ditemukan                                                |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
}

void Sorting_Pemulung()
{
	if(head_pemulung == NULL)
	{
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                   Data Pemulung                                                    |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| NIDP |              Nama              |                         Alamat                        |  Poin  | Peringkat |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                    Data Kosong                                                     |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
	else
	{
		int y = 8;
		bantu_pemulung = head_pemulung;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                   Data Pemulung                                                    |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "| NIDP |              Nama              |                         Alamat                        |  Poin  | Peringkat |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;

		while(bantu_pemulung != NULL)
		{
			gotoxy(0,y); cout << "|      |                                |                                                       |        |           |" << endl;
			gotoxy(3,y); cout << bantu_pemulung -> nidp;
			gotoxy(9,y); cout << bantu_pemulung -> nama;
			gotoxy(42,y); cout << bantu_pemulung -> alamat;
			gotoxy(99,y); cout << bantu_pemulung -> poin;
			gotoxy(111,y); cout << bantu_pemulung -> peringkat;
			bantu_pemulung = bantu_pemulung -> next;
			y++;
		}
		cout << "\n----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
}

void Urut_Pemulung(int menu_data_urut, int menu_data_urut_order)
{
	if(menu_data_urut == 1)
	{
		if(menu_data_urut_order == 1)
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> nidp > temp_head_pemulung -> next -> nidp)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
		else
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> nidp < temp_head_pemulung -> next -> nidp)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
	}
	else if(menu_data_urut == 2)
	{
		if(menu_data_urut_order == 1)
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> nama > temp_head_pemulung -> next -> nama)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
		else
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> nama < temp_head_pemulung -> next -> nama)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
	}
	else if(menu_data_urut == 3)
	{
		if(menu_data_urut_order == 1)
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> alamat > temp_head_pemulung -> next -> alamat)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
		else
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> alamat < temp_head_pemulung -> next -> alamat)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
	}
	else if(menu_data_urut == 4)
	{
		if(menu_data_urut_order == 1)
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> poin > temp_head_pemulung -> next -> poin)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
		else
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> poin < temp_head_pemulung -> next -> poin)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
	}
	else if(menu_data_urut == 5)
	{
		if(menu_data_urut_order == 1)
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> peringkat > temp_head_pemulung -> next -> peringkat)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
		else
		{
			data_pemulung *temp_head_pemulung = head_pemulung;
		
			int temp_nidp;
			string temp_nama;
			string temp_alamat;
			int temp_poin;
			int temp_peringkat;
			int counter = 0;
			
			while (temp_head_pemulung)
			{
				temp_head_pemulung = temp_head_pemulung -> next;
				counter++;
			}
			temp_head_pemulung = head_pemulung;
			
			for (int j = 0; j < counter; j++)
			{
				while (temp_head_pemulung -> next)
				{
					if (temp_head_pemulung -> peringkat < temp_head_pemulung -> next -> peringkat)
					{
						temp_nidp = temp_head_pemulung -> nidp;
						temp_head_pemulung -> nidp = temp_head_pemulung -> next -> nidp;
						temp_head_pemulung -> next -> nidp = temp_nidp;
			
						temp_nama = temp_head_pemulung -> nama;
						temp_head_pemulung -> nama = temp_head_pemulung -> next -> nama;
						temp_head_pemulung -> next -> nama = temp_nama;
						
						temp_alamat = temp_head_pemulung -> alamat;
						temp_head_pemulung -> alamat = temp_head_pemulung -> next -> alamat;
						temp_head_pemulung -> next -> alamat = temp_alamat;
						
						temp_poin = temp_head_pemulung -> poin;
						temp_head_pemulung -> poin = temp_head_pemulung -> next -> poin;
						temp_head_pemulung -> next -> poin = temp_poin;
						
						temp_peringkat = temp_head_pemulung -> peringkat;
						temp_head_pemulung -> peringkat = temp_head_pemulung -> next -> peringkat;
						temp_head_pemulung -> next -> peringkat = temp_peringkat;
					}
					temp_head_pemulung = temp_head_pemulung -> next;
				}	
				temp_head_pemulung = head_pemulung;
			}
			Sorting_Pemulung();
		}
	}
}

void Database_Barang()
{
	data1_barang = new data_barang;
	data1_barang -> kode = "P1";
	data1_barang -> nama_barang = "Botol Plastik";
	data1_barang -> harga = 1000;
	data1_barang -> poin_barang = 1;
	data1_barang -> tingkat = "Rendah";
	data1_barang -> next = NULL;
	data1_barang -> prev = NULL;

	data2_barang = new data_barang;
	data2_barang -> kode = "P2";
	data2_barang -> nama_barang = "Gelas Plastik";
	data2_barang -> harga = 1000;
	data2_barang -> poin_barang = 3;
	data2_barang -> tingkat = "Menengah";
	data2_barang -> next = NULL;
	data2_barang -> prev = NULL;

	data3_barang = new data_barang;
	data3_barang -> kode = "L1";
	data3_barang -> nama_barang = "Besi";
	data3_barang -> harga = 1500;
	data3_barang -> poin_barang = 5;
	data3_barang -> tingkat = "Tinggi";
	data3_barang -> next = NULL;
	data3_barang -> prev = NULL;
	
	data4_barang = new data_barang;
	data4_barang -> kode = "P1";
	data4_barang -> nama_barang = "Botol Plastik";
	data4_barang -> harga = 1000;
	data4_barang -> poin_barang = 1;
	data4_barang -> tingkat = "Rendah";
	data4_barang -> next = NULL;
	data4_barang -> prev = NULL;

	data5_barang = new data_barang;
	data5_barang -> kode = "P2";
	data5_barang -> nama_barang = "Gelas Plastik";
	data5_barang -> harga = 1000;
	data5_barang -> poin_barang = 3;
	data5_barang -> tingkat = "Menengah";
	data5_barang -> next = NULL;
	data5_barang -> prev = NULL;

	data6_barang = new data_barang;
	data6_barang -> kode = "L1";
	data6_barang -> nama_barang = "Besi";
	data6_barang -> harga = 1500;
	data6_barang -> poin_barang = 5;
	data6_barang -> tingkat = "Tinggi";
	data6_barang -> next = NULL;
	data6_barang -> prev = NULL;
}

void Relasi_Barang()
{
	head_barang = data1_barang;
	tail_barang = data3_barang;
	head_barang -> next = data2_barang;
	data2_barang -> next = tail_barang;
	data2_barang -> prev = head_barang;
	tail_barang -> prev = data2_barang;
	
	simpan_barang_temp = data4_barang;
	temp_simpan_barang = data6_barang;
	simpan_barang_temp -> next = data5_barang;
	data5_barang -> next = temp_simpan_barang;
	data5_barang -> prev = simpan_barang_temp;
	temp_simpan_barang -> prev = data5_barang;
}

void Tampil_Barang()
{
	if(simpan_barang_temp == NULL)
	{
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                               Data Barang                                               |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  Kode  |         Nama Barang         |  Harga / KG  |   Poin Barang / KG   |     Tingkat Pencemaran     |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                               Data Kosong                                               |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl << endl;
		
	}
	else
	{
		int y = 5;
		simpan_barang = simpan_barang_temp;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                               Data Barang                                               |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  Kode  |         Nama Barang         |  Harga / KG  |   Poin Barang / KG   |     Tingkat Pencemaran     |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		while(simpan_barang != NULL)
		{
			gotoxy(0,y); cout << "|        |                             |              |                      |                            |" << endl;
			gotoxy(3,y); cout << simpan_barang -> kode;
			gotoxy(11,y); cout << simpan_barang -> nama_barang;
			gotoxy(45,y); cout << simpan_barang -> harga;
			gotoxy(65,y); cout << simpan_barang -> poin_barang;
			gotoxy(88,y); cout << simpan_barang -> tingkat;
			simpan_barang = simpan_barang -> next;
			y++;
		}
		cout << "\n-----------------------------------------------------------------------------------------------------------" << endl << endl;
	}
}

void Cari_Barang(int menu_barang_cari)
{
	string temp_kode[counter_barang];
	string temp_nama_barang[counter_barang];
	int temp_harga[counter_barang];
	int temp_poin_barang[counter_barang];
	string temp_tingkat[counter_barang];

	int i;
	int temp_data = 0;
	int data_angka;
	string data_huruf;
	bantu_barang = head_barang;

	if(menu_barang_cari == 1)
	{
		cout << "Masukkan Kode Yang Ingin Dicari = ";
		cin.get();
		getline(cin, data_huruf);
		cout << endl;

		for(i = 1; i <= counter_barang; i++)
		{
			if (bantu_barang -> kode == data_huruf)
			{
				temp_data++;
				temp_kode[temp_data] = bantu_barang -> kode;
				temp_nama_barang[temp_data] = bantu_barang -> nama_barang;
				temp_harga[temp_data] = bantu_barang -> harga;
				temp_poin_barang[temp_data] = bantu_barang -> poin_barang;
				temp_tingkat[temp_data] = bantu_barang -> tingkat;
			}

			bantu_barang = bantu_barang -> next;
		}
	}
	else if(menu_barang_cari == 2)
	{
		cout << "Masukkan Nama Barang Yang Ingin Dicari = ";
		cin.get();
		getline(cin, data_huruf);
		cout << endl;

		for(i = 1; i <= counter_barang; i++)
		{
			if (bantu_barang -> nama_barang == data_huruf)
			{
				temp_data++;
				temp_kode[temp_data] = bantu_barang -> kode;
				temp_nama_barang[temp_data] = bantu_barang -> nama_barang;
				temp_harga[temp_data] = bantu_barang -> harga;
				temp_poin_barang[temp_data] = bantu_barang -> poin_barang;
				temp_tingkat[temp_data] = bantu_barang -> tingkat;
			}

			bantu_barang = bantu_barang -> next;
		}
	}
	else if(menu_barang_cari == 3)
	{
		cout << "Masukkan Harga Yang Ingin Dicari = ";
		cin >> data_angka;
		cout << endl;

		for(i = 1; i <= counter_barang; i++)
		{
			if (bantu_barang -> harga == data_angka)
			{
				temp_data++;
				temp_kode[temp_data] = bantu_barang -> kode;
				temp_nama_barang[temp_data] = bantu_barang -> nama_barang;
				temp_harga[temp_data] = bantu_barang -> harga;
				temp_poin_barang[temp_data] = bantu_barang -> poin_barang;
				temp_tingkat[temp_data] = bantu_barang -> tingkat;
			}

			bantu_barang = bantu_barang -> next;
		}
	}
	else if(menu_barang_cari == 4)
	{
		cout << "Masukkan Poin Barang Yang Ingin Dicari = ";
		cin >> data_angka;
		cout << endl;

		for(i = 1; i <= counter_barang; i++)
		{
			if (bantu_barang -> poin_barang == data_angka)
			{
				temp_data++;
				temp_kode[temp_data] = bantu_barang -> kode;
				temp_nama_barang[temp_data] = bantu_barang -> nama_barang;
				temp_harga[temp_data] = bantu_barang -> harga;
				temp_poin_barang[temp_data] = bantu_barang -> poin_barang;
				temp_tingkat[temp_data] = bantu_barang -> tingkat;
			}

			bantu_barang = bantu_barang -> next;
		}
	}
	else if(menu_barang_cari == 5)
	{
		cout << "Masukkan Tingkat Pencemaran Yang Ingin Dicari = ";
		cin.get();
		getline(cin,data_huruf);
		cout << endl;

		for(i = 1; i <= counter_barang; i++)
		{
			if (bantu_barang -> tingkat == data_huruf)
			{
				temp_data++;
				temp_kode[temp_data] = bantu_barang -> kode;
				temp_nama_barang[temp_data] = bantu_barang -> nama_barang;
				temp_harga[temp_data] = bantu_barang -> harga;
				temp_poin_barang[temp_data] = bantu_barang -> poin_barang;
				temp_tingkat[temp_data] = bantu_barang -> tingkat;
			}
			
			bantu_barang = bantu_barang -> next;
		}
	}

	if(temp_data > 0)
	{
		for(i = 1; i <= temp_data; i++)
		{
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "|                                                   Data Ditemukan                                                   |" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " Kode               : " << temp_kode[i] << endl;
			cout << " Nama Barang        : " << temp_nama_barang[i] << endl;
			cout << " Harga / KG         : " << temp_harga[i] << endl;
			cout << " Poin Barang / KG   : " << temp_poin_barang[i] << endl;
			cout << " Tingkat Pencemaran : " << temp_tingkat[i] << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
		}
		
		cout << "Tekan Untuk Melanjutkan...";
		getch();
	}
	else
	{
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                Data Tidak Ditemukan                                                |" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	}
}

void Sorting_Barang()
{
	if(head_barang == NULL)
	{
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                               Data Barang                                               |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  Kode  |         Nama Barang         |  Harga / KG  |   Poin Barang / KG   |     Tingkat Pencemaran     |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                               Data Kosong                                               |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl << endl;
	}
	else
	{
		int y = 7;
		bantu_barang = head_barang;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                               Data Barang                                               |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "|  Kode  |         Nama Barang         |  Harga / KG  |   Poin Barang / KG   |     Tingkat Pencemaran     |" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;

		while(bantu_barang != NULL)
		{
			gotoxy(0,y); cout << "|        |                             |              |                      |                            |" << endl;
			gotoxy(3,y); cout << bantu_barang -> kode;
			gotoxy(11,y); cout << bantu_barang -> nama_barang;
			gotoxy(45,y); cout << bantu_barang -> harga;
			gotoxy(65,y); cout << bantu_barang -> poin_barang;
			gotoxy(88,y); cout << bantu_barang -> tingkat;
			bantu_barang = bantu_barang -> next;
			y++;
		}
		cout << "\n-----------------------------------------------------------------------------------------------------------" << endl << endl;
	}
}

void Urut_Barang(int menu_barang_urut, int menu_barang_urut_order)
{
	if(menu_barang_urut == 1)
	{
		if(menu_barang_urut_order == 1)
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> kode > temp_head_barang -> next -> kode)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
		else
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> kode < temp_head_barang -> next -> kode)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
	}
	else if(menu_barang_urut == 2)
	{
		if(menu_barang_urut_order == 1)
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> nama_barang > temp_head_barang -> next -> nama_barang)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
		else
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> nama_barang < temp_head_barang -> next -> nama_barang)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
	}
	else if(menu_barang_urut == 3)
	{
		if(menu_barang_urut_order == 1)
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> harga > temp_head_barang -> next -> harga)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
		else
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> harga < temp_head_barang -> next -> harga)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
	}
	else if(menu_barang_urut == 4)
	{
		if(menu_barang_urut_order == 1)
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> poin_barang > temp_head_barang -> next -> poin_barang)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
		else
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> poin_barang < temp_head_barang -> next -> poin_barang)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
	}
	else if(menu_barang_urut == 5)
	{
		if(menu_barang_urut_order == 1)
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> tingkat > temp_head_barang -> next -> tingkat)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
		else
		{
			data_barang *temp_head_barang = head_barang;
		
			string temp_kode;
			string temp_nama_barang;
			int temp_harga;
			int temp_poin_barang;
			string temp_tingkat;
			int counter_barang = 0;
			
			while (temp_head_barang)
			{
				temp_head_barang = temp_head_barang -> next;
				counter_barang++;
			}
			temp_head_barang = head_barang;
			
			for (int j = 0; j < counter_barang; j++)
			{
				while (temp_head_barang -> next)
				{
					if (temp_head_barang -> tingkat < temp_head_barang -> next -> tingkat)
					{
						temp_kode = temp_head_barang -> kode;
						temp_head_barang -> kode = temp_head_barang -> next -> kode;
						temp_head_barang -> next -> kode = temp_kode;
			
						temp_nama_barang = temp_head_barang -> nama_barang;
						temp_head_barang -> nama_barang = temp_head_barang -> next -> nama_barang;
						temp_head_barang -> next -> nama_barang = temp_nama_barang;
						
						temp_harga = temp_head_barang -> harga;
						temp_head_barang -> harga = temp_head_barang -> next -> harga;
						temp_head_barang -> next -> harga = temp_harga;
						
						temp_poin_barang = temp_head_barang -> poin_barang;
						temp_head_barang -> poin_barang = temp_head_barang -> next -> poin_barang;
						temp_head_barang -> next -> poin_barang = temp_poin_barang;
						
						temp_tingkat = temp_head_barang -> tingkat;
						temp_head_barang -> tingkat = temp_head_barang -> next -> tingkat;
						temp_head_barang -> next -> tingkat = temp_tingkat;
					}
					temp_head_barang = temp_head_barang -> next;
				}	
				temp_head_barang = head_barang;
			}
			Sorting_Barang();
		}
	}
}

void Transaksi()
{
	int temp_nidp[counter];
	string temp_nama[counter];
	string temp_alamat[counter];
	int temp_poin[counter];
	int temp_peringkat[counter];

	int i;
	int temp_data_pemulung = 0;
	int data_nidp;
	
	int nidp;
	string nama;
	string alamat;
	int poin;
	int peringkat;
	
	string kode;
	string nama_barang;
	int harga;
	int poin_barang;
	string tingkat;
	
	float total_harga;
	int total_poin_barang;
	time_t now = time(0);
	char* tanggal = ctime(&now);
	
	bantu_pemulung = head_pemulung;

	Tampil_Pemulung();

	cout << "Masukkan NIDP = ";
	cin >> data_nidp;
	cout << endl;

	for(i = 1; i <= counter; i++)
	{
		if (bantu_pemulung -> nidp == data_nidp)
		{
			temp_data_pemulung++;
			temp_nidp[temp_data_pemulung] = bantu_pemulung -> nidp;
			temp_nama[temp_data_pemulung] = bantu_pemulung -> nama;
			temp_alamat[temp_data_pemulung] = bantu_pemulung -> alamat;
			temp_poin[temp_data_pemulung] = bantu_pemulung -> poin;
			temp_peringkat[temp_data_pemulung] = bantu_pemulung -> peringkat;
			
			nidp = bantu_pemulung -> nidp;
			nama = bantu_pemulung -> nama;
			alamat = bantu_pemulung -> alamat;
			poin = bantu_pemulung -> poin;
			peringkat = bantu_pemulung -> peringkat;
		}

		bantu_pemulung = bantu_pemulung -> next;
	}

	if(temp_data_pemulung > 0)
	{
		for(i = 1; i <= temp_data_pemulung; i++)
		{
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "|                                                        Data                                                        |" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " NIDP      : " << temp_nidp[i] << endl;
			cout << " Nama      : " << temp_nama[i] << endl;
			cout << " Alamat    : " << temp_alamat[i] << endl;
			cout << " Poin      : " << temp_poin[i] << endl;
			cout << " Peringkat : " << temp_peringkat[i] << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
		}
		
		cout << "Tekan Untuk Melanjutkan...";
		getch();
		
		string temp_kode[counter_barang];
		string temp_nama_barang[counter_barang];
		int temp_harga[counter_barang];
		int temp_poin_barang[counter_barang];
		string temp_tingkat[counter_barang];
	
		int temp_data_barang = 0;
		float data_harga;
		string data_kode;
		
		bantu_barang = head_barang;	
	
		system("cls");
	
		Tampil_Barang();
		
		cout << "Masukkan Kode Barang = ";
		cin.get();
		getline(cin, data_kode);
		cout << endl;
	
		for(i = 1; i <= counter_barang; i++)
		{
			if (bantu_barang -> kode == data_kode)
			{
				temp_data_barang++;
				temp_kode[temp_data_barang] = bantu_barang -> kode;
				temp_nama_barang[temp_data_barang] = bantu_barang -> nama_barang;
				temp_harga[temp_data_barang] = bantu_barang -> harga;
				temp_poin_barang[temp_data_barang] = bantu_barang -> poin_barang;
				temp_tingkat[temp_data_barang] = bantu_barang -> tingkat;
				
				kode = bantu_barang -> kode;
				nama_barang = bantu_barang -> nama_barang;
				harga = bantu_barang -> harga;
				poin_barang = bantu_barang -> poin_barang;
				tingkat = bantu_barang -> tingkat;
				
				total_harga = bantu_barang -> harga;
				total_poin_barang = bantu_barang -> poin_barang;
				
			}
	
			bantu_barang = bantu_barang -> next;
		}
	
		if(temp_data_barang > 0)
		{
			for(i = 1; i <= temp_data_barang; i++)
			{
				cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "|                                                        Data                                                        |" << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << " Kode               : " << temp_kode[i] << endl;
				cout << " Nama Barang        : " << temp_nama_barang[i] << endl;
				cout << " Harga / KG         : " << temp_harga[i] << endl;
				cout << " Poin Barang / KG   : " << temp_poin_barang[i] << endl;
				cout << " Tingkat Pencemaran : " << temp_tingkat[i] << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
			}
			
			cout << "Tekan Untuk Melanjutkan...";
			getch();
			
			system("cls");
			cout << "-------------------------------------------" << endl;
			cout << "|          Perhitungan Transaksi          |" << endl;
			cout << "-------------------------------------------" << endl << endl;
			
			cout << "Masukkan Berat Barang Dalam KG = ";
			cin >> data_harga;
			
			total_harga = total_harga * data_harga * peringkat;
			total_poin_barang = total_poin_barang * data_harga;
			
			cout << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "|                                                 Perhitungan Harga                                                  |" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " NIDP                     : " << nidp << endl;
			cout << " Peringkat                : " << peringkat << endl;
			cout << " Harga / KG               : " << harga << " / KG " << endl;
			cout << " Poin Barang / KG         : " << poin_barang << " / KG " << endl;
			cout << " Perhitungan Harga        : " << data_harga << " KG x " << harga << " (x" << peringkat << " Bonus)" << endl;
			cout << " Perhitungan Poin         : " << data_harga << " KG x " << poin_barang << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
			
			cout << "Tekan Untuk Melanjutkan...";
			getch();
			
			system("cls");
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "|                                                 Transaksi Berhasil                                                 |" << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "| NIDP                     : " << nidp << endl;
			cout << "| Nama                     : " << nama << endl;
			cout << "| Alamat                   : " << alamat << endl;
			cout << "| Poin                     : " << poin << endl;
			cout << "| Peringkat                : " << peringkat << endl;
			cout << "| Kode                     : " << kode << endl;
			cout << "| Nama Barang              : " << nama_barang << endl;
			cout << "| Harga / KG               : " << harga << " / KG " << endl;
			cout << "| Poin Barang / KG         : " << poin_barang << " / KG " << endl;
			cout << "| Tingkat Pencemaran       : " << tingkat << endl;
			cout << "| Total Harga Yang Dibayar : Rp" << total_harga << endl;
			cout << "| Total Penambahan Poin    : +" << total_poin_barang << endl;
		    cout << "| Waktu dan Tanggal        : " << tanggal;
			cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
						
			bantu_pemulung = head_pemulung;
			simpan_pemulung = simpan_pemulung_temp;
			
			for(i = 1; i <= counter; i++)
			{
				if (bantu_pemulung -> nidp == data_nidp)
				{
					bantu_pemulung -> poin = bantu_pemulung -> poin + total_poin_barang;
					simpan_pemulung -> poin = simpan_pemulung -> poin + total_poin_barang;
					
					if(bantu_pemulung -> poin < 100)
					{
						bantu_pemulung -> peringkat = 1;
						simpan_pemulung -> peringkat = 1;
					}
					else if(bantu_pemulung -> poin >= 100 && bantu_pemulung -> poin < 500)
					{
						bantu_pemulung -> peringkat = 2;
						simpan_pemulung -> peringkat = 2;
					}
					else if(bantu_pemulung -> poin >= 500 && bantu_pemulung -> poin < 1500)
					{
						bantu_pemulung -> peringkat = 3;
						simpan_pemulung -> peringkat = 3;
					}
					else if(bantu_pemulung -> poin >= 1500 && bantu_pemulung -> poin < 3000)
					{
						bantu_pemulung -> peringkat = 4;
						simpan_pemulung -> peringkat = 4;
					}
					else if(bantu_pemulung -> poin > 3000)
					{
						bantu_pemulung -> peringkat = 5;
						simpan_pemulung -> peringkat = 5;
					}
				}
				
				bantu_pemulung = bantu_pemulung -> next;
				simpan_pemulung = simpan_pemulung -> next;
			}
		}
		else
		{
			cout << "------------------------------------" << endl;
			cout << "|          Data Tidak Ada          |" << endl;
			cout << "------------------------------------" << endl << endl;
		}
				
		cout << "Tekan Untuk Melanjutkan...";
		getch();
	}
	else
	{
		cout << "------------------------------------" << endl;
		cout << "|          Data Tidak Ada          |" << endl;
		cout << "------------------------------------" << endl << endl;
		
		cout << "Tekan Untuk Melanjutkan...";
		getch();
	}
}
