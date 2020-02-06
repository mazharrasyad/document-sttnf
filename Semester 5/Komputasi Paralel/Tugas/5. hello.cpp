#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
    clock_t mulai = clock();
    int x = 0;

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int thread = omp_get_num_threads();
        x += 5;
        printf("Hello from thread %d, nthread = %d : x is %d\n", id, thread, x);
    }

    cout << "\nWaktu Eksekusi Program : " << double(clock() - mulai) / CLOCKS_PER_SEC << " Detik" << endl;
}