#include <iostream>
#include <vector>
#include <algorithm>

void sequential_sort(std::vector<unsigned int>& X)
{
    unsigned int i, j, count;
    unsigned int N = X.size();

    std::vector<unsigned int> tmp(N);

    for (i = 0; i < N; i++)
    {
        count = 0;
        for (j = 0; j < N; j++)
        {
            if (X[j] < X[i] || (X[j] == X[i] && j < i))
                count++;
        }
        tmp[count] = X[i];
    }

    std::copy(tmp.begin(), tmp.end(), X.begin());
}

int main()
{
    std::vector<unsigned int> X = {5, 3, 8, 3, 1, 9};

    std::cout << "Before sorting:\n";
    for (auto x : X)
        std::cout << x << " ";

    sequential_sort(X);

    std::cout << "\n\nAfter sorting:\n";
    for (auto x : X)
        std::cout << x << " ";

    return 0;
}
