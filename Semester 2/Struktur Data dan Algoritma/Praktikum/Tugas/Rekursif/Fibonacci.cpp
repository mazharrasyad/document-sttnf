// Algoritma Fibonacci
#include <iostream>

using namespace std;

// Fungsi Fibonacci
int Fibonacci (int n)
{
	// Proses
	if (n <= 2) // Proses Rumus Fibonacci
		return 1; 
	else if (n > 1) // Proses Fibonacci
		return Fibonacci(n-1) + Fibonacci(n-2); // Proses Pertambahan Dari 1 Nilai Sebelumnya Dan 2 Nilai Sebelumnya

	/* 
 	Contoh Penjelasan Algoritma :

	Dengan Ketentuan n > 1
	Jika Nilai n = 4

	Maka Nilai n Dimasukkan Kedalam Fungsi Fibonacci(n)

	Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)

	Berikut Penjelasannya :
	Fibonacci(4) = Fibonacci(4-1) + Fibonacci(4-2)
	Fibonacci(4) = Fibonacci(3) + Fibonacci(2)

	Dan Kemudian Mencari Nilai Fibonacci(3) + Fibonacci(2) Dengan Menggunakan Fungsi Yang Sama Secara Berulang
	Fibonacci(3) = Fibonacci(3-1) + Fibonacci (3-2)
	Fibonacci(3) = Fibonacci(2) + Fibonacci(1)
	Fibonacci(2) = Fibonacci(2-1) + Fibonacci (2-2)
	Fibonacci(2) = Fibonacci(1) + Fibonacci (0)

	Dan Kemudian Mencari Nilai Fibonacci(1) dan Fibonacci(0)
	Fibonacci(1) = 1
	Fibonacci(0) = 1

	Khusus Untuk n = 1 dan n = 2 Bernilai 1 Karena Rumus Fibonacci Sedangkan Sisanya Dijumlahkan

	Maka Hasilnya Kemudian Dijumlahkan
	Fibonacci(2) = Fibonacci(1) + Fibonacci (0) -> 1 "Karena n = 2"
	Fibonacci(3) = Fibonacci(2) + Fibonacci(1) -> 1 + 1 = 2
	Fibonacci(4) = Fibonacci(3) + Fibonacci(2) -> 2 + 1 = 3

	Maka Hasil Fibonacci Dari Nilai n = 4 Adalah 3
	*/
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
