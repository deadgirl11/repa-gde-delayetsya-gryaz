#include "ush.h"

int mx_pwd_builtin(char **arg, char **env) {
    char *cwd;
    char buff[4096 + 1];

    if (!arg[0] || mx_strequ(arg[0], "-L")) {
        mx_printstr(mx_get_env_var("PWD", env));
        mx_printstr("\n");
        return 1;
    } else {
        cwd = getcwd(buff, 4096);
        mx_printstr(cwd);
        mx_printstr("\n");
        return 1;
    }
}

int mx_which_builtin(char **arg, char **env) {
    int	i = -1;
    int q = -1;
	char *bin_path;
	char **path = mx_strsplit(mx_get_env_var("PATH", env), ':');
	struct stat	f;

    // while (arg[++q]) {
    while (path && path[++i]) {
        if (mx_get_substr_index(arg[i], path[i]) == 0)
            bin_path = mx_strdup(arg[i]);
        else 
            bin_path = mx_pathjoin(path[i], arg[i]);
        mx_printstr(bin_path);
        mx_printstr("\n");
    }
    // }
	// free(path);
	return 0;
}
