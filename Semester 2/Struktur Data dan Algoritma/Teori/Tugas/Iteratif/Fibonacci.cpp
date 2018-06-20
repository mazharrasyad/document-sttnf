// Algoritma Fibonacci
#include <iostream>

using namespace std;

// Fungsi Fibonacci
int Fibonacci (int n)
{
	int i, hasil = 1, proses_1 = 1, proses_2 = 1;

	for (i = 2; i < n; i++) // Output Perulangan Barisan Bilangan Fibonacci
	{
		hasil = proses_1 + proses_2;
		proses_1 = proses_2;
		proses_2 = hasil;
	}
	return hasil;
}

// Program Utama
int main()
{	
	// Deklarasi
	int n,i; // Variabel

	cout << "---------- Algoritma Fibonacci ----------" << endl << endl;

	// Input
	cout << "Dengan Ketentuan | n >= 1 |" << endl; // Ketentuan Bilangan Fibonacci
	cout << "Masukkan Nilai n = ";
	cin >> n; // Input Nilai n Dari Keyboard

	// Verifikasi
	if (n < 0 || n == 0)
		cout << "\nError Masukkan Nilai n >= 1" << endl;
	else
	{
		// Output
		cout << "\nBerikut Barisan Bilangan Fibonacci(n) : " << endl;
		for (i = 0; i < n; i++) // Output Perulangan Barisan Bilangan Fibonacci
		{
			cout << "Nilai n = " << i+1 << ", Fibonacci = " << Fibonacci(i+1);

			if (n-(n-i) == 0 || n-(n-(i)) == 1)		
				cout << " Dari Rumus" << endl;	
			else
				cout << " Dari " << Fibonacci(n-(n-i)) << " + " << Fibonacci(n-(n-(i-1))) << endl;
		}

		cout << "\nFibonacci n(" << n << ") = " << Fibonacci(n) << endl; // Output Hasil Fibonacci Dari Nilai n
	}
}
