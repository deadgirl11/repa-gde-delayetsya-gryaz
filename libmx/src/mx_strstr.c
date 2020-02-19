#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    char *begin = (char*) haystack;

    if (*needle == '\0')
        return (begin);
    
    while (*haystack != '\0') {
        begin = (char*) haystack;

        while (*needle == *haystack && *haystack != '\0') {
            ++haystack;
            ++needle;
        }
        if (*needle == '\0')
            return (begin);
        haystack = begin + 1;
    }
    return NULL;
}

// int main() {
//     char s[] = "123456789abcdefg"; 
//     printf("Искомая строка начинается с символа %s\n", mx_strstr(s, "2"));
//     printf("Искомая строка начинается с символа %s\n", mx_strstr(s, "g"));
//     printf("Искомая строка начинается с символа %s\n", mx_strstr(s, ""));
//     printf("Искомая строка начинается с символа %s\n", mx_strstr(s, "sdfsdfsdfsdf"));
//     return 0;
// }
