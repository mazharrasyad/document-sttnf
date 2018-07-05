#include <iostream>

using namespace std;

int Fibonacci (int n);
int Faktorial (int n);
int Kombinasi (int n, int r);
int Permutasi (int n, int r);
int Deret (int n);
int Deret_Ganjil (int n);
int Deret_Genap (int n);
int Perpangkatan (int n, int r);

int main()
{
  int pilihan;
  int n;
  int r;

  menu_utama:
  cout << "\033[2J\033[;1H";
  cout << "----- Iteratif -----" << endl << endl;
  cout << "1. Fibonacci" << endl;
  cout << "2. Faktorial" << endl;
  cout << "3. Kombinasi" << endl;
  cout << "4. Permutasi" << endl;
  cout << "5. Deret" << endl;
  cout << "6. Deret Ganjil" << endl;
  cout << "7. Deret Genap" << endl;
  cout << "8. Perpangkatan" << endl;
  cout << "Masukkan Pilihan : ";
  cin >> pilihan;

  switch(pilihan)
  {
      case 1:
        cout << "\033[2J\033[;1H";
        cout << "----- 1. Fibonacci -----" << endl << endl;
        cout << "Masukkan nilai n : ";
        cin >> n;
        cout << "Hasil = " << Fibonacci(n);
        cin.ignore().get();
        goto menu_utama;
        break;

      case 2:
        cout << "\033[2J\033[;1H";
        cout << "----- 2. Faktorial -----" << endl << endl;
        cout << "Masukkan nilai n : ";
        cin >> n;
        cout << "Hasil = " << Faktorial(n);
        cin.ignore().get();
        goto menu_utama;
        break;

      case 3:
        cout << "\033[2J\033[;1H";
        cout << "----- 3. Kombinasi -----" << endl << endl;
        cout << "Masukkan nilai n : ";
        cin >> n;
        cout << "Masukkan nilai r : ";
        cin >> r;
        cout << "Hasil = " << Kombinasi(n,r);
        cin.ignore().get();
        goto menu_utama;
        break;

      case 4:
        cout << "\033[2J\033[;1H";
        cout << "----- 4. Permutasi -----" << endl << endl;
        cout << "Masukkan nilai n : ";
        cin >> n;
        cout << "Masukkan nilai r : ";
        cin >> r;
        cout << "Hasil = " << Permutasi(n,r);
        cin.ignore().get();
        goto menu_utama;
        break;

      case 5:
        cout << "\033[2J\033[;1H";
        cout << "----- 5. Deret -----" << endl << endl;
        cout << "Masukkan nilai n : ";
        cin >> n;
        cout << "Hasil = " << Deret(n);
        cin.ignore().get();
        goto menu_utama;
        break;

      case 6:
        cout << "\033[2J\033[;1H";
        cout << "----- 6. Deret Ganjil -----" << endl << endl;
        cout << "Masukkan nilai n : ";
        cin >> n;
        cout << "Hasil = " << Deret_Ganjil(n);
        cin.ignore().get();
        goto menu_utama;
        break;

      case 7:
        cout << "\033[2J\033[;1H";
        cout << "----- 7. Deret Genap -----" << endl << endl;
        cout << "Masukkan nilai n : ";
        cin >> n;
        cout << "Hasil = " << Deret_Genap(n);
        cin.ignore().get();
        goto menu_utama;
        break;

      case 8:
        cout << "\033[2J\033[;1H";
        cout << "----- 8. Perpangkatan -----" << endl << endl;
        cout << "Masukkan nilai n : ";
        cin >> n;
        cout << "Masukkan nilai r : ";
        cin >> r;
        cout << "Hasil = " << Perpangkatan(n,r);
        cin.ignore().get();
        goto menu_utama;
        break;

      default :
        cout << "\033[2J\033[;1H";
        cout << "----- Error -----" << endl;
        cin.ignore().get();
        goto menu_utama;
        break;
  }
}

int Fibonacci (int n)
{
  // 1 + 1 + 2 + 3 + 5
  int i;
  int hasil;
  int proses_1 = 1;
  int proses_2 = 0;

  for(i = 0; i < n; i++)
  {
    hasil = proses_1 + proses_2;
    proses_1 = proses_2;
    proses_2 = hasil;
  }

  return hasil;
}

int Faktorial (int n)
{
  // 0! = 1, 1! = 1, 2! = 2 * 1
  int i;
  int hasil = 1;

  for(i = 0; i < n; i++)
  {
    hasil = hasil * (i + 1);
  }

  return hasil;
}

int Kombinasi (int n, int r)
{
  // nCr
  int i;
  int hasil = 1;
  int proses_1 = 1;
  int proses_2 = 1;

  for(i = 0; i < n; i++)
  {
    hasil = hasil * (i + 1);
  }

  for(i = 0; i < r; i++)
  {
    proses_1 = proses_1 * (i + 1);
  }

  for(i = 0; i < (n-r); i++)
  {
    proses_2 = proses_2 * (i + 1);
  }

  hasil = hasil / (proses_1 * proses_2);
  return hasil;
}

int Permutasi (int n, int r)
{
  // nPr
  int i;
  int hasil = 1;
  int proses_1 = 1;

  for(i = 0; i < n; i++)
  {
    hasil = hasil * (i + 1);
  }

  for(i = 0; i < (n-r); i++)
  {
    proses_1 = proses_1 * (i + 1);
  }

  hasil = hasil / proses_1;
  return hasil;
}

int Deret (int n)
{
  // 1 + 2 + 3 + 4
  int i;
  int hasil = 0;

  for(i = 0; i < n; i++)
  {
    hasil = hasil + (i + 1);
  }
  return hasil;
}

int Deret_Ganjil (int n)
{
  // 1 + 3 + 5 + 7 + 9
  int i;
  int hasil;
  int proses_1 = -1;

  for(i = 0; i < n; i++)
  {
      proses_1 = proses_1 + 2;
      hasil = hasil + proses_1;
  }

  return hasil;
}

int Deret_Genap (int n)
{
  // 2 + 4 + 6 + 8 + 10
  int i;
  int hasil;
  int proses_1 = 0;

  for(i = 0; i < n; i++)
  {
      proses_1 = proses_1 + 2;
      hasil = hasil + proses_1;
  }

  return hasil;
}

int Perpangkatan (int n, int r)
{
  // 2^1, 2^2, 2^3
  int i;
  int hasil = 1;

  for(i = 0; i < n; i++)
  {
      hasil = hasil * r;
  }

  return hasil;
}
