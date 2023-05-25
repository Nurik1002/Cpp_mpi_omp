#include <omp.h>
#include <stdio.h>

int main() {
    int sum = 0;
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    #pragma omp parallel for num_threads(4) reduction(+:sum)
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("Massiv yig'indisi : %d\n", sum);

    return 0;
}
// Output : 
// Massiv yig'indisi : 15