#include <omp.h>
#include <vector>
#include <limits>

void minmax_openmp(const std::vector<int>& data, int& min_val, int& max_val) {
    int local_min = std::numeric_limits<int>::max();
    int local_max = std::numeric_limits<int>::min();
    
    #pragma omp parallel reduction(min:local_min) reduction(max:local_max)
    {
        #pragma omp for
        for (size_t i = 0; i < data.size(); i++) {
            if (data[i] < local_min) local_min = data[i];
            if (data[i] > local_max) local_max = data[i];
        }
    }
    
    min_val = local_min;
    max_val = local_max;
}