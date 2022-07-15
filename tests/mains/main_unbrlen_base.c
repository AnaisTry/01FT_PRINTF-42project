#include "includes/libftprintf.h"
#include <stdio.h>

int main()
{
	unsigned int x = -10;

	printf("%zu\n", ft_unbrlen_base(x, 10));
	printf("%zu\n", ft_unbrlen_base(x, 10));
	return (0);
}