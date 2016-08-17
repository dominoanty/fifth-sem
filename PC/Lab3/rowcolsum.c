#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void main()
{
  int n, i, j;
  printf("\nEnter the nuumber of rows : ");
  scanf("%d",&n);
  int **mat = (int**)malloc(sizeof(int*)*n);
  int *rowsum = (int*) malloc(sizeof(int)*n);
  int *colsum = (int*) malloc(sizeof(int)*n);
  for(i=0; i<n;i++)
    mat[i] = (int*) malloc(sizeof(int)*n);
  for(i=0; i<n;i++)
    for(j=0; j<n;j++)
      mat[i][j] = i+j;

  for(i=0; i<n;i++)
    for(j=0; j<n;j++)
      printf("\n mat[%d][%d] = %d", i, j, mat[i][j]);
  
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    {
      rowsum[i]+=mat[i][j];
      colsum[j]+=mat[i][j];
    }

  printf("\n Rowsums \n");

  for(i=0; i<n; i++)
    printf(" \n hrowsum[%d] = %d", i, rowsum[i]);

  for(i=0; i<n; i++)
    printf(" \ncolsum[%d] = %d", i, colsum[i]);

}
