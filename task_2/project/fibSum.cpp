#include "fibSum.h"


unsigned fibSum(unsigned n) {
    if (n < 2) return 0;
    if (n == 2) return 1;

    return 1 + fibSum(n-1) + fibSum(n-2);
}