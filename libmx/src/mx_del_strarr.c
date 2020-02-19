#include "libmx.h"

void mx_del_strarr(char ***arr) {
    if (arr && *arr && **arr) {
        while (arr != NULL) {
            mx_strdel(*arr);
        }
    }
}
