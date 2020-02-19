#include "ush.h"

void signal_handler(int signo) {
	if (signo == SIGINT) {
		mx_printstr("\n");
		signal(SIGINT, signal_handler);
	} else if (signo == EOF) {
        mx_printstr("\n");
		signal(EOF, signal_handler);
    } else if (signo == SIGTSTP) {
        signal(SIGTSTP, signal_handler);
    }
}

static int exec_commands(char **commands, char **env) {
    int i = -1;
    int exit = 0;
    char **command;

    while (commands[++i]) {
        command = mx_strsplit(commands[i], ' ');
        exit = mx_run_command(command, env, 0);
        //free(&command);
        if (exit == 1)
            break;
    }
    return exit;
}

static void circle_main(char **env) {
    char *input;
    char **alias;
    char **commands;
    int ret;

     while (1) {
        signal(SIGINT, signal_handler);
        mx_display(env);
        commands = mx_get_input(&input, env);
        if (mx_isemptystr(input, 1)) {
            free(input);
            continue;
        }
        //free(input);
        ret = exec_commands(commands, env);
        // free(&commands);
        if (ret == -1) 
            break;
	}
}

int main(int argc, char **argv, char **envr) {
    char **env;

    env = mx_init_envr(argc, argv, envr);
    circle_main(env);
    // free(&env);
    exit(1);
}
