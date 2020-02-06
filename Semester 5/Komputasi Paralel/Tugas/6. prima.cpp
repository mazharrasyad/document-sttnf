#include <iostream>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <stdio.h>

using namespace std;

string isPrime(int n)
{
    if (n < 2){
        return "Bukan";
    }
    else if (n == 2 or n == 3){
        return "Prima";
    }
    else{
        string prima = "Prima";
        for (int i = 2; i <= n / 2; ++i){
            if(n % i == 0){
                prima = "Bukan";
                break;
            }
        }
        return prima;
    }
}

void PrimeLessInc(int x){
    #pragma omp parallel for
    {
        for (int i = 2; i <= x; i++){
            cout << "i = " << i << ", Status = " << isPrime(i) << endl;
        }
    }
}


int main()
{
    clock_t mulai = clock();
    PrimeLessInc(10);
    cout << "\nWaktu Eksekusi Program : " << double(clock() - mulai) / CLOCKS_PER_SEC << " Detik" << endl;
}


