#include "ush.h"


static int run_cmd(char *path, char **args, char **env) {
	pid_t pid;

	pid = fork();
	signal(SIGINT, signal_handler);
	if (pid == 0)
		execve(path, args, env);
	else if (pid < 0) {
		free(path);
        mx_errors(FORK_FAIL, "crash (");
		return (-1);
	}
	wait(&pid);
	// if (path)
	// 	free(path);
	return (1);
}

static int is_executable(char *bin_path, struct stat f, char **command, char **env) {
	if (f.st_mode & S_IFREG) {
		if (f.st_mode & S_IXUSR)
			return (run_cmd(bin_path, command, env));
		else 
            mx_errors(USH_PERMISION, bin_path);
		// free(bin_path);
		return 1;
	}
	// free(bin_path);
	return 0;
}

static int check_builtins(char **command, char **env) {
	if (mx_strequ(command[0], "exit"))
		return (-1);
	// else if (mx_strequ(command[0], "echo"))
	// 	return (mx_echo_builtin(command + 1, env));
	else if (mx_strequ(command[0], "cd"))
		return (mx_cd_builtin(command + 1, env));
	else if (mx_strequ(command[0], "export"))
		return (mx_export_builtin(command + 1, env));
	else if (mx_strequ(command[0], "unset"))
		return (mx_unsetenv_builtin(command + 1, env));
    else if (mx_strequ(command[0], "which"))
        return (mx_which_builtin(command + 1, env));
    else if (mx_strequ(command[0], "pwd"))
        return (mx_pwd_builtin(command + 1, env));
    else if (mx_strequ(command[0], "env")) {
		return (mx_env_builtin(command + 1, env));
    }
	return 0;
}

static int check_bins(char **commands, char **env) {
    int	i = -1;
	char *bin_path;
	char **path = mx_strsplit(mx_get_env_var("PATH", env), ':');
	struct stat	f;

    while (path && path[++i]) {
        if (mx_get_substr_index(commands[0], path[i]) == 0)
            bin_path = mx_strdup(commands[0]);
        else 
            bin_path = mx_pathjoin(path[i], commands[0]);
        if (lstat(bin_path, &f) == -1)
			free(bin_path);
		else {
			free(path);
			return (is_executable(bin_path, f, commands, env));
		}
	}
	// free(path);
	return 0;
}

int mx_run_command(char **commands, char **env, int run_mode) {
    struct stat f;
    int is_builtin;

    if (run_mode)
        if (check_bins(commands, env) ||
            (is_builtin = check_builtins(commands, env)) == 1)
                return 0;
    if (!run_mode)
        if ((is_builtin = check_builtins(commands, env)) == 1 ||
            check_bins(commands, env) )
                return 0;
    if (is_builtin < 0)
        return -1;
    // if (lstat(commands[0], &f) != -1) {
    //     if (f.st_mode & S_IFDIR) {
    //         mx_change_dir(commands[0], 0, env);
    //         return 0;
    //     } else if (f.st_mode & S_IXUSR)
    //         return (run_cmd(mx_strdup(commands[0]), commands, env));
    // }
    mx_errors(USH_NF, commands[0]);
    return 0;
}
