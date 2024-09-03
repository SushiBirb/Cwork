#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <malloc.h>

int main() {


    uint64_t n;
    uint64_t a = 0;
    uint64_t b = 1;
    uint64_t c = 0;
    uint64_t i;

    printf("Enter num\n");
    scanf("%lld", &n);

    if (n == 0)
        return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    clock_t start_time = clock();
    printf("%llu\n", b);
    double elapsed_time = (double) (clock() - start_time) / CLOCKS_PER_SEC;
    printf("Done in %f seconds\n", elapsed_time);
    return 0;
}