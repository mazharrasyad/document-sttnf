// Algoritma Kombinasi
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

// Fungsi Kombinasi
int Kombinasi (int n, int r)
{
	// Proses
	if (n < r) // Proses Rumus Kombinasi
		return 0;
	else if (n >= r) // Proses Kombinasi
		return Faktorial(n) / (Faktorial(n-r) * Faktorial(r));
}

	/* 
 	Contoh Penjelasan Algoritma :

	Dengan Ketentuan | n > r | n >= 1 | r >= 1 |
	Jika Nilai n = 3 dan Nilai r = 2

	Maka Nilai n Dimasukkan Kedalam Fungsi Kombinasi(n,r)

	Kombinasi(n,r) = Faktorial(n) / (Faktorial(n-r) * Faktorial(r))

	Karena Fungsi Kombinasi Memanggil Fungsi Faktorial Maka Proses Berlanjut Ke Fungsi Faktorial(n)

	Faktorial(n) = n * Faktorial(n-1)

	Berikut Penjelasannya :
	Kombinasi(3,2) = Faktorial(3) / (Faktorial(3-2) * Faktorial(2))
	Kombinasi(3,2) = Faktorial(3) / (Faktorial(1) * Faktorial(2))

	Maka Fungsi Faktorial(n) Dijalankan Karena Bagian Dari Fungsi Kombinasi
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

	Maka Dari Hasil Faktorial Tersebut Dapat Diberikan Nilai Kepada Fungsi Kombinasi
	Kombinasi(3,2) = Faktorial(3) / (Faktorial(1) * Faktorial(2))
	Kombinasi(3,2) = 6 / (1 * 2)
	Kombinasi(3,2) = 6 / 2
	Kombinasi(3,2) = 3

	Maka Hasil Kombinasi Dari Nilai n = 3 Dan r = 2 Adalah 3
	*/

// Program Utama
int main()
{	
	// Deklarasi
	int n,r,i,j,k;

	cout << "---------- Algoritma Kombinasi ----------" << endl << endl;

	// Input
	cout << "Dengan Ketentuan | n >= r | n >= 1 | r >= 1 |" << endl; // Ketentuan Bilangan Kombinasi
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
		cout << "\nBerikut Kombinasi C(n,r) : " << endl;
		cout << "C(" << n << "," << r << ") = " << n << "! / ((" << n << " - " << r << ")! * " << r << "!)" << endl;
		cout << "C(" << n << "," << r << ") = " << n << "! / (" << n-r << "! * " << r << "!)" << endl;
		cout << "C(" << n << "," << r << ") = (";
		for (i = 0; i < n; i++) // Output Perulangan Proses Kombinasi
		{
			cout << n-i;		
			if (n-i == 1)
			{
				cout << ") / ((";
				for (j = 0; j <= (n-r)-j; j++)
				{
					cout << (n-r)-j;
					
					if ((n-r)-j == 1 || n-r == 0)
					{					
						cout << ") * (";
						for (k = 0; k < r; k++)
						{
							cout << r-k;

							if (r-k == 1 || r-k == 0)
								cout << "))";
							else
								cout << " * ";
						}
					}
					else
						cout << " * ";
				}
			}
			else
				cout << " * ";
		}
		cout << endl;
		cout << "C(" << n << "," << r << ") = " << Faktorial(n) << " / (" << Faktorial(n-r) << " * " << Faktorial(r) << ")" << endl;
		cout << "C(" << n << "," << r << ") = " << Faktorial(n) << " / (" << Faktorial(n-r) << " * " << Faktorial(r) << ")" << endl;
		cout << "C(" << n << "," << r << ") = " << Faktorial(n) << " / " << Faktorial(n-r) * Faktorial(r) << endl;
		cout << "C(" << n << "," << r << ") = " << Kombinasi(n,r);
		cout << endl;

		cout << "\nKombinasi C(" << n << "," << r << ") = " << Kombinasi(n,r) << endl; // Output Hasil Kombinasi Dari Nilai n dan Nilai r
	}
}
