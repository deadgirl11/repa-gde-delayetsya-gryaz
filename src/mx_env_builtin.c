#include "ush.h"


static int p_env_arg(char **arg, char **env) {
    if (!arg[0])
        mx_errors(ENV_OPTION_REQ, arg[0]);
    else {
        if (!arg[1])
            mx_print_env(env);
        else {
            mx_remove_env_var(arg[1], env);
            return mx_run_command(arg + 1, env, 1);
        }
    }
    return 1;
}

static int u_env_arg(char **arg, char **env) {
    if (!arg[0])
        mx_errors(ENV_OPTION_REQ, arg[0]);
    else {
        mx_remove_env_var(arg[1], env);
        if (!arg[1]) 
            mx_print_env(env);
        else 
            return mx_run_command(arg + 1, env, 1);
    }
    return 1;
}

int mx_env_builtin(char **arg, char **env) {
    char **new_env = mx_init_export(env);

    if (!arg[0]) {
        mx_print_env(env);
        return 1;
    } 
    if (mx_strequ(arg[0], "-P"))
        return p_env_arg(arg + 1, new_env);
    else if (mx_strequ(arg[0], "-u"))
        return u_env_arg(arg + 1, new_env);
    else {
        if (mx_strequ(arg[0], "-i") && !arg[1])
            return 1;
        else if (mx_strequ(arg[0], "-i"))
            return mx_run_command(arg + 1, NULL, 1);
        else
            mx_errors(ENV_ILL,arg[0]);
    }
    return 1;
}