#include "ush.h"

char *mx_parse_home_path(char *path, int reverse, char **env) {
    char *new;
    char *home_path = mx_get_env_var("HOME", env);

    if(!path)
        return NULL;
    if (strcmp(home_path, path) == 0)
        return mx_strdup(home_path);
    new = mx_replace_substr(path,home_path, "~");
    return new;
}
