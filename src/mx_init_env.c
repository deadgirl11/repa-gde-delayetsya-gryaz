#include "ush.h"

char **mx_init_envr(int argc, char **argv, char **envr) {
    char **env;
    int i = -1;

    (void)argc;
    (void)argv;
    env = (char **)malloc(sizeof(char *) * (envv_len(envr) +1));
    while(envr[++i]) {
        if (!(env[i] = mx_strdup(envr[i])))
            mx_exit_shell(env);
    }
    return env;
}

char **mx_init_export(char **env) {
    char **export = (char **)malloc(sizeof(char *) * (envv_len(env) +1));
    int i = -1;

    while(env[++i]) {
        if (!(export[i] = mx_strdup(env[i])))
            mx_exit_shell(env);
    }
    mx_quicksort(export, 0, mx_sizearr(export));
    return export;
}