#include <omp.h>
#include <stdio.h>

int main() {
    int sum = 0;
    // reduction(operator: list): Paralel bo'limni bajarayotganda, 
    // list o'zgaruvchanlarini belgilangan operator yordamida qisqartirib o'zgartirishga imkon beradi. 
    // Operatorlar, misol uchun +: y, *: sum, -: diff kabi matematikaviy operatorlardan iborat bo'lishi mumkin. 
    // Misol uchun, #pragma omp parallel for reduction(+: sum) ifodasi har bir ish  sum o'zgaruvchasini o'zgartirish imkonini beradi.
    #pragma omp parallel for reduction(+:sum) num_threads(10)
    for (int i = 0; i < 10; ++i) {
        sum += i;
    }

    printf("Yig'indi: %d\n", sum);

    return 0;
}
// Output : 
// Yig'indi: 45