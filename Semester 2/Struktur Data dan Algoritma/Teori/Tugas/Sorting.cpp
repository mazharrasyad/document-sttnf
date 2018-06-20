#include <iostream>

using namespace std;

int Tukar(int *a, int *b);
int Output_Data(int n, int Data[]);
int Insertion_Sort(int n, int Data[]);
int Binary_Sort(int n, int Data[]);
int Selection_Sort(int n, int Data[]);
int Bubble_Sort(int n, int Data[]);
int Shell_Sort(int n, int Data[]);
int Quick_Sort(int n, int Data[]);
int Rumus_Quick_Sort(int L, int R, int Data[]);
int Merge_Sort(int n, int Data[]);
int Rumus_Merge_Sort(int awal, int akhir, int Data[]);
int Rumus_Merge(int awal, int mid, int akhir, int Data[]);

int main()
{
	// Deklarasi
	int p,n,i;

	cout << "Masukkan Banyak Data = ";
	cin >> n;

	int Data[n];
	// End Deklarasi

	// Input
	cout << endl;
	for(i = 0; i < n; i++)
	{
		cout << "Masukkan Data [" << i << "] = ";
		cin >> Data[i];
	}

	cout << endl;
	cout << "Data Sebelum Diurutkan = ";
	for(i = 0; i < n; i++)
	{
		cout << Data[i] << " ";
	}
	cout << endl << endl;
	// End Input

	// Proses & Output
	cout << "<----- Algoritma Sorting ----->" << endl << endl;
	cout << "1. Insertion Sort" << endl;
	cout << "2. Binary Insertion Sort" << endl;
	cout << "3. Selection Sort" << endl;
	cout << "4. Bubble Sort" << endl;
	cout << "5. Shell Sort" << endl;
	cout << "6. Quick Sort" << endl;
	cout << "7. Merge Sort" << endl;
	cout << "\nMasukkan Pilihan Sorting = ";
	cin >> p;

	switch(p)
	{
		case 1:
			cout << endl;
			Insertion_Sort(n,Data);
			Output_Data(n,Data);
			break;

		case 2:
			cout << endl;
			Binary_Sort(n,Data);
			Output_Data(n,Data);
			break;

		case 3:
			cout << endl;
			Selection_Sort(n,Data);
			Output_Data(n,Data);
			break;

		case 4:
			cout << endl;
			Bubble_Sort(n,Data);
			Output_Data(n,Data);
			break;

		case 5:
			cout << endl;
			Shell_Sort(n,Data);
			Output_Data(n,Data);
			break;

		case 6:
			cout << endl;
			Quick_Sort(n,Data);
			Output_Data(n,Data);
			break;

		case 7:
			cout << endl;
			Merge_Sort(n,Data);
			Output_Data(n,Data);
			break;

		default:
			cout << "\nError Pilihan Tidak Ada" << endl;
	}
	// End Proses & Output
}

int Tukar(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int Output_Data(int n, int Data[])
{
	int i;
	cout << endl;
	cout << "Data Sebelum Diurutkan = ";
	for(i = 0; i < n; i++)
	{
		cout << Data[i] << " ";
	}
	cout << endl;
}

int Insertion_Sort(int n, int Data[])
{
	int i = 1;
	int j;
	int x;

	cout << "<----- Insertion Sort ----->" << endl;

	while (i < n)
	{
		x = Data[i];
		j = i - 1;

		while (x < Data[j])
		{
			Data[j + 1] = Data[j];
			j = j - 1;
		}
		Data [j + 1] = x;
		i = i + 1;
	}
}

int Binary_Sort(int n, int Data[])
{
	int i = 1;
	int j;
	int x;
	int l;
	int r;
	int m;

	cout << "<----- Binary Insertion Sort ----->" << endl;

	while (i < n)
	{
		x = Data[i];
		l = 0;
		r = i - 1;

		while (l <= r)
		{
			m = (l + r) / 2;

			if (x < Data[m])
				r = m - 1;
			else
				l = m + 1;
		}

		j = i - 1;

		while (j >= l)
		{
			Data[j+1] = Data[j];
			j = j - 1;
		}
		Data[l] = x;
		i = i + 1;
	}
}

int Selection_Sort(int n, int Data[])
{
	int i = 0;
	int j;
	int k;
	int x;

	cout << "<----- Selection Sort ----->" << endl;

	while (i < n-1)
	{
		k = i;
		j = i + 1;

		while (j < n)
		{
			if (Data[k] > Data[j])
				k = j;

			j = j + 1;
		}
		Tukar(&Data[i], &Data[k]);
		i = i + 1;
	}
}

int Bubble_Sort(int n, int Data[])
{
	int i = 0;
	int j;
	int k = 0;
	int x;

	cout << "<----- Bubble Sort ----->" << endl;

	while (i < n - 1)
	{
		j = n - 1;
		while (j >= i)
		{
			if(Data[j-1] > Data[j])
			{
				Tukar(&Data[j-1], &Data[j]);
			}
			j = j - 1;
		}
		i = i + 1;
	}
}

int Shell_Sort(int n, int Data[])
{
	int i = 0;
	int j;
	int k = 0;
	int x;
	int jarak;
	bool sudah;

	cout << "<----- Shell Sort ----->" << endl;

	jarak = n;
	while (jarak > 1)
	{
		jarak = jarak / 2;
		sudah = false;
		while (sudah == false)
		{
			sudah = true;
			j = 0;
			while (j < n - jarak)
			{
				if (Data[j] > Data[j + jarak])
				{
					Tukar(&Data[j], &Data[j + jarak]);
					sudah = false;
				}

				j = j + 1;
			}
		}
	}
}

int Quick_Sort(int n, int Data[])
{
	cout << "<----- Quick Sort ----->" << endl;

	Rumus_Quick_Sort(0,n,Data);
}

int Rumus_Quick_Sort(int L, int R, int Data[])
{
	int x;
	int i;
	int j;

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
			Rumus_Quick_Sort(L,j,Data);
		if(i<R)
			Rumus_Quick_Sort(i,R,Data);
	}
}

int Merge_Sort(int n, int Data[])
{
	cout << "<----- Merge Sort ----->" << endl;

	Rumus_Merge_Sort(0,n,Data);
}

int Rumus_Merge_Sort(int awal, int akhir, int Data[])
{
	if(akhir-awal != 1)
	{
		int mid;

		mid = (awal + akhir) / 2;
		Rumus_Merge_Sort(awal, mid, Data);
		Rumus_Merge_Sort(mid, akhir, Data);
		Rumus_Merge(awal, mid, akhir, Data);
	}
}

int Rumus_Merge(int awal, int mid, int akhir, int Data[])
{
	int temp[100];
	int tempAwal = awal;
	int tempMid = mid;
	int i = 0;
	int j;
	int k;

	while(tempAwal < mid && tempMid < akhir)
	{
		if(Data[tempAwal] < Data[tempMid])
		{
			temp[i] = Data[tempAwal];
			tempAwal++;
		}
		else
		{
			temp[i] = Data[tempMid];
			tempMid++;
		}

		i++;
	}

	while(tempAwal < mid)  //kalau masih ada yang sisa
	{
		temp[i] = Data[tempAwal];
		tempAwal++;
		i++;
	}

	while(tempMid < akhir)
	{
		temp[i] = Data[tempMid];
		tempMid++;
		i++;
	}

	for(j = 0, k = awal; j < i, k < akhir; j++, k++)  //mengembalikan ke array semula, tapi
	{
		Data[k] = temp[j]; //sudah urut
	}
}
