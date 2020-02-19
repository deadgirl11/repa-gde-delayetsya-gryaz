#include "ush.h"

void mx_errors(enum m_eror errors, char *a) {
    if (errors == UNSET_ERR) {
        mx_printerr("unset: not enough arguments\n");
    } else if (errors == USH_NF) {
        mx_printerr("ush: command not found: ");
        mx_printerr(a);
        mx_printerr("\n");
    } else if (errors == FORK_FAIL) {
        mx_printerr("Fork failed to create a new process.\n");
    } else if (errors == USH_BAD_ASSIGN) {
        mx_printerr("ush: bad assignment\n");
    } else if (errors == CD_NSFORD) {
        mx_printerr("cd: no such file or directory:");
        mx_printerr(a);
        mx_printerr("\n");
    } else if (errors == CD_PERMISION) {
        mx_printerr("cd: permission denied: ");
        mx_printerr(a);
        mx_printerr("\n");
    } else if (errors == CD_NON_DIR) {
        mx_printerr("cd: not a directory: ");
        mx_printerr(a);
        mx_printerr("\n");
    } else if (errors == CD_STR_NOT_PWD) {
        mx_printerr("cd: string not in pwd: ");
		mx_printerr(a);
        mx_printerr("\n");
    } else if (errors == CD_TO_MANY) {
        mx_printerr("cd: too many arguments\n");
    } else if (errors == USH_PERMISION) {
        mx_printerr("ush: permission denied: ");
		mx_printerr(a);
        mx_printerr("\n");
    } else if (errors == ENV_ILL) {
        mx_printerr("env: illegal option -");
		mx_printerr(a);
        mx_printerr("\n");
        mx_printerr("usage: env [-i] [-P utilpath] [-u name]\n");
        mx_printerr("           [name=value ...] [utility [argument ...]]\n");
    } else if (errors == ENV_OPTION_REQ) {
        mx_printerr("env: option requires an argument -");
        mx_printerr(a);
        mx_printerr("\n");
        mx_printerr("usage: env [-i] [-P utilpath] [-u name]\n");
        mx_printerr("           [name=value ...] [utility [argument ...]]\n");
    }
    
    
}
