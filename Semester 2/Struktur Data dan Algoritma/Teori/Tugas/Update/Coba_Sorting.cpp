#include <iostream>

using namespace std;

int Insertion_Sort (int n, int Data[]);
int Binary_Sort (int n, int Data[]);
int Selection_Sort (int n, int Data[]);
int Bubble_Sort (int n, int Data[]);
int Shell_Sort (int n, int Data[]);

int main()
{
  int pilihan;
  int n;
  int i;

  cout << "\033[2J\033[;1H";
  cout << "----- Sorting -----" << endl << endl;
  cout << "Masukkan banyak n : ";
  cin >> n;
  cout << endl;

  int Data[n];
  for(i = 0; i < n; i++)
  {
    cout << "Data Ke " << i << " = ";
    cin >> Data[i];
  }

  menu_utama:
  cout << "\033[2J\033[;1H";
  cout << "----- Sorting -----" << endl << endl;
  cout << "1. Insertion Sort" << endl;
  cout << "2. Binary Sort" << endl;
  cout << "3. Selection Sort" << endl;
  cout << "4. Bubble Sort" << endl;
  cout << "5. Shell Sort" << endl;
  cout << "6. Quick Sort" << endl;
  cout << "7. Merge Sort" << endl << endl;
  cout << "Masukkan pilihan : ";
  cin >> pilihan;

  switch(pilihan)
  {
    case 1:
      cout << "\033[2J\033[;1H";
      cout << "----- 1. Insertion Sort -----" << endl << endl;
      Insertion_Sort(n,Data);
      for(i = 0; i < n; i++)
      {
        cout << "Data Ke " << i << " = " << Data[i] << endl;
      }
      cin.ignore().get();
      goto menu_utama;
      break;

    case 2:
      cout << "\033[2J\033[;1H";
      cout << "----- 2. Binary Sort -----" << endl << endl;
      Binary_Sort(n,Data);
      for(i = 0; i < n; i++)
      {
        cout << "Data Ke " << i << " = " << Data[i] << endl;
      }
      cin.ignore().get();
      goto menu_utama;
      break;

    case 3:
      cout << "\033[2J\033[;1H";
      cout << "----- 3. Selection Sort -----" << endl << endl;
      Selection_Sort(n,Data);
      for(i = 0; i < n; i++)
      {
        cout << "Data Ke " << i << " = " << Data[i] << endl;
      }
      cin.ignore().get();
      goto menu_utama;
      break;

    case 4:
      cout << "\033[2J\033[;1H";
      cout << "----- 4. Bubble Sort -----" << endl << endl;
      Bubble_Sort(n,Data);
      for(i = 0; i < n; i++)
      {
        cout << "Data Ke " << i << " = " << Data[i] << endl;
      }
      cin.ignore().get();
      goto menu_utama;
      break;

    case 5:
      cout << "\033[2J\033[;1H";
      cout << "----- 5. Shell Sort -----" << endl << endl;
      Shell_Sort(n,Data);
      for(i = 0; i < n; i++)
      {
        cout << "Data Ke " << i << " = " << Data[i] << endl;
      }
      cin.ignore().get();
      goto menu_utama;
      break;
  }
}

int Insertion_Sort (int n, int Data[])
{
  int i = 1;
  int j;
  int x;

  while(i < n)
  {
    x = Data[i];
    j = i - 1;
    while(x < Data[j])
    {
      Data[j + 1] = Data[j];
      j--;
    }
    Data[j + 1] = x;
    i++;
  }
}

int Binary_Sort (int n, int Data[])
{
  int i = 1;
  int j;
  int x;
  int l;
  int m;
  int r;

  while(i < n)
  {
    x = Data[i];
    j = i - 1;
    l = 0;
    r = i - 1;

    while(l <= r)
    {
      m = (l + r) / 2;

      if (x < Data[m])
        r = m - 1;
      else
        l = m + 1;
    }

    while(l <= j)
    {
      Data[j + 1] = Data[j];
      j--;
    }
    Data[j + 1] = x;
    i++;
  }
}

int Selection_Sort (int n, int Data[])
{
  int i = 0;
  int j;
  int k;
  int x;

  while(i < n-1)
  {
    k = i;
    j = i + 1;
    while(j < n)
    {
      if(Data[j] < Data[k])
        k = j ;

      j++;
    }
    x = Data[i];
    Data[i] = Data[k];
    Data[k] = x;
    i++;
  }
}

int Bubble_Sort (int n, int Data[])
{
  int i = 0;
  int j;
  int x;

  while(i < n-1)
  {
    j = n - 1;
    while(i < j)
    {
      if(Data[j] < Data[j-1])
      {
        x = Data[j];
        Data[j] = Data[j-1];
        Data[j-1] = x;
      }
      j--;
    }
    i++;
  }
}

int Shell_Sort (int n, int Data[])
{
  int i = 1;
  int j;
  int x;
  int jarak;
  bool sudah;

  jarak = n;
  while(i < jarak)
  {
    jarak = jarak / 2;
    sudah = false;
    while(sudah == false)
    {
      sudah = true;
      j = 0;
      while(j < n-jarak)
      {
        if(Data[j+jarak] < Data[j])
        {
          x = Data[j+jarak];
          Data[j+jarak] = Data[j];
          Data[j] = x;
          sudah = false;
        }
        j++;
      }
    }
  }
}
