#ifndef LIBMX_H
#define LIBMX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

int mx_count_char(char *str, char c);
int mx_strcmp(const char *s1, const char *s2);
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
void mx_quicksort(char **arr, int left, int right);
int mx_factorial_iter(int n);
void mx_foreach(int *arr, int size, void (*f)(int));
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_nbr_to_hex(unsigned long nbr);
double mx_pow(double n, unsigned int pow);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_sort_arr_int(int *arr, int size);
void mx_print_unicode(wchar_t c);
int mx_sqrt(int x);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, const char delim);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
void mx_del_strarr(char ***arr);
char *mx_file_to_str(const char *file);
int mx_get_char_index(const char *str, char c);
int mx_get_substr_index(const char *str, const char *sub);
char *mx_itoa(int number);
void *mx_memccpy(void *dst, const void *src, int c, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memcpy(void *dst, const void *src, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *to, const void *from, size_t numBytes);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memset(void *b, int c, size_t len);
void *mx_realloc(void *ptr, size_t size);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
char *mx_strcpy(char *dst, const char *src);
void mx_strdel(char **str);
char *mx_strndup(const char *s1, size_t n);
char *mx_strdup(const char *str);
int mx_strlen(const char *c);
int mx_sizearr(char **arr);
char *mx_strnew(const int size);
void mx_str_reverse(char *s);
char *mx_strcat(char *s1, const char *s2);
void mx_strdel(char **str);
char *mx_strjoin(const char *s1, const char *s2);
char **mx_strsplit(const char *s, char c);
char *mx_strstr(const char *haystack, const char *needle);
void mx_swap_char(char *s1, char *s2);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_printerr(const char *s);
int mx_atoi(const char *str);
bool mx_isspace(char c);
bool mx_isdigit(int c);
bool mx_isalpha(int c);
int	mx_strequ(char const *s1, char const *s2);
char *mx_strchr(const char *s, int c);
int mx_read_line(char **line, int buf_size, char delim, const int fd);

#endif
