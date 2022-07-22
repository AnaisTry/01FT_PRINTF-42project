/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:15:16 by angassin          #+#    #+#             */
/*   Updated: 2022/07/22 10:49:54 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	flag_unbr_len_base(t_print *ps, unsigned int nb, unsigned int base);

//%u
/*
	Prints the unsigned decimal number at the spot of the placeholder %u.
*/
void	spec_u(t_print *ps)
{
	unsigned int	nb;
	int				nb_len;

	nb = va_arg(ps->args, unsigned int);
	nb_len = flag_unbr_len_base(ps, nb, DECIMAL_LEN);
	unbr_left_padding(ps, nb_len, nb);
	if (ps->width && !ps->minus && ps->zero)
		padding(ps, nb_len);
	number_zero_padding(ps, nb_len);
	if (ps->dot && !ps->precision && !nb_len && !ps->minus)
		return ;
	else if (!(ps->dot && !ps->precision && !nb))
		ft_putnbr_base_fd(nb, DECIMAL, 1);
	if (ps->width && ps->minus)
		padding(ps, nb_len);
	ps->len += nb_len;
}

// %x 
/*
	Prints the hexadecimal number at the spot of the placeholder %x,
	the digits bigger than 9 will be written in lower case.
	With the '#' flag a non-zero result has the string ‘0x’ prepended to it.
*/
void	spec_x(t_print *ps)
{
	unsigned int	nb;
	int				nb_len;

	nb = va_arg(ps->args, unsigned int);
	nb_len = flag_unbr_len_base(ps, nb, HEXA_LEN);
	if (nb > 0 && ps->hash && ps->zero && !ps->dot)
		nb_len += ft_putstr_fd("0x", 1);
	unbr_left_padding(ps, nb_len, nb);
	if (nb > 0 && ps->hash && !ps->zero)
		nb_len += ft_putstr_fd("0x", 1);
	if (ps->width && !ps->minus && ps->zero)
		padding(ps, nb_len);
	if (ps->hash && nb > 0)
		number_zero_padding(ps, nb_len - 2);
	else
		number_zero_padding(ps, nb_len);
	if (ps->dot && !ps->precision && !nb_len && !ps->minus)
		return ;
	else if (!(ps->dot && !ps->precision && !nb))
		ft_putnbr_base_fd(nb, HEXA, 1);
	if (ps->width && ps->minus)
		padding(ps, nb_len);
	ps->len += nb_len;
}

// %X
/*
	Prints the hexadecimal number at the spot of the placeholder %X,
	the digits bigger than 9 will be written in upper case.
	With the '#' flag a non-zero result has the string ‘0X’ prepended to it.
*/
void	spec_upper_x(t_print *ps)
{
	unsigned int	nb;
	int				nb_len;

	nb = va_arg(ps->args, unsigned int);
	nb_len = flag_unbr_len_base(ps, nb, HEXA_LEN);
	if (nb > 0 && ps->hash && ps->zero && !ps->dot)
		nb_len += ft_putstr_fd("0X", 1);
	unbr_left_padding(ps, nb_len, nb);
	if (nb > 0 && ps->hash && !ps->zero)
		nb_len += ft_putstr_fd("0X", 1);
	if (ps->width && !ps->minus && ps->zero)
		padding(ps, nb_len);
	if (ps->hash && nb > 0)
		number_zero_padding(ps, nb_len - 2);
	else
		number_zero_padding(ps, nb_len);
	if (ps->dot && !ps->precision && !nb_len && !ps->minus)
		return ;
	else if (!(ps->dot && !ps->precision && !nb))
		ft_putnbr_base_fd(nb, UPPER_HEXA, 1);
	if (ps->width && ps->minus)
		padding(ps, nb_len);
	ps->len += nb_len;
}

/*
	Determines the size of the unsigned number to be printed in the given base.
	In case a null precision is given with a zero, the zero won't be printed.
*/
static int	flag_unbr_len_base(t_print *ps, unsigned int nb, unsigned int base)
{
	int	nb_len;

	if (nb == 0 && ps->dot && ps->precision == 0)
		nb_len = 0;
	else
		nb_len = ft_unbrlen_base(nb, base);
	return (nb_len);
}

/*
	If a precision is given with a numeric conversion (d, i, o, u, x, and X),
	the 0 flag is ignored.
	An optional decimal digit string stored in the width variable specifies 
	a minimum field width.  
	If the converted value has fewer characters than the field width, it will 
	be padded with spaces on the left (or right, if the '-' left-adjustment 
	flag has been given) to fill out the field width.
	With the zero flag '0' the converted value is padded on the left with zeros 
	rather than blanks.
	In case of both a width and a precision is given, if the precision is higher 
	than the length of the number, then the total width will include the extra
	zeros padded before the number and the prefix if there is one.
*/
void	unbr_left_padding(t_print *ps, int nb_len, unsigned int nb)
{
	if (ps->dot && ps->zero)
		ps->zero = 0;
	if (ps->hash && ps->width && ps->dot && nb > 0 && !ps->minus)
		ps->width -= 2;
	if ((ps->width && !ps->minus && !ps->zero)
		|| (ps->width && ps->dot && !ps->precision && !ps->minus))
	{
		if ((ps->dot && ps->precision > nb_len))
			ps->width -= ps->precision - nb_len;
		if (ps->width && ps->hash && nb && !ps->dot)
			nb_len += 2;
		padding(ps, nb_len);
	}
}
