// Lab 1, Number of Threads
#include <stdio.h>
#include <omp.h>

int main()
{
  #pragma omp parallel num_threads(4)
  {
    int i=omp_get_thread_num();
    printf("\nHello world from thread %d\n", i);
  }
}
