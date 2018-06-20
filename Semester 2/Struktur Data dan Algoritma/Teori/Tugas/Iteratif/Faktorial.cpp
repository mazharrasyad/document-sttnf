// Algoritma Faktorial
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

// Program Utama
int main()
{	
	// Deklarasi
	int n,i;

	cout << "---------- Algoritma Faktorial ----------" << endl << endl;

	// Input
	cout << "Dengan Ketentuan | n > 1 |" << endl; // Ketentuan Bilangan Faktorial
	cout << "Masukkan Nilai n = ";
	cin >> n; // Input Nilai n Dari Keyboard

	// Verifikasi
	if (n < 1)
		cout << "\nError Masukkan Nilai n > 1" << endl;
	else
	{
		// Output
		 
		cout << "\nFaktorial n(" << n << ") = ";
		for (i = 0; i < n; i++) // Output Perulangan Faktorial
		{
			cout << i + 1;
			if (i + 1 == n)
				cout << "";
			else
				cout << " * ";
		}
		cout << "\nFaktorial n(" << n << ") = " << Faktorial(n) << endl; // Output Hasil Faktorial Dari Nilai n
	}
}
