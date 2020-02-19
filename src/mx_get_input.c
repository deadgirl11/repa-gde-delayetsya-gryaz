#include "ush.h"

static char **mx_parse_input(char *input) {
    char *replacoperator = mx_replace_substr(input, "&&", ";");
    char **split_str_by_sep = mx_strsplit(replacoperator,';');
    char **without_space = (char **)malloc(sizeof(char *) * 1000);
    int i = 0;
    while (split_str_by_sep[i]){
        without_space[i] = mx_strdup(mx_del_extra_spaces(split_str_by_sep[i]));
        i++;
    }
    without_space[i] = NULL;
    return without_space;
}



char **mx_get_input(char **input, char **env) {
    int ret;
    char b;
    int i = 0;
    char **parse_input;
    int count = 1;

    *input = mx_strnew(1);
    while ((ret = read(0, &b, 1)) && b != '\n') {
        *(*input + i++) = b;
		*input = mx_realloc(*input, count + 1);
		count++;
    }
    *(*input + i) = '\0';
    if (!ret) {
		free(*input);
		mx_exit_shell(env);
	}
    parse_input = mx_parse_input(*input);
    return parse_input;
}
