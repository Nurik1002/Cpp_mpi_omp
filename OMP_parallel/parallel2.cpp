#include <omp.h>
#include <stdio.h>

int main() {
    int n = 10;
    int data[n];

    // omp parallel private optsiyasi o'zgaruvchini hususiy qilib oladi va 0 ni ta'minlaydi
    
    #pragma omp parallel private(n) num_threads(n)
    {
        printf("\n = %d", n);
    }
    return 0;
}
// Output : 
// = 32761
//  = 0
//  = 0
//  = 0
//  = 0
//  = 0
//  = 0
//  = 0
//  = 0
//  = 0