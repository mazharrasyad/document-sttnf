// Algoritma Faktorial
#include <iostream>

using namespace std;

// Fungsi Faktorial
int Faktorial (int n)
{
	// Proses
	if (n <= 1) // Proses Rumus Faktorial
		return 1;
	else if (n > 1) // Proses Faktorial
		return n * Faktorial(n-1);
}

	/* 
 	Contoh Penjelasan Algoritma :

	Dengan Ketentuan n > 1
	Jika Nilai n = 3

	Maka Nilai n Dimasukkan Kedalam Fungsi Faktorial(n)

	Faktorial(n) = n * Faktorial(n-1)

	Berikut Penjelasannya :
	Faktorial(3) = 3 * Faktorial(3-1)
	Faktorial(3) = 3 * Faktorial(2)

	Kemudian Dari Fungsi Faktorial(3) Akan Memanggil Fungsi Faktorial(2) Didalam Fungsi Tersebut

	Faktorial(2) = 2 * Faktorial(2-1)
	Faktorial(2) = 2 * Faktorial(1)

	Proses Yang Sama Diulang Sampai Menemukan Sebuah Nilai

	Faktorial(1) = 1 * Faktorial(1-1)
	Faktorial(1) = 1 * Faktorial(0)

	Faktorial(0) Tidak Akan Diproses Karena Tidak Memenuhi Syarat Dari Faktorial
	Maka Proses Dimulai Dari Faktorial(1) Dengan Nilainya Adalah 1 Karena Sudah Ketentuannya

	Faktorial(1) = 1

	Jika Sudah Didapatkan Maka Faktorial(2) Dan Faktorial Selanjutnya Akan Bisa Didapatkan Hasilnya
	Cara Ini Hampir Sama Dengan Cara Subtitusi Bilangan

	Faktorial(2) = 2 * Faktorial(1)
	Faktorial(2) = 2 * 1
	Faktorial(2) = 2

	Faktorial(3) = 3 * Faktorial(2)
	Faktorial(3) = 3 * 2
	Faktorial(3) = 6

	Maka Hasil Faktorial Dari Nilai n = 3 Adalah 6
	*/

// Program Utama
int main()
{	
	// Deklarasi
	int n,i;

	cout << "---------- Algoritma Faktorial ----------" << endl << endl;

	// Input
	cout << "Dengan Ketentuan | n > 1 |" << endl; // Ketentuan Bilangan Faktorial
	cout << "Masukkan Nilai n = ";
	cin >> n; // Input Nilai n Dari Keyboard

	// Verifikasi
	if (n < 1)
		cout << "\nError Masukkan Nilai n > 1" << endl;
	else
	{
		// Output
		 
		cout << "\nFaktorial n(" << n << ") = ";
		for (i = 0; i < n; i++) // Output Perulangan Faktorial
		{
			cout << i + 1;
			if (i + 1 == n)
				cout << "";
			else
				cout << " * ";
		}
		cout << "\nFaktorial n(" << n << ") = " << Faktorial(n) << endl; // Output Hasil Faktorial Dari Nilai n
	}
}
