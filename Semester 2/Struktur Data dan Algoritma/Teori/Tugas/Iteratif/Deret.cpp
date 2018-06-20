// Algoritma Deret
#include <iostream>

using namespace std;

// Fungsi Deret
int Deret (int n)
{
	int i, hasil = 0;

	for (i = 0; i < n; i++)
	{
		hasil = hasil + (i + 1);
	}

	return hasil;
}

// Program Utama
int main()
{	
	// Deklarasi
	int n,i,j;

	cout << "---------- Algoritma Deret ----------" << endl << endl;

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
		cout << "\nBerikut Deret(n) : " << endl;
		cout << "Proses Deret(" << n << ") = ";
		for (i = 0; i < n; i++) // Output Perulangan Proses Deret
		{
			cout << i + 1;
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
			cout << "Deret n = " << i + 1 << " Adalah ";
			for (j = 0; j <= i; j++)
			{
				if (i + 1 == 1)
					cout << "Dari Rumus";
				else
				{
					cout << j + 1;
					if (j + 1 == i + 1)
						cout << "";
					else
						cout << " + ";
				}
			}
			cout << " = " << Deret(n-(n-(i+1))) << endl;
		}
		
		cout << "\nDeret(" << n << ") = " << Deret(n) << endl; // Output Hasil Deret Dari Nilai n
	}
}
