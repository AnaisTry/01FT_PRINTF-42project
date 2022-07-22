/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:31:39 by angassin          #+#    #+#             */
/*   Updated: 2022/07/21 16:29:43 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
	Pads the line with empty spaces or 0 if the flag '0' has been given 
	in the format. 
	If a precision is given the 0 flag is ignored.
*/
void	padding(t_print *print_struct, int nb_len)
{
	char	fill;

	fill = ' ';
	if (print_struct->zero && !print_struct->dot)
		fill = '0';
	while (nb_len < print_struct->width)
	{
		print_struct->len += ft_putchar_fd(fill, 1);
		nb_len++;
	}
}

/*
	Puts additional 0 before the number if the precision is higher 
	than the length of the number.
	The final width comprises the total number of digits printed indicated
	by the precision.
*/
void	number_zero_padding(t_print *print_struct, int nb_len)
{
	if (print_struct->plus && print_struct->zero
		&& print_struct->width > nb_len)
		print_struct->precision = print_struct->width;
	while (nb_len < print_struct->precision)
	{
		print_struct->len += ft_putchar_fd('0', 1);
		if (print_struct->width > 0)
			print_struct->width--;
		nb_len++;
	}
}
