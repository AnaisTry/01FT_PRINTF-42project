#include "includes/libftprintf.h"
#include <stdio.h>

int main()
{
	int x = -10;

	printf("%zd\n", ft_nbrlen_base(x, 10));
	return (0);
}