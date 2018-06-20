// Algoritma Hanoi
#include<iostream>
 
using namespace std;
 
// Fungsi Hanoi
int Hanoi(int n, char m1, char m2, char m3)
{
	// Proses
	if(n == 1) // Proses Rumus Hanoi
		cout << "Dari Menara " << m1 << " Bangunan 1 Ke Menara " << m3 << endl;
	else if (n > 1) // Proses Hanoi
	{
		Hanoi(n-1,m1,m3,m2);
		cout << "Dari Menara " << m1 << " Bangunan " << n << " Ke Menara " << m3 << endl;	
		Hanoi(n-1,m2,m1,m3);
	}
}
 
	/* 
 	Contoh Penjelasan Algoritma :

	Dengan Ketentuan n >= 1
	Jika Nilai n = 2
	
	Maka nilai n dimasukkan ke dalam fungsi Hanoi(n,m1,m2,m3) dan m1 m2 m3 merupakan menaranya
	
	Proses Jika n > 1
	Hanoi(n,m1,m2,m3) = Hanoi(n-1,m1,m3,m2) Proses ke 1	
	Kemudian fungsi Hanoi dipanggil lagi dengan isi yang berbeda menjadi Hanoi(n-1,m1,m3,m2)

	Dari Menara m1 Bangunan n Ke Menara m3 	Proses ke 2

	Hanoi(n,m1,m2,m3) = Hanoi(n-1,m2,m1,m3) Proses Ke 3
	Kemudian fungsi Hanoi dipanggil lagi dengan isi yang berbeda menjadi Hanoi(n-1,m2,m1,m3)

	Proses n = 1
	Hanoi(n,m1,m2,m3) = Dari m1 Bangunan 1 Ke m3

	Berikut Penjelasannya :
	Susunan Bangunan dimulai dari paling bawah Bangunan 2 dan paling atas Bangunan 1

	Proses Jika n > 1
	Hanoi(2,A,B,C) = Hanoi(2-1,A,C,B) 	
	Hanoi(2,A,B,C) = Hanoi(1,A,C,B)		

	Dengan Ketentuan hanoi jika n = 1 maka fungsi Hanoi(1,A,C,B) dapat diketahui

	Hanoi(1,A,C,B) = Dari Menara A Bangunan 1 Ke Menara B		Proses ke 1
	Hanoi(2,A,B,C) = Hanoi(1,A,C,B)					Proses ke 1
	Hanoi(2,A,B,C) = Dari Menara A Bangunan 1 Ke Menara B 		Proses ke 1 Hasil

	Kemudian ke proses selanjutnya dan nilai n tidak berkurang karena bukan di deklarasi
	Dari Menara A Bangunan 2 Ke Menara C				Proses ke 2 Hasil

	Setelah selesai proses 2 maka proses terakhir bisa dijalankan

	Hanoi(2,A,B,C) = Hanoi(2-1,B,A,C)
	Hanoi(2,A,B,C) = Hanoi(1,B,A,C)
	
	Nilai n tidak berkurang karena tidak di deklarasi tetapi menara yang berpindah posisi

	Hanoi(1,B,A,C) = Dari Menara B Bangunan 1 Ke Menara C		Proses ke 3
	Hanoi(2,A,B,c) = Hanoi(1,B,A,C)					Proses ke 3
	Hanoi(2,A,B,c) = Dari Menara B Bangunan 1 Ke Menara C		Proses ke 3 Hasil

	Dan Jika Digabungkan dari semua proses tersebut menjadi

	| Menara A |	| Menara B |	| Menara C |	Posisi Pertama
	     1
	     2

	Proses Ke 1 = Dari Menara A Bangunan 1 Ke Menara B 

	| Menara A |	| Menara B |	| Menara C |	Posisi Kedua
	     2		     1
	     
	Proses Ke 2 = Dari Menara A Bangunan 2 Ke Menara C

	| Menara A |	| Menara B |	| Menara C |	Posisi Ketiga
	     		     1		     2

	Proses Ke 3 = Dari Menara B Bangunan 1 Ke Menara C

	| Menara A |	| Menara B |	| Menara C |	Posisi Keempat
	     		     		     1
					     2

	Maka Hanoi dari Jumlah Bangunan 2 adalah sebagai berikut :

	Dari Menara A Bangunan 1 Ke Menara B 
	Dari Menara A Bangunan 2 Ke Menara C
	Dari Menara B Bangunan 1 Ke Menara C
	*/

// Program Utama
int main()
{
	// Deklarasi
	int n,i;
	char a = 'A', b = 'B', c = 'C';

	cout << "---------- Algoritma Hanoi ----------" << endl << endl;
	
	// Input
	cout << "Dengan Ketentuan | n >= 1 |" << endl; // Ketentuan Hanoi
	cout << "Masukkan Jumlah Bangunan = ";
	cin >> n;

	// Verifikasi
	if (n < 0 || n == 0)
		cout << "\nError Masukkan Nilai n >= 1" << endl;
	else
	{
		// Output
		cout << "\n| Menara A | \t| Menara B | \t| Menara C | " << endl;
		for (i = 0; i < n; i++)
		{
			cout << "     " << i+1 << endl;
		}
	
		cout << endl;	
		Hanoi(n,a,b,c);
	}
		cout << "\n| Menara A | \t| Menara B | \t| Menara C | " << endl;
		for (i = 0; i < n; i++)
		{			
			cout << "\t\t\t\t     " << i+1 << endl;
		}
}
