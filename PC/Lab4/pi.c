#include <stdio.h>
#include <time.h>
#include <omp.h>
int main(void)
{
  double pi,x;
  clock_t begin,end;
  int i,N;
  pi=0.0;
  N=1000;
  begin = clock();
  #pragma omp parallel for private(x,i) reduction(+:pi)
    for(i=0;i<N;i++)
    {
      x=(double)i/N;
      pi+=4/(1+x*x);
    }
  end = clock();
  printf("\n Time spent : %f ", (double)(end-begin)/CLOCKS_PER_SEC);
  pi=pi/N;
  printf("Pi is %f\n",pi);
}
