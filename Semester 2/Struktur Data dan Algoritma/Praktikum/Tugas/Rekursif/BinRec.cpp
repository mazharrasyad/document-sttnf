// Algoritma BinRec
#include <iostream>

using namespace std;

// Fungsi BinRec
int BinRec (int n)
{	
	// Proses
	if (n == 1) // Proses Rumus BinRec
		return 1;
	else if (n > 0) // Proses BinRec
		return BinRec(n/2) + 1;
	else
		return 0;
}

	/* 
 	Contoh Penjelasan Algoritma :

	Dengan Ketentuan | n > 0 |
	Jika Nilai n = 3

	Maka nilai n dimasukkan kedalam fungsi BinRec(n)

	BinRec(n) = BinRec(n/2) + 1

	Berikut Penjelasannya :
	BinRec(3) = BinRec(3/2) + 1
	BinRec(3) = BinRec(1) + 1
	
	Karena Variabel yang digunakan adalah integer maka hasil bagi akan berupa bilangan bulat
	Seperti 3/2 = 1 dan bukannya 1,5

	Karena BinRec(1) belum diketahui maka akan diproses ke fungsi BinRec(n) untuk mengetahuinya

	BinRec(1) = 1

	Dari ketentuan BinRec jika n = 1 maka hasilnya adalah 1

	BinRec(1) = 1
	BinRec(3) = BinRec(1) + 1
	BinRec(3) = 1 + 1
	BinRec(3) = 2

	Maka Hasil BinRec Nilai n = 3 Adalah 2
	*/

// Program Utama
int main()
{	
	// Deklarasi
	int n,i;

	cout << "---------- Algoritma BinRec ----------" << endl << endl;

	// Input
	cout << "Dengan Ketentuan | n > 0 |" << endl; // Ketentuan Bilangan Deret
	cout << "Masukkan Nilai Desimal = ";
	cin >> n;

	// Verifikasi
	if (n <= 0)
		cout << "\nError Masukkan Nilai n > 0" << endl;
	else
	{	
		// Output
		cout << "\nBinRec Nilai Desimal = " << n << " Adalah Berjumlah " << BinRec(n) << " Digit Biner" << endl; // Output Hasil BinRec Dari Nilai n
	}
}	
