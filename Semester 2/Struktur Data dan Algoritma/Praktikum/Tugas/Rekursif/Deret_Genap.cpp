// Algoritma Deret Genap
#include <iostream>

using namespace std;

// Fungsi Deret Genap
int Deret_Genap (int n)
{
	// Proses
	if (n == 1) // Proses Rumus Deret Genap
		return 2;
	else if (n > 1) // Proses Deret Genap
		return 2 * n + Deret_Genap(n-1);
}

	/* 
 	Contoh Penjelasan Algoritma :

	Dengan Ketentuan | n >= 1 |
	Jika Nilai n = 3

	Maka nilai n dimasukkan kedalam fungsi Deret_Genap(n)

	Deret_Genap(n) = 2 * n + Deret_Genap(n-1)

	Berikut Penjelasannya :
	Deret_Genap(3) = 2 * 3 + Deret_Genap(3-1)
	Deret_Genap(3) = 2 * 3 + Deret_Genap(2)
	Deret_Genap(3) = 6 + Deret_Genap(2)

	Karena Deret_Genap(2) tidak diketahui maka harus dicari terlebih dahulu dengan fungsi Deret_Genap(n)
	
	Deret_Genap(2) = 2 * 2 + Deret_Genap(2-1)
	Deret_Genap(2) = 4 + Deret_Genap(1)

	Dari ketentuan yang berlaku pada rumus deret jika n = 1 maka hasilnya adalah 2

	Deret_Genap(1) = 2
	Deret_Genap(2) = 4 + Deret_Genap(1)
	Deret_Genap(2) = 4 + 2
	Deret_Genap(2) = 6
		
	Jika Deret_Genap(2) sudah diketahui maka Deret_Genap(3) dapat diketahui

	Deret_Genap(2) = 6
	Deret_Genap(3) = 6 + Deret_Genap(2)
	Deret_Genap(3) = 6 + 6		
	Deret_Genap(3) = 12

	Maka Hasil Deret Genap Nilai n = 3 Adalah 12
	*/


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
