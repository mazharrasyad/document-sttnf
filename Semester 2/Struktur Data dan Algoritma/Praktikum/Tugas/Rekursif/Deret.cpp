// Algoritma Deret
#include <iostream>

using namespace std;

// Fungsi Deret
int Deret (int n)
{
	// Proses
	if (n == 1) // Proses Rumus Deret
		return 1;
	else if (n > 1) // Proses Deret
		return n + Deret(n-1);
}

	/* 
 	Contoh Penjelasan Algoritma :

	Dengan Ketentuan | n >= 1 |
	Jika Nilai n = 3

	Maka nilai n dimasukkan kedalam fungsi Deret(n)

	Deret(n) = n + Deret(n-1)

	Berikut Penjelasannya :
	Deret(3) = 3 + Deret(3-1)
	Deret(3) = 3 + Deret(2)

	Karena Deret(2) tidak diketahui maka harus dicari terlebih dahulu dengan fungsi Deret(n)
	
	Deret(2) = 2 + Deret(2-1)
	Deret(2) = 2 + Deret(1)

	Dari ketentuan yang berlaku pada rumus Deret jika n = 1 maka hasilnya adalah 1

	Deret(1) = 1
	Deret(2) = 2 + Deret(1)
	Deret(2) = 2 + 1
	Deret(2) = 3
		
	Jika Deret(2) sudah diketahui maka Deret(3) dapat diketahui

	Deret(2) = 3
	Deret(3) = 3 + Deret(2)
	Deret(3) = 3 + 3
	Deret(3) = 6

	Maka Hasil Deret Nilai n = 3 Adalah 6
	*/

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
