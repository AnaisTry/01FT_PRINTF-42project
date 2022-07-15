#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int	max(int num_args, ...);
void print(char *placeholders, ...);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

int	main()
{
	int max_num = max(4, 10, 150, 14, 16);
	printf("max_num: %d\n", max_num);
	
	print("ddfd", 4, 2, 10.5, 3);
	print("fdfdf", 1.1, 0, 2.2, 5, 3.2);

	return 0;
}

// output the largest number from the given list of numbers
int max(int num_args, ...)
{
	va_list args;
	va_start(args, num_args);
	int max =0;

	for(int i = 0; i<num_args; i++)
	{
		int x = va_arg(args, int);
		//printf("x: %d\n", x);
		if (i == 0) 
			max = x;
		else if (x > max)
			max = x;
	}
	va_end(args);
	return max;
}

//print an integer or a double according to the placeholder
void print(char *placeholders, ...)
{
	int num_args = strlen(placeholders);

	va_list args;
	va_start(args, placeholders);

	for(int i = 0; i < num_args; i++)
	{
		if(placeholders[i] == 'd')
		{
			int x = va_arg(args, int);
			ft_putnbr_fd(x, 1);
			ft_putchar_fd('\n', 1);
		} 
		else if(placeholders[i] == 'f')
		{
			double dx = va_arg(args, double);
			printf("%f\n", dx);
		}
	}
	va_end(args);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -(unsigned int)n;
	}
	else
	{
		nb = (unsigned int)n;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
	}
	ft_putchar_fd((nb % 10 + '0'), fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}