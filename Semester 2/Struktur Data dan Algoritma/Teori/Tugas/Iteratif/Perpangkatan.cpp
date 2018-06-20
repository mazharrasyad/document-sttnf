// Algoritma Perpangkatan
#include <iostream>

using namespace std;

// Fungsi Perpangkatan
int Perpangkatan (int x, int n)
{
	int i, hasil = 1;

	for (i = 0; i < n; i++) // Output Perulangan Proses Perpangkatan
	{
		hasil = hasil * x;
	}

	return hasil;
}

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
