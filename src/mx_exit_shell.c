#include "ush.h"

void mx_exit_shell(char **env) {
	mx_del_strarr(&env);
	write(1, "\n", 1);
	exit(0);
}
