/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:10:55 by angassin          #+#    #+#             */
/*   Updated: 2022/05/02 18:12:44 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	memsize_str(long n);

/*
	Allocates (with malloc(3)) and returns a string
	representing the integer received as an argument.
	Returns NULL if allocation fails.
	Negative numbers must be handled.
*/
char	*ft_itoa(int n)
{
	char	*a;
	long	nb;
	int		len;
	int		i;

	nb = (long)n;
	len = memsize_str(nb);
	a = ft_calloc((len + 1), sizeof(*a));
	if (!a)
		return (NULL);
	if (nb == 0)
		a[0] = '0';
	if (nb < 0)
	{
		a[0] = '-';
		nb = -nb;
	}
	i = len - 1;
	while (nb)
	{
		a[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (a);
}

// returns the length of space needed by the string before the terminating \0
static int	memsize_str(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
