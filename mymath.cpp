#include "mymath.h"

int fib(int n) {
    if (n < 2) return n;
    int a;
    int b = 1;
    int c = 1;
    while (n) {
        a = b;
        b = c;
        c = a + b;
        --n;
    }
    return c;
}