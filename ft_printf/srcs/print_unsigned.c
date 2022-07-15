/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:15:16 by angassin          #+#    #+#             */
/*   Updated: 2022/07/15 16:33:49 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	flag_nb_len_base(t_print *ps, unsigned int nb, unsigned int base);

//%p
/*
	Prints the address of the pointer at the spot of the placeholder %p,
	expressed in hexadecimal with the "0x" prefix before the number.
	An optional decimal digit string stored in the width variable specifies 
	a minimum field width.  
	If the converted value has fewer characters than the field width, it will 
	be padded with spaces on the left (or right, if the '-' left-adjustment 
	flag has been given) to fill out the field width.
	In case the zero flag '0' is given, the zeros are padded after the 
	"0x" prefix.
	For the optional precision, in the form of a dot '.' followed by an 
	optional digit string stored in the variable precision:
	The precision indicates the minimum number of digits to be printed.
	If the precision is bigger than the number, the number will be filled 
	with zeros in front, after the prefix "0x".
*/
void	spec_p(t_print *ps)
{
	void			*ptr;
	int				addr_len;

	ptr = va_arg(ps->args, void *);
	if (ptr == 0 && ps->dot && ps->precision == 0)
		addr_len = 2;
	else
		addr_len = ft_unbrlen_base((unsigned long)ptr, HEXA_LEN) + 2;
	if (ps->zero)
		ft_putstr_fd("0x", 1);
	unbr_left_padding(ps, addr_len);
	if (!ps->zero)
		ft_putstr_fd("0x", 1);
	number_zero_padding(ps, addr_len - 2);
	if (addr_len)
		ft_put_unbr_base_fd((unsigned long)ptr, HEXA, 1);
	ps->len += addr_len;
	if (ps->width && ps->minus)
		padding(ps, addr_len);
}

//%u
/*
	Prints the unsigned decimal number at the spot of the placeholder %u.
*/
void	spec_u(t_print *ps)
{
	unsigned int	nb;
	int				nb_len;

	nb = va_arg(ps->args, unsigned int);
	nb_len = flag_nb_len_base(ps, nb, DECIMAL_LEN);
	unbr_left_padding(ps, nb_len);
	if (ps->width && !ps->minus && ps->zero)
		padding(ps, nb_len);
	number_zero_padding(ps, nb_len);
	if (ps->dot && (ps->precision == 0) && (nb_len == 0))
		return ;
	else
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
	nb_len = flag_nb_len_base(ps, nb, HEXA_LEN);
	if (nb > 0 && ps->hash && ps->zero)
		nb_len += ft_putstr_fd("0x", 1);
	unbr_left_padding(ps, nb_len);
	if (nb > 0 && ps->hash && !ps->zero)
		nb_len += ft_putstr_fd("0x", 1);
	if (ps->width && !ps->minus && ps->zero)
		padding(ps, nb_len);
	if (ps->hash && nb > 0)
		number_zero_padding(ps, nb_len - 2);
	else
		number_zero_padding(ps, nb_len);
	if (ps->dot && (ps->precision == 0) && (nb_len == 0))
		return ;
	else
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
	nb_len = flag_nb_len_base(ps, nb, HEXA_LEN);
	if (nb > 0 && ps->hash && ps->zero)
		nb_len += ft_putstr_fd("0X", 1);
	unbr_left_padding(ps, nb_len);
	if (nb > 0 && ps->hash && !ps->zero)
		nb_len += ft_putstr_fd("0X", 1);
	if (ps->width && !ps->minus && ps->zero)
		padding(ps, nb_len);
	if (ps->hash && nb > 0)
		number_zero_padding(ps, nb_len - 2);
	else
		number_zero_padding(ps, nb_len);
	if (ps->dot && (ps->precision == 0) && (nb_len == 0))
		return ;
	else
		ft_putnbr_base_fd(nb, UPPER_HEXA, 1);
	if (ps->width && ps->minus)
		padding(ps, nb_len);
	ps->len += nb_len;
}

/*
	Determines the size of the unsigned number to be printed in the given base.
	In case a null precision is given with a zero, the zero won't be printed.
*/
static int	flag_nb_len_base(t_print *ps, unsigned int nb, unsigned int base)
{
	int	nb_len;

	if (nb == 0 && ps->dot && ps->precision == 0)
		nb_len = 0;
	else
		nb_len = ft_unbrlen_base(nb, base);
	return (nb_len);
}
