#include "ush.h"

int mx_echo_builtin(char **arg, char **env) {
    if (!arg[0]) {
		write(1, "\n", 1);
		return (1);
	}
    return 1;
}
