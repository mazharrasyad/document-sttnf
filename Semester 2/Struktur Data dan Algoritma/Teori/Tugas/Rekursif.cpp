#include <iostream>

using namespace std;

int Nilai_n(int *n);
int Nilai_m(int *m);
int Fibonacci (int n);
int Faktorial (int n);
int Kombinasi (int n, int r);
int Permutasi (int n, int r);
int Perpangkatan (int n, int x);
int Deret (int n);
int Deret_Genap (int n);
int Deret_Ganjil (int n);
int BinRec(int n);

int main()
{
  int p,n,r,x;

	cout << "<----- Algoritma Rekursif ----->" << endl << endl;
	cout << "1. Fibonacci" << endl;
	cout << "2. Kombinasi" << endl;
	cout << "3. Permutasi" << endl;
	cout << "4. Perpangkatan" << endl;
	cout << "5. Deret 1 + 2 + 3 + ... + n" << endl;
  cout << "6. Deret Genap 2 + 4 + 6 + ... + n" << endl;
  cout << "7. Deret Ganjil 1 + 3 + 5 + ... + n" << endl;
  cout << "8. BinRec" << endl;
	cout << "\nMasukkan Pilihan Rekursif = ";
	cin >> p;

	switch(p)
	{
		case 1:
			Nilai_n(&n);
      cout << "\nHasil = " << Fibonacci(n) << endl;
			break;

		case 2:
			Nilai_n(&n);
      cout << "\nMasukkan Nilai r = ";
      cin >> r;
      cout << "\nHasil = " << Kombinasi(n,r) << endl;
			break;

		case 3:
			Nilai_n(&n);
      cout << "\nMasukkan Nilai r = ";
      cin >> r;
      cout << "\nHasil = " << Permutasi(n,r) << endl;
			break;

		case 4:
      cout << "\nMasukkan Nilai x = ";
      cin >> x;
			Nilai_n(&n);
      cout << "\nHasil = " << Perpangkatan(n, x) << endl;
			break;

		case 5:
			Nilai_n(&n);
      cout << "\nHasil = " << Deret(n) << endl;
			break;

    case 6:
      Nilai_n(&n);
      cout << "\nHasil = " << Deret_Genap(n) << endl;
      break;

    case 7:
			Nilai_n(&n);
      cout << "\nHasil = " << Deret_Ganjil(n) << endl;
			break;

    case 8:
			Nilai_n(&n);
      cout << "\nHasil = " << BinRec(n) << endl;
			break;

		default:
			cout << "\nError Pilihan Tidak Ada" << endl;
	}
}

int Nilai_n(int *n)
{
  cout << "\nMasukkan Nilai n = ";
  cin >> *n;
}

int Fibonacci(int n)
{
  if (n == 1 || n == 2)
    return 1;
	else
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int Faktorial (int n)
{
  if (n == 0 || n == 1)
    return 1;
  else
    return n * Faktorial(n-1);
}

int Kombinasi(int n, int r)
{
  if (n < r)
		return 0;
	else
		return Faktorial(n) / (Faktorial(r) * Faktorial(n-r));
}

int Permutasi(int n, int r)
{
  if (n < r)
		return 0;
	else
		return Faktorial(n) / Faktorial(n-r);
}

int Perpangkatan(int n, int x)
{
  if (n == 0)
		return 1;
	else
		return x * Perpangkatan(n-1, x);
}

int Deret(int n)
{
  if (n == 1)
		return 1;
	else
		return n + Deret(n-1);
}

int Deret_Genap(int n)
{
  if (n == 1)
		return 2;
	else
		return (2 * n) + Deret_Genap(n-1);
}

int Deret_Ganjil(int n)
{
  if (n == 1)
		return 1;
	else
		return (2 * n)-1 + Deret_Ganjil(n-1);
}

int BinRec(int n)
{
  if (n == 1)
		return 1;
	else
		return BinRec(n / 2)+1;
}
