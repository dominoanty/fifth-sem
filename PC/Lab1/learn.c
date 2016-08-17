// Lab 1 Privates
#include <stdio.h>
#include <omp.h>

int main()
{
  int i=10;
  printf("\nValue before pragma i=%d\n",i);
  #pragma omp parallel num_threads(4) private(i)
  {
    printf("\nThread %d value before entering : %d",omp_get_thread_num(),i);
    i=i+omp_get_thread_num();
    printf("\nThread %d value after changing : %d", omp_get_thread_num(), i);
  }
  printf("\nThread %d value at end %d", omp_get_thread_num(), i);
}
