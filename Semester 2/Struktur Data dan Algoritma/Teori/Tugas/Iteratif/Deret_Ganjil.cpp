// Algoritma Deret Ganjil
#include <iostream>

using namespace std;

// Fungsi Deret Ganjil
int Deret_Ganjil (int n)
{
	int i, hasil = 1;

	for (i = 0; i <= n; i++)
	{
		hasil = hasil + ((2 * i) - 1);
	}

	return hasil;
}

// Program Utama
int main()
{	
	// Deklarasi
	int n,i,j,k;

	cout << "---------- Algoritma Deret Ganjil ----------" << endl << endl;

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
		cout << "\nBerikut Deret Ganjil(n) : " << endl;
		cout << "Proses Deret Ganjil(" << n << ") = ";
		
		k = -1;
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
		cout << endl << endl;

		for (i = 0; i < n; i++)
		{
			cout << "Deret Ganjil n = " << i + 1 << " Adalah ";
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
			k = -1;
			cout << " = " << Deret_Ganjil(n-(n-(i+1))) << endl;
		}

		cout << "\nDeret Ganjil(" << n << ") = " << Deret_Ganjil(n) << endl; // Output Hasil Deret Ganjil Dari Nilai n
	}
}
