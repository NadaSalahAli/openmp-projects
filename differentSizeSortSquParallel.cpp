#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>
#include <cstdlib>

void sequential_sort(std::vector<unsigned int>& X)
{
    unsigned int N = X.size();
    std::vector<unsigned int> tmp(N);

    for (unsigned int i = 0; i < N; i++)
    {
        unsigned int count = 0;
        for (unsigned int j = 0; j < N; j++)
        {
            if (X[j] < X[i] || (X[j] == X[i] && j < i))
                count++;
        }
        tmp[count] = X[i];
    }

    std::copy(tmp.begin(), tmp.end(), X.begin());
}

void parallel_sort(std::vector<unsigned int>& X)
{
    unsigned int N = X.size();
    std::vector<unsigned int> tmp(N);

    #pragma omp parallel for
    for (int i = 0; i < (int)N; i++)
    {
        unsigned int count = 0;
        for (unsigned int j = 0; j < N; j++)
        {
            if (X[j] < X[i] || (X[j] == X[i] && j < (unsigned int)i))
                count++;
        }
        tmp[count] = X[i];
    }

    std::copy(tmp.begin(), tmp.end(), X.begin());
}

int main()
{
    srand(0);

    std::cout << "N\tSequential(s)\tParallel(s)\n";

    for (int N : {1000, 5000, 10000, 20000})
    {
        std::vector<unsigned int> X(N);
        for (int i = 0; i < N; i++)
            X[i] = rand() % 100000;

        std::vector<unsigned int> X_copy = X;

        double start = omp_get_wtime();
        sequential_sort(X);
        double seq_time = omp_get_wtime() - start;

        start = omp_get_wtime();
        parallel_sort(X_copy);
        double par_time = omp_get_wtime() - start;

        std::cout << N << "\t" << seq_time << "\t\t" << par_time << "\n";
    }

    return 0;
}
