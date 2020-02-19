#include"libmx.h"
static int mx_strncmp(const char *s1, const char *s2, int n) {
    while (n--) {
        if (*s1 != *s2)
            return *s1 - *s2;
        ++s1;
        ++s2;
    }
    return 0;
}

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) return NULL;
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    int sun_num = mx_count_substr(str, sub);
    char *newstr = mx_strnew(mx_strlen(str) - sub_len * sun_num + replace_len * sun_num);
    char *to = newstr;
    while (*str) {
        if (mx_strncmp(str, sub, sub_len) == 0) {
            mx_strcat(newstr, replace);
            to += replace_len;
            str += sub_len;
        }
        else {
            *to = *str;
            to++;
            str++;
        }
    }
    return newstr;
}

