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
int BinRec (int n);

int main()
{
  int pilihan;
  int n;
  int r;

  menu_utama:
  cout << "\033[2J\033[;1H";
  cout << "----- Rekursif -----" << endl << endl;
  cout << "1. Fibonacci" << endl;
  cout << "2. Faktorial" << endl;
  cout << "3. Kombinasi" << endl;
  cout << "4. Permutasi" << endl;
  cout << "5. Deret" << endl;
  cout << "6. Deret Ganjil" << endl;
  cout << "7. Deret Genap" << endl;
  cout << "8. Perpangkatan" << endl;
  cout << "9. BinRec" << endl << endl;
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

      case 9:
        cout << "\033[2J\033[;1H";
        cout << "----- 9. BinRec -----" << endl << endl;
        cout << "Masukkan nilai n : ";
        cin >> n;
        cout << "Hasil = " << BinRec(n);
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
  if(n == 1 || n == 2)
    return 1;
  else
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Faktorial (int n)
{
  // 0! = 1, 1! = 1, 2! = 2 * 1
  if(n == 0 || n == 1)
    return 1;
  else
    return n * Faktorial(n - 1);
}

int Kombinasi (int n, int r)
{
  // nCr
  if (n == 0)
    return 1;
  else
    return Faktorial(n) / (Faktorial(r) * Faktorial(n-r));
}

int Permutasi (int n, int r)
{
  // nPr
  if (n == 0)
    return 1;
  else
    return Faktorial(n) / Faktorial(n-r);
}

int Deret (int n)
{
  // 1 + 2 + 3 + 4
  if (n == 1)
    return 1;
  else
    return n + Deret(n - 1);
}

int Deret_Ganjil (int n)
{
  // 1 + 3 + 5
  if (n == 1)
    return 1;
  else
    return (2 * n) - 1 + Deret_Ganjil(n - 1);
}

int Deret_Genap (int n)
{
  // 2 + 4 + 6
  if (n == 1)
    return 2;
  else
    return (2 * n) + Deret_Genap(n - 1);
}

int Perpangkatan (int n, int r)
{
  // 2^1, 2^2, 2^3
  if (n == 0)
    return 1;
  else
    return (r) * Perpangkatan(n-1,r);
}

int BinRec (int n)
{
  // 1 atau 0
  if (n == 1)
    return 1;
  else
    return BinRec(n / 2) + 1;
}
