#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main()
{
  int sum, *arr, n;
  int i;
  int chunk=5;
  printf("\nEnter the number : ");
  scanf("%d",&n);
  arr = (int*) malloc(sizeof(int)*n);
  for(i=0; i<n;i++)
    arr[i]=2*i;
  #pragma omp parallel for default(shared) private(i) schedule(static)
    for(i=0;i<n;i++)
    {
      sum+=arr[i];
      printf("\nThread %d Array[%d]", omp_get_thread_num(), i);
    }
  printf("\nThe sum is %d", sum);
}
