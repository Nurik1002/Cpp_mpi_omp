
#include <omp.h>
#include <stdio.h>

int main() {
    int number = 10;
    #pragma omp parallel for
    for (int i = 0; i < 5; ++i) {
        #pragma omp atomic
        number--;
    }
    printf("Ayirma : %d\n", number);
    return 0;
}
// Output :
// Ayirma : 5