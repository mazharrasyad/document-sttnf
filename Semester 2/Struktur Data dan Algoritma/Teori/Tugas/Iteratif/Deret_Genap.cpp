// Algoritma Deret Genap
#include <iostream>

using namespace std;

// Fungsi Deret Genap
int Deret_Genap (int n)
{
	int i, hasil = 2;

	for (i = 2; i <= n; i++)
	{
		hasil = hasil + (2 * i);
	}

	return hasil;
}

// Program Utama
int main()
{	
	// Deklarasi
	int n,i,j,k;

	cout << "---------- Algoritma Deret Genap ----------" << endl << endl;

	// Input
	cout << "Dengan Ketentuan | n >= 1 |" << endl; // Ketentuan Bilangan Deret
	cout << "Masukkan Nilai n = ";
	cin >> n;

	// Verifikasi
	if (n < 1)
		cout << "\nError Masukkan Nilai n >= 1" << endl;
	else
	{
		// Output
		cout << "\nBerikut Deret Genap(n) : " << endl;
		cout << "Proses Deret Genap(" << n << ") = ";
		for (i = 0; i < n; i++) // Output Perulangan Proses Deret
		{
			k = k + 2;
			cout << k;

			if ((i + 1) == n)
			{
				cout << "";
			}
			else
				cout << " + ";
		}
		k = 0;
		cout << endl << endl;

		for (i = 0; i < n; i++)
		{
			cout << "Deret Genap n = " << i + 1 << " Adalah ";
			for (j = 0; j <= i; j++)
			{
				if (i + 1 == 1)
					cout << "Dari Rumus";
				else
				{
					k = k + 2;
					cout << k;

					if (j + 1 == i + 1)
						cout << "";
					else
						cout << " + ";
				}
			}
			k = 0;
			cout << " = " << Deret_Genap(n-(n-(i+1))) << endl;
		}

		cout << "\nDeret Genap(" << n << ") = " << Deret_Genap(n) << endl; // Output Hasil Deret Genap Dari Nilai n
	}
}
