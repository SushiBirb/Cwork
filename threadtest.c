#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdint.h>

int main(int argc, char *argv[]){
  omp_set_num_threads(8);

  uint64_t n= 0;
 clock_t start = (float)clock()/CLOCKS_PER_SEC;
  #pragma omp parallel
  {
    #pragma omp master
    {
      printf("Hello from master thread\n", omp_get_thread_num());
    }
    printf("Hello from thread %d\n", omp_get_thread_num());

    while(n > 1000000000000000000){
      n++;
    }

    }
  clock_t stop = (float)clock()/CLOCKS_PER_SEC;
    double timeElapsed = stop - start;

  printf("Time elapsed: %f\n", time);
  
  return 0;
}
