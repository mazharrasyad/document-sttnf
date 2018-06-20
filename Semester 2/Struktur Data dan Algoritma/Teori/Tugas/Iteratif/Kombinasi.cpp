// Algoritma Kombinasi
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

// Fungsi Kombinasi
int Kombinasi (int n, int r)
{
	int i, hasil = 1, proses_1 = 1, proses_2 = 1;	
	
	for (i = 0; i < n; i++) // Proses Iteratif Faktorial(n)
	{
		hasil = hasil * (i + 1);
	}
	for (i = 0; i < (n-r); i++) // Proses Iteratif Faktorial
	{
		proses_1 = proses_1 * (i + 1);
	}
	for (i = 0; i < r; i++) // Proses Iteratif Faktorial
	{
		proses_2 = proses_2 * (i + 1);
	}
	hasil = hasil / (proses_1 * proses_2);
	return hasil;
}

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
