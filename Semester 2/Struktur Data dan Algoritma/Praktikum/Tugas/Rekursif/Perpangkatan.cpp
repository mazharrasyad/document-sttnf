// Algoritma Perpangkatan
#include <iostream>

using namespace std;

// Fungsi Perpangkatan
int Perpangkatan (int x, int n)
{
	// Proses
	if (n == 0) // Proses Rumus Perpangkatan
		return 1; 
	else if (n > 1) // Proses Perpangkatan
		return x * Perpangkatan(x,n-1);
}

	/* 
 	Contoh Penjelasan Algoritma :

	Dengan Ketentuan | x >= 0 | n >= 0 |
	Jika Nilai x = 3 dan Nilai n = 2

	Maka Nilai n Dimasukkan Kedalam Fungsi Perpangkatan(x,n)

	Perpangkatan(x,n) = x * Perpangkatan(x,n-1)

	Berikut Penjelasannya:
	Perpangkatan(3,2) = 3 * Perpangkatan(3,2-1)
	Perpangkatan(3,2) = 3 * Perpangkatan(3,1)
	
	Jika Hasilnya Belum Diketahui Maka Memanggil Fungsi Yang Sama Secara Berulang 

	Perpangkatan(3,1) = 3 * Perpangkatan(3,1-1)
	Perpangkatan(3,1) = 3 * Perpangkatan(3,0)

	Karena n = 0 Maka Hasilnya Adalah 1 Sesuai Ketentuan Yang Berlaku
		
	Perpangkatan(3,0) = 1

	Jika Sudah Didapatkan Salah Satu Hasilnya Maka Hasil Yang Lain Akan Didapatkan

	Perpangkatan(3,0) = 1
	Perpangkatan(3,1) = 3 * Perpangkatan(3,0)
	Perpangkatan(3,1) = 3 * 1
	Perpangkatan(3,1) = 3
	Perpangkatan(3,2) = 3 * Perpangkatan(3,1)
	Perpangkatan(3,2) = 3 * 3
	Perpangkatan(3,2) = 9

	Maka Hasil Perpangkatan Bilangan 3 Dengan Pangkat 2 Adalah 27
	*/

// Program Utama
int main()
{	
	// Deklarasi
	int n,x,i;

	cout << "---------- Algoritma Perpangkatan ----------" << endl << endl;
	
	// Input
	cout << "Dengan Ketentuan | x >= 0 | n >= 0 |" << endl; // Ketentuan Bilangan Perpangkatan
	cout << "Masukkan Nilai x = ";
	cin >> x;
	cout << "Masukkan Nilai n = ";
	cin >> n;

	// Verifikasi
	if (x < 0 || n < 0)
		cout << "\nError Masukkan Nilai x >= 0 atau n >= 0" << endl;
	else
	{
		// Output
		cout << "\nBerikut Perpangkatan(x,n) : " << endl;
		if (n == 0)
		{
			cout << "Perpangkatan " << x << " Pangkat " << n << " = " << Perpangkatan(x,n) << " Dari Rumus" << endl;
		}
		else
		{
			cout << "Proses Perpangkatan " << x << " Pangkat " << n << " = ";
		
			for (i = 0; i < n; i++) // Output Perulangan Proses Perpangkatan
			{
				cout << x << "(" << i + 1 << ")";
			
				if ((i + 1) == n)
				{
					cout << "";

					if (n == 1)
						cout << " Dari Bilangan Itu Sendiri";
				}
				else
					cout << " * ";
			}
			cout << endl << endl;

			for (i = 0; i < n; i++)
			{
				cout << "Nilai x = " << x << " Pangkat " << i + 1 << " = " << Perpangkatan(x,n-(n-(i+1))) << endl;
			}			
				
			cout << "\nPerpangkatan " << x << " Pangkat " << n << " = " << Perpangkatan(x,n) << endl;
		}
		cout << "\nPerpangkatan(" << x << "," << n << ") = " << Perpangkatan(x,n) << endl; // Output Hasil Perpangkatan Dari Nilai x dan Nilai n
	}
}
