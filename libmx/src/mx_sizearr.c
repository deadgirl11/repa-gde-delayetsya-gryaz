#include "libmx.h"

int mx_sizearr(char **arr) {
    int count = -1;

    while (*arr != NULL) {
        arr++;
        count++;
    }
    return count;
}
