#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
void main(int argc, char* argv[])
{
  if(argc != 2)
  {
    printf("\nUsage : smallest <initial_number_of_elements> \n");
    exit(1);
  }
  int NO_ELEMENTS = atoi(argv[1]);
  int *var = (int*) malloc(sizeof(int) * NO_ELEMENTS);
  srand(time(NULL));
  int i=0;
  int smallest=10000;
  time_t begin,end;
  for(i=0; i<NO_ELEMENTS;i++)
  {
    var[i] = rand()%NO_ELEMENTS +1 ;
  }
  begin = clock();
  #pragma omp parallel for  num_threads(20) schedule(static,5) private(i) reduction(min:smallest)
  for(i=0; i<NO_ELEMENTS;i++)
  {
    if(var[i] < smallest)
      smallest = var[i];
   // printf("\n from thread %d : %d ", omp_get_thread_num(), var[i] );
  }
  end = clock();
  printf("\nThe time taken is %f", (double)(end-begin)/CLOCKS_PER_SEC);
  printf("\nThe smallest is %d", smallest);
}
