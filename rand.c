#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int upper_bound = 1000;
  int lower_bound = 100;

  for(int i = 0; i < 10; i++) {
    int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;

    printf("%d ", value);
  }
  return 0;
}
