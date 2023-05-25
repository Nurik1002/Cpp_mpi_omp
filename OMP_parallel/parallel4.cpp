#include <omp.h>
#include <stdio.h>

int main() {
    int son = 123;
    // shared optsiyasida o'zgaruvchi qiymati o'zgarmaydi ya'ni umumiy qiladi
    #pragma omp parallel shared(son)
    {
        printf("\nson = %d", son);
    }

    return 0;
}
// Output : 
// son = 123
// son = 123
// son = 123
// son = 123
// son = 123
// son = 123
// son = 123
// son = 123