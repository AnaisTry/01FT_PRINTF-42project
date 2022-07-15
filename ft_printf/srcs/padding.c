/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:31:39 by angassin          #+#    #+#             */
/*   Updated: 2022/07/15 16:35:26 by angassin         ###   ########.fr       */
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
	If the prefix is added in front of an hexadecimal, the padding is reduced
	by 2.
*/
void	number_zero_padding(t_print *print_struct, int nb_len)
{
	while (nb_len < print_struct->precision)
	{
		print_struct->len += ft_putchar_fd('0', 1);
		if (print_struct->width > 0)
			print_struct->width--;
		nb_len++;
	}
}

/*
	If a precision is given with a numeric conversion (d, i, o, u, x, and X),
	the 0 flag is ignored.
	If the prefix is added in front of an hexadecimal, the padding is reduced
	by 2.
	An optional decimal digit string stored in the width variable specifies 
	a minimum field width.  
	If the converted value has fewer characters than the field width, it will 
	be padded with spaces on the left (or right, if the '-' left-adjustment 
	flag has been given) to fill out the field width.
	With the zero flag '0' the converted value is padded on the left with zeros 
	rather than blanks.
	In case of both a width and a precision is given, if the precision is higher 
	than the length of the number, then the total width will include the extra
	zeros padded before the number.
*/
void	unbr_left_padding(t_print *ps, int nb_len)
{
	if (ps->dot && ps->zero)
		ps->zero = 0;
	if ((ps->width && !ps->minus && !ps->zero)
		|| (ps->width && ps->dot && (ps->precision == 0)))
	{
		if (ps->dot && ps->precision > nb_len)
		{
			if (ps->hash)
				ps->width -= ps->precision - nb_len + 2;
			else
				ps->width -= ps->precision - nb_len;
		}
		padding(ps, nb_len);
	}
}
