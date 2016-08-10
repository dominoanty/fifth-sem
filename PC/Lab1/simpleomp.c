// Lab 1, Simple OMP
#include <stdio.h>
#include <omp.h>
int main()
{
  int nthreads, tid;
  #pragma omp parallel private(tid)
  {
    tid=omp_get_thread_num();
    printf("\nHello World from thread= %d", tid);
    if(!tid)
    {
      nthreads = omp_get_num_threads();
      printf("\nNumber of threads = %d\n", nthreads);
    }
  }
}
