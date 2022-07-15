#include <stdio.h>
#include "includes/libftprintf.h"

int	main()
{
	long int n;
	char *base = "01";
	int base_len = 2;
	int	ret1;
	
	n = 21;
	//n = 154;
	printf("%zd\n", ft_nbrlen_base(n, base_len));
	printf("printf : ");
	ret1 = printf("%ld\n", n);
	printf("%d\n", ret1 - 1);
	ft_printf("ft_printf : ");
	ft_putnbr_base_fd(n, base, 1);
	printf("\n");

	int		nbr;
	// char	*base;

	nbr = -1234678;
	ft_putnbr_base_fd(nbr, "0123456789", 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_base_fd(nbr, "9876543210", 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_base_fd(nbr, "9876543", 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_base_fd(nbr, "01", 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_base_fd(nbr, "0123456789ABCDEF", 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_base_fd(nbr, "poneyvif", 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_base_fd(nbr, "abcdef", 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_base_fd(nbr, "helop", 1);
	ft_putchar_fd('\n', 1);
	return (0);
	//base = "0123456789"
	//base = "01"
	//base = "0123456789ABCDEF"
	//base = "poneyvif"
}