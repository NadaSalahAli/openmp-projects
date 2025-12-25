#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    const int N = 10000000;
    double sum = 0.0;

    
    double* arr = new double[N];
    for (int i = 0; i < N; i++) {
        arr[i] = 1.0;
    }

    double start = omp_get_wtime();


    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    double end = omp_get_wtime();

    cout << "Sum = " << sum << endl;
    cout << "Time = " << end - start << " seconds" << endl;

    delete[] arr;
    return 0;
}
