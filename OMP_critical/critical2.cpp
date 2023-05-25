#include <omp.h>
#include <stdio.h>

int main() {
    int sum = 0;
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    #pragma omp parallel num_threads(4)
    {
        int local_sum = 0;

        #pragma omp for
        for (int i = 0; i < size; i++) {
            local_sum += arr[i];
        }

        #pragma omp critical
        {
            sum += local_sum;
        }
    }

    printf("Yig'indi : %d\n", sum);

    return 0;
}
// Output :
// Yig'indi : 15