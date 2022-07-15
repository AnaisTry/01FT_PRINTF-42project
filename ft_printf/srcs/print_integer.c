/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:48:53 by angassin          #+#    #+#             */
/*   Updated: 2022/07/12 20:47:45 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	integer_left_padding(t_print *ps, int nb, int nb_len);
static void	print_integer(t_print *ps, int nb, int nb_len);

// %d or %i
/*
	Prints the decimal number at the spot of the placeholder %d.
	With the '+' flag a sign must be placed before the number.
	With the space flag a blank should be left before a positive number.
	A '+' overrides a space if both are used.
	For the optional precision, in the form of a dot '.' followed by an optional 
	digit string stored in the variable precision:
	The precision indicates the minimum number of digits to be printed.
	If the precision is bigger than the number, the number will be filled 
	with zeros in front.
*/
void	spec_d(t_print *ps)
{
	int				nb;
	int				nb_len;

	nb = va_arg(ps->args, int);
	if (nb >= 0 && ps->plus)
		ps->len += ft_putchar_fd('+', 1);
	if (nb >= 0 && ps->space && !ps->plus)
		ps->len += ft_putchar_fd(' ', 1);
	if (nb == 0 && ps->dot && ps->precision == 0)
		nb_len = 0;
	else
		nb_len = ft_nbrlen_base(nb, DECIMAL_LEN);
	integer_left_padding(ps, nb, nb_len);
	print_integer(ps, nb, nb_len);
	ps->len += nb_len;
}

void	spec_i(t_print *ps)
{
	spec_d(ps);
}

/*
	If a precision is given the '0' flag is ignored.
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
static void	integer_left_padding(t_print *ps, int nb, int nb_len)
{
	if (ps->dot && ps->zero)
		ps->zero = 0;
	if ((ps->width && !ps->minus && !ps->zero)
		|| (ps->width && ps->dot && (ps->precision == 0)))
	{
		if (ps->dot && ps->precision > nb_len)
		{
			ps->width -= ps->precision - nb_len;
			if (nb < 0)
				ps->width -= 1;
		}
		padding(ps, nb_len);
	}
}

/*
	For a negative number the zeros are padded after the sign.
	Puts additional 0 before the number if the precision is higher 
	than the length of the number.	
*/
static void	print_integer(t_print *ps, int nb, int nb_len)
{
	if (nb < 0 && nb != INT_MIN)
	{
		ft_putchar_fd('-', 1);
		if (ps->dot && ps->precision > nb_len)
			ps->width -= ps->precision - nb_len;
		nb = -nb;
		if (ps->width && !ps->minus && ps->zero)
			padding(ps, nb_len);
		if (!ps->minus || (ps->minus && ps->precision > nb_len))
			nb_len--;
	}
	else if (ps->width && !ps->minus && ps->zero)
		padding(ps, nb_len);
	number_zero_padding(ps, nb_len);
	if (ps->dot && (ps->precision == 0) && (nb_len == 0))
		return ;
	else
		ft_putnbr_fd(nb, 1);
	if (ps->width && ps->minus)
		padding(ps, nb_len);
}
