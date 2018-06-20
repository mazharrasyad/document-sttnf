#include <iostream>

using namespace std;

int Faktorial1 (int n)
{
	if(n < 0)
		return (1);
	else if (n > 1)
		return (n*Faktorial1(n-1));
	else
		return (1);
}

int Faktorial2 (int m)
{
	if(m < 0)
		return (1);
	else if (m > 1)
		return (m*Faktorial2(m-2));
	else
		return (1);
}

int main ()
{
	int n,m,hasil;

	cout << "Masukkan Nilai Faktorial = ";
	cin >> n;
	m = n;
	hasil = Faktorial1(n) + Faktorial2(m);
	cout << "Nilai Faktorial " << n << " dan " << m << " = " << hasil << endl;
}
