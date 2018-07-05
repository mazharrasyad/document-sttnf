#include <iostream>

using namespace std;

int Sequential_Search (int n, int Data[]);
int Binary_Search (int n, int Data[]);

int main()
{
  int pilihan;
  int n;
  int i;

  cout << "\033[2J\033[;1H";
  cout << "----- Searching -----" << endl << endl;
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
  cout << "1. Sequential Search" << endl;
  cout << "2. Binary Search" << endl << endl;
  cout << "Masukkan pilihan : ";
  cin >> pilihan;

  switch(pilihan)
  {
    case 1:
      cout << "\033[2J\033[;1H";
      cout << "----- 1. Sequential Search -----" << endl << endl;
      Sequential_Search(n,Data);
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
      Binary_Search(n,Data);
      for(i = 0; i < n; i++)
      {
        cout << "Data Ke " << i << " = " << Data[i] << endl;
      }
      cin.ignore().get();
      goto menu_utama;
      break;
  }
}

int Sequential_Search (int n, int Data[])
{
  int i = 0;
  int x;
  bool ketemu = false;

  cout << "Masukkan nilai x : ";
  cin >> x;

  while(ketemu == false && i < n)
  {
    if(Data[i] == x)
      ketemu = true;
    else
      i++;
  }

  cout << endl;

  if(ketemu == true)
    cout << "Data ditemukan di Data Ke " << i << " dengan x = " << x << endl << endl;
  else
    cout << "Data tidak ditemukan" << endl << endl;
}

int Binary_Search (int n, int Data[])
{
  int i = 1;
  int j;
  int x;
  int l;
  int m;
  int r;
  int ketemu = false;

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

  cout << "Masukkan nilai x : ";
  cin >> x;

  l = 0;
  r = n - 1;

  while(ketemu == false && l <= r)
  {
    m = (l + r) / 2;

    if(Data[m] == x)
      ketemu = true;

    if(x < Data[m])
      r = m - 1;
    else
      l = m + 1;
  }

  cout << endl;

  if(ketemu == true)
    cout << "Data ditemukan di Data Ke " << m << " dengan x = " << x << endl << endl;
  else
    cout << "Data tidak ditemukan" << endl << endl;
}
