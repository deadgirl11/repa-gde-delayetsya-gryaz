#include "libmx.h"

bool mx_isspace(char c) {
    int n = 0;
    switch(c) {
        case ' ':
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
            n++;
    }
    return n;
}
