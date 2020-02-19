#include "libmx.h"

bool mx_isalpha(int c) {
    int n = 0;
    if ((c >=65 && c <=90) || (c >=97 && c <=122)) {
        n++;
        return n;
    }
    else {
        return n;
    }
}
