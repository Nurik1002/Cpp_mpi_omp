#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char* argv[])
{
	
	omp_set_num_threads(4);

	
	#pragma omp parallel
	{
		
		printf("[Jarayon %d] birinchi habar.\n", omp_get_thread_num());

		
		#pragma omp barrier

		
		#pragma omp single
		{
			printf("Barrier o'z ishini tugatdi.\n");
		}

		
		printf("[Jarayon %d] Oxirgi habar.\n", omp_get_thread_num());
	}

	return 0;
}
// Output :
// [Jarayon 0] birinchi habar.
// [Jarayon 3] birinchi habar.
// [Jarayon 2] birinchi habar.
// [Jarayon 1] birinchi habar.
// Barrier o'z ishini tugatdi.
// [Jarayon 3] Oxirgi habar.
// [Jarayon 1] Oxirgi habar.
// [Jarayon 0] Oxirgi habar.
// [Jarayon 2] Oxirgi habar.
