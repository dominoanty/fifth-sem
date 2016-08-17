#include <omp.h>
#include <stdio.h>

void main()
{
  int j, k, a;

  printf("\nWith collapse : ");
  #pragma omp parallel num_threads(2)
  {
    #pragma omp for collapse(2) ordered private(j,k) schedule(static,3)
      for (k=1; k<=3; k++)
        for (j=1; j<=2; j++)
        {
          #pragma omp ordered
            printf("Thread : %d k = %d ; j = %d \n", omp_get_thread_num(), k, j);
          /* end ordered */
        }
  }
  printf("\nWithout collapse : ");
  #pragma omp parallel num_threads(2)
  {
    #pragma omp for ordered private(j,k) schedule(static,3)
      for (k=1; k<=3; k++)
        for (j=1; j<=2; j++)
        {
          #pragma omp ordered
            printf("Thread : %d k = %d ; j = %d \n", omp_get_thread_num(), k, j);
          /* end ordered */
        }
  }
}
