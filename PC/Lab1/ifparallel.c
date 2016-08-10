#include <omp.h>
#include <stdio.h>
int main()
{
  int val;
  printf("\n Enter 0 for serial, 1 for parallel : "); 
  scanf("%d",&val);
  #pragma omp parallel if(val)
  {
    if(omp_in_parallel())
      printf("Parallel val = %d id =%d \n",val,omp_get_thread_num());
    else
      printf("Serial val = %d id = %d\n", val, omp_get_thread_num());
  }
}
