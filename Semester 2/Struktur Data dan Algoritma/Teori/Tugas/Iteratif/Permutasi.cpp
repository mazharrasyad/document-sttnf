// Algoritma Permutasi
#include <iostream>

using namespace std;

// Fungsi Faktorial
int Faktorial (int n)
{
	int i, hasil = 1;

	for (i = 0; i < n; i++) // Proses Iteratif Faktorial
	{
		hasil = hasil * (i + 1);
	}
	return hasil;
}

// Fungsi Permutasi
int Permutasi (int n, int r)
{
	int i, hasil = 1, proses_1 = 1;	
	
	for (i = 0; i < n; i++) // Proses Iteratif Faktorial(n)
	{
		hasil = hasil * (i + 1);
	}
	for (i = 0; i < (n-r); i++) // Proses Iteratif Faktorial
	{
		proses_1 = proses_1 * (i + 1);
	}
	hasil = hasil / proses_1;
	return hasil;
}

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
