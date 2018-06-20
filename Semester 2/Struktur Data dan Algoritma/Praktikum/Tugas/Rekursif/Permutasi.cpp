// Algoritma Permutasi
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

// Fungsi Permutasi
int Permutasi (int n, int r)
{
	// Proses
	if (n < r) // Proses Rumus Permutasi
		return 0;
	else if (n >= r) // Proses Permutasi
		return Faktorial(n) / Faktorial(n-r);
}

	/* 
 	Contoh Penjelasan Algoritma :

	Dengan Ketentuan | n > r | n >= 1 | r >= 1 |
	Jika Nilai n = 3 dan Nilai r = 1

	Maka Nilai n Dimasukkan Kedalam Fungsi Permutasi(n,r)

	Permutasi(n,r) = Faktorial(n) / Faktorial(n-r)

	Karena Fungsi Permutasi Memanggil Fungsi Faktorial Maka Proses Berlanjut Ke Fungsi Faktorial(n)

	Faktorial(n) = n * Faktorial(n-1)

	Berikut Penjelasannya :
	Permutasi(3,1) = Faktorial(3) / Faktorial(3-1)
	Permutasi(3,1) = Faktorial(3) / Faktorial(2)

	Maka Fungsi Faktorial(n) Dijalankan Karena Bagian Dari Fungsi Permutasi
	Faktorial(3) = 3 * Faktorial(3-1)
	Faktorial(3) = 3 * Faktorial(2)
	Faktorial(2) = 2 * Faktorial(2-1)
	Faktorial(2) = 2 * Faktorial(1)
	Faktorial(1) = 1 * Faktorial(1-1)
	Faktorial(1) = 1 * Faktorial(0)
	
	Hasil Dari Faktorial(n)
	Faktorial(1) = 1
	Faktorial(2) = 2 * Faktorial(1)
	Faktorial(2) = 2 * 1
	Faktorial(2) = 2
	Faktorial(3) = 3 * Faktorial(2)
	Faktorial(3) = 3 * 2
	Faktorial(3) = 6

	Maka Dari Hasil Faktorial Tersebut Dapat Diberikan Nilai Kepada Fungsi Permutasi
	Permutasi(3,1) = Faktorial(3) / Faktorial(2)
	Permutasi(3,1) = 6 / 2
	Permutasi(3,1) = 3

	Maka Hasil Permutasi Dari Nilai n = 3 Dan r = 1 Adalah 3
	*/

// Program Utama
int main()
{	
	// Deklarasi
	int n,r,i,j,k;

	cout << "---------- Algoritma Permutasi ----------" << endl << endl;

	// Input
	cout << "Dengan Ketentuan | n >= r | n >= 1 | r >= 1 |" << endl; // Ketentuan Bilangan Permutasi
	cout << "Masukkan Nilai n = ";
	cin >> n; // Input Nilai n Dari Keyboard
	cout << "Masukkan Nilai r = ";
	cin >> r; // Input Nilai r Dari Keyboard

	// Verifikasi
	if (n < r || n <= 0 || r <= 0)
		cout << "\nError Masukkan Nilai n >= r atau n >= 1 atau r >= 1" << endl;
	else
	{
		// Output
		cout << "\nBerikut Permutasi P(n,r) : " << endl;
		cout << "P(" << n << "," << r << ") = " << n << "! / (" << n << " - " << r << ")!" << endl;
		cout << "P(" << n << "," << r << ") = " << n << "! / " << n - r << "!" << endl;
		cout << "P(" << n << "," << r << ") = (";
		for (i = 0; i < n; i++) // Output Perulangan Proses Permutasi
		{
			cout << n-i;
			
			if (n-i == 1 || n-i == 0)
			{
				cout << ") / (";
				if (n-r == 0)
					cout << "1)";
				else
				{
					for (j = 0; j < (n-r); j++)
					{
						cout << (n-r)-j;
						if ((n-r)-j == 1 || (n-r)-j == 0)		
							cout << ")";
						else
							cout << " * ";
					}
				}
			}
			else
				cout << " * ";
		}
		cout << endl;
		cout << "P(" << n << "," << r << ") = " << Faktorial(n) << " / " << Faktorial(n-r) << endl;
		cout << "P(" << n << "," << r << ") = " << Permutasi(n,r);
		cout << endl;

		cout << "\nPermutasi P(" << n << "," << r << ") = " << Permutasi(n,r) << endl; // Output Hasil Permutasi Dari Nilai n dan Nilai r
	}
}
