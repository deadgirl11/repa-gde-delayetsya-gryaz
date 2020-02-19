#include "ush.h"

static int mx_strendswith(char *s1, char *s2) {
	int	i;

	i = -1;
	while (s1[++i])
		if (s1[i] == s2[0])
			if (mx_strcmp(s1 + i, s2) == 0)
				return (1);
	return (0);
}

char *mx_pathjoin(char *p1, char *p2) {
	char *tmp2;

	if (!p2 || !p1)
		return (NULL);
	if (!mx_strendswith(p1, "/")) {
		if (p2[0] == '/')
			return (mx_strjoin(p1, p2));
		else {
			tmp2 = mx_strjoin(mx_strjoin(p1, "/"), p2);
			return (tmp2);
		}
	}
	else {
		if (p2[0] == '/')
			return (mx_strjoin(p1, p2 + 1));
		else
			return (mx_strjoin(p1, p2));
	}
}
