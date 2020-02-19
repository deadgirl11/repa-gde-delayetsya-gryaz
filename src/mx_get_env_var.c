#include "ush.h"

char **realloc_envv(int new_size, char **env) {
    int i = -1;
	char **new;
    new = (char **)malloc(sizeof(char *) * (new_size + 1));;

	while (env[++i] && i < new_size) {
		new[i] = mx_strdup(env[i]);
		mx_strdel(&env[i]);
	}
	free(env);
	return new;
}

int envv_len(char **envv) {
	int	i = -1;
	int	count = 0;
    
	while (envv[++i])
		count++;
	return (count);
}

char *mx_get_env_var(char *var, char **env) {
    char *tmp;
    int i = -1;
    
    if(!env)
        return NULL;
    while (env[++i]) {
        tmp = mx_strjoin(var, "=");
        if ((mx_get_substr_index(env[i], tmp)) == 0) {
            free(tmp);
            return (mx_strchr(env[i], '=') + 1);
        }
        free(tmp);
    }
    return NULL;
}
