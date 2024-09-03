#include <stdio.h>
#include <stdint.h>
#include <time.h>
int main() {
    clock_t start_time = clock();
    uint64_t n = 0;

  for(uint64_t i = 0; i < 1000000000; i++) {
    n++;
  }
  double elapsed_time = (double) (clock() - start_time) / CLOCKS_PER_SEC;
        printf("Done in %f seconds\n", elapsed_time);
        
  return 0;
}
