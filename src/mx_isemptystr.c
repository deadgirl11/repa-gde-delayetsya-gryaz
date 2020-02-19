#include "ush.h"

int mx_isemptystr(char *str, int consider_space) {
	int	i = -1;
	int	min = 32 + consider_space;
	int max = 126;

	while (str[++i]) {
		if (str[i] >= min && str[i] <= max)
			return (0);
	}
	return (1);
}
