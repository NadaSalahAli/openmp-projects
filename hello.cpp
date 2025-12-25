#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        std::cout << "Hello from thread " << thread_id 
                  << " out of " << num_threads << std::endl;
    }
    return 0;
}
