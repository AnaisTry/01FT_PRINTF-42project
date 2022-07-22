/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:27:03 by angassin          #+#    #+#             */
/*   Updated: 2022/07/21 10:36:48 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
