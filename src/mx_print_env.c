#include "ush.h"

void mx_print_env(char **env) {
    int i = 0;
    while (env[i]) {
        mx_printstr(env[i++]);
        mx_printstr("\n");
    }
}
