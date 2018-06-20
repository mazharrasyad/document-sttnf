/*
	Muhammad Azhar Rasyad
	0110217029
	Teknik Informatika 1
	Struktur Data dan Algoritma
	STT Terpadu Nurul Fikri
*/

#include <iostream>

using namespace std;

int Tukar(int *a, int *b);
int Quick_Sort (int n);
int Merge_Sort (int n);

int main ()
{
	int p,n;

	cout << "<----- Algoritma Sorting ----->" << endl << endl;
	cout << "1. Quick Sort" << endl;
	cout << "2. Merge Sort" << endl;
	cout << "\nMasukkan Pilihan Sorting = ";
	cin >> p;

	switch(p)
	{
		case 1:
			cout << "\nMasukkan Jumlah n = ";
			cin >> n;
			Quick_Sort(n);
			break;

		case 2:
			cout << "\nMasukkan Jumlah n = ";
			cin >> n;
			Merge_Sort(n);
			break;

		default:
			cout << "\nError Pilihan Tidak Ada" << endl;
	}
}

int Tukar(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int Rumus_Quick_Sort(int Data[], int L, int R)
{
	int x,i,j;

	x = Data[(L+R)/2];
	i = L;
	j = R;

	while(i <= j)
	{
		while(Data[i] < x)
			i = i + 1;

		while(Data[j] > x)
			j = j - 1;

		if(i <= j)
		{
			Tukar(&Data[i], &Data[j]);
			i = i + 1;
			j = j - 1;
		}

		if(L<j)
			Rumus_Quick_Sort(Data,L,j);
		if(i<R)
			Rumus_Quick_Sort(Data,i,R);
	}
}

int Quick_Sort (int n)
{
	// Deklarasi
	int i,LK,LB,a;
	LK = 0;

	int Data[n];
	// End Deklarasi

	// Input
	cout << endl;

	for (i = 0; i < n; i++)
	{
		cout << "Masukkan Data[" << i << "] = ";
		cin >> Data[i];
	}

	cout << endl;

	cout << "Data Sebelum Diurutkan = ";

	for (i = 0; i < n; i++)
	{
		cout << Data[i] << " ";
	}

	cout << endl << endl;
	// End Input

	// Proses
	cout << "<----- Quick Sort ----->" << endl;

	for(LB = 0; LB < n; LB++)
	{
		Rumus_Quick_Sort(Data,LK,LB);

		// Output
		cout << "\nLoop Ke " << LB + 1 << " = ";

		for (i = 0; i < n; i++)
		{
			cout << "| " << Data[i] << " |";
		}
		// End Output
	}
	// End Proses

	// Output
	cout << endl << "\nData Sesudah Diurutkan = ";

	for (i = 0; i < n; i++)
	{
		cout << Data[i] << " ";
	}
	// End Output

	cout << endl;
}

int Rumus_Merge_Sort(int T1[], int T2[], int T3[], int J1, int J2, int &J3, int n)
{
	int i,j;

	i = 0;
	j = 0;
	J3 = 0;

	while ((i < J1) && (j < J2))
	{
		cout << "Nilai T1 " << i << " : " << T1[i] << endl;
		cout << "Nilai T2 " << j << " : " << T2[j] << endl;
		cout << endl;

		if(T1[i] < T2[j])
		{
			T3[J3] = T1[i];
			i = i + 1;
		}
		else
		{
			T3[J3] = T2[j];
			j= j + 1;
		}

		J3 = J3 + 1;
	}

	if(i >= J1)
	{
		i = j;
		while(i < J2)
		{
			T3[J3] = T2[i];
			i = i + 1;
			J3 = J3 + 1;
		}
	}
	else
	{
		j = i;
		while(j < J1)
		{
			T3[J3] = T1[j];
			j = j + 1;
			J3 = J3 + 1;
		}
	}

	// Output
	cout << "Data Sesudah Diurutkan = ";
	for(int i = 0; i < n; i++)
	{
		 cout << T3[i] << " ";
	}
	cout << endl;
	// End Output
}

int Merge_Sort (int n)
{
	int i,J1,J2,J3,x,y,LK,LB;
	LK = 0;
	LB = n;

	int T3[n];

	// Input
	cout << endl;

	for (i = 0; i < n; i++)
	{
		cout << "Masukkan Data[" << i << "] = ";
		cin >> T3[i];
	}

	cout << endl;

	cout << "Data Sebelum Diurutkan = ";

	for (i = 0; i < n; i++)
	{
		cout << T3[i] << " ";
	}

	cout << endl << endl;
	// End Input

	// Proses
	if (n % 2 == 0)
	{
		x = n / 2;
		y = n / 2;
	}
	else
	{
		x = n / 2;
		y = (n / 2) + 1;
	}

	int T1[x];
	int T2[y];

	for(i = 0; i < x; i++)
	{
		T1[i] = T3[i];
	}

	for(i = 0; i < y; i++)
	{
		T2[i] = T3[i+x];
	}

	cout << "T1[" << x << "] = {";
	for(i = 0; i < x; i++)
	{
		cout << T1[i];
		if(i+1 < x)
			cout << ",";
		else
			cout << "";
	}
	cout << "}" << endl;

	cout << "T2[" << x << "] = {";
	for(i = 0; i < y; i++)
	{
		cout << T2[i];
		if(i+1 < y)
			cout << ",";
		else
			cout << "";
	}
	cout << "}" << endl;

	J1 = x;
	J2 = y;

	// Proses
	cout << endl << "<----- Merge Sort ----->" << endl << endl;

	Rumus_Quick_Sort(T1, LK, x);
	Rumus_Quick_Sort(T2, LK, y);
	Rumus_Merge_Sort(T1, T2, T3, J1, J2, J3, n);

	// End Proses
}
