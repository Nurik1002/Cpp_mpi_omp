#include <omp.h>
#include <stdio.h>

int main()
{
#pragma omp parallel for schedule(static,1) 	
    for (int i = 0; i < 20; i++)
	{
		printf("Jarayon %d i : %d\n", omp_get_thread_num(), i);
	}
	return 0;
}

// Output :
// Jarayon 0 i : 0
// Jarayon 0 i : 8
// Jarayon 0 i : 16
// Jarayon 7 i : 7
// Jarayon 7 i : 15
// Jarayon 6 i : 6
// Jarayon 6 i : 14
// Jarayon 4 i : 4
// Jarayon 4 i : 12
// Jarayon 3 i : 3
// Jarayon 3 i : 11
// Jarayon 3 i : 19
// Jarayon 1 i : 1
// Jarayon 1 i : 9
// Jarayon 1 i : 17
// Jarayon 5 i : 5
// Jarayon 5 i : 13
// Jarayon 2 i : 2
// Jarayon 2 i : 10
// Jarayon 2 i : 18