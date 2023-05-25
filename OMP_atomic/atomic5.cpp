#include <omp.h>
#include <stdio.h>

int main() {
    float result = 0.0f;
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        float partial = i * 1.5f;
        #pragma omp atomic
        result += partial;
    }
    printf("result : %.2f\n", result);
return 0;
}
// Output : 
//result : 67.50