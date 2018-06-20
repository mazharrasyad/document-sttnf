/*
	Muhammad Azhar Rasyad
	0110217029
	Teknik Informatika 1
	Struktur Data dan Algoritma
	STT Terpadu Nurul Fikri
*/

#include <iostream>

using namespace std;

int Sequential_Search (int n);
int Binary_Search (int n);
int Sorting (int Data[], int n);

int main ()
{
	int p,n;

	cout << "<----- Algoritma Searching ----->" << endl << endl;
	cout << "1. Sequential Search" << endl;
	cout << "2. Binary Search" << endl;
	cout << "\nMasukkan Pilihan Searching = ";
	cin >> p;

	switch(p)
	{
		case 1:
			cout << "\nMasukkan Jumlah n = ";
			cin >> n;
			Sequential_Search(n);
			break;

		case 2:
			cout << "\nMasukkan Jumlah n = ";
			cin >> n;
		  Binary_Search(n);
			break;

		default:
			cout << "\nError Pilihan Tidak Ada" << endl;
	}
}

int Sequential_Search(int n)
{
  // Deklarasi
	int x,a,i;
  int Data[n];
  bool ketemu;
	// End Deklarasi

	// Input
	cout << endl;

	for (a = 0; a < n; a++)
	{
		cout << "Masukkan Data[" << a << "] = ";
		cin >> Data[a];
	}

	cout << endl;

	cout << "Data Sebelum Diurutkan = ";

	for (a = 0; a < n; a++)
	{
		cout << Data[a] << " ";
	}

	cout << endl << endl;

  cout << "Masukkan Nilai Yang Dicari x = ";
  cin >> x;
  // End Input

  // Proses
  i = 0;
  ketemu = false;

  cout << endl;

  while ((ketemu == false) && (i <= n))
  {
    cout << "Data[" << i << "] = " << Data[i] << endl;

    if (Data[i] == x)
      ketemu = true;
    else
      i = i + 1;
  }
  // End Proses

  // Output
  cout << endl;

  if (ketemu == true)
    cout << "Data yang dicari ada di Data[" << i << "] yaitu " << x << endl;
  else
    cout << "Data tidak ditemukan" << endl;
  // End Output
}

int Binary_Search(int n)
{
  // Deklarasi
	int x,a,i=0,L,R,m;
  int Data[n];
  bool ketemu;
	// End Deklarasi

	// Input
	cout << endl;

	for (a = 0; a < n; a++)
	{
		cout << "Masukkan Data[" << a << "] = ";
		cin >> Data[a];
	}

	cout << endl;

	cout << "Data Sebelum Diurutkan = ";

	for (a = 0; a < n; a++)
	{
		cout << Data[a] << " ";
	}

  Sorting(Data, n);

  cout << "\nMasukkan Nilai Yang Dicari x = ";
  cin >> x;
  // End Input

  // Proses
  L = 0;
  m = 0;
  R = n - 1;
  ketemu = false;

  while ((L <= R) && (ketemu == false))
  {
    m = (L + R) / 2;

    // Output
    cout << "\n<-----Loop Ke " << i+1 << "----->" <<  endl;
    cout << "Awal = " << Data[L] << endl;
    cout << "Tengah = " << Data[m] << endl;
    cout << "Ujung = " << Data[R] << endl;

    if (Data[m] == x)
      ketemu = true;

    if (x < Data[m])
      R = m - 1;

    if (x > Data[m])
      L = m + 1;

    i++;
  }
  // End Proses

  // Output
  cout << endl;

  if (ketemu == true)
    cout << "Data yang dicari ada di Data[" << m << "] yaitu " << x << endl;
  else
    cout << "Data tidak ditemukan" << endl;
  // End Output
}

int Sorting(int Data[], int n)
{
  // Deklarasi
	int i = 0,j,k = 0,x,a;
	// End Deklarasi

  // Proses
  while (i < n - 1)
  {
    j = n - 1;
    while (j >= i)
    {
      if(Data[j-1] > Data[j])
      {
        x = Data[j-1];
        Data[j-1] = Data[j];
        Data[j] = x;
      }
      j = j - 1;
    }
    i = i + 1;
  }
  // End Proses

  // Output
	cout << endl;

	cout << "\nData Sesudah Diurutkan = ";

	for (a = 0; a < n; a++)
	{
		cout << Data[a] << " ";
	}

	cout << endl;
	// End Output
}
