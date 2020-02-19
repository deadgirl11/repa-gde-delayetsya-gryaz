#include "libmx.h"

int	mx_strequ(char const *s1, char const *s2) {
	if (!s1 || !s2)
		return (0);
	return (mx_strcmp(s1, s2) ? 0 : 1);
}
