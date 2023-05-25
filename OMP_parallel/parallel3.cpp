#include <omp.h>
#include <stdio.h>

int main() {
    int n = 10;
    
// if optsiyasi agar shart to'g'ri bo'lsa barcha jarayon ishlaydi
// Aks holda 1 ta jarayon ishlaydi
 #pragma omp parallel if(n > 100)
    {
        printf("\njarayon id : %d", omp_get_thread_num());
    }

    return 0;
}
// Output : 
// jarayon id : 0