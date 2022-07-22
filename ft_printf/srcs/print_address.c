/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:24:06 by angassin          #+#    #+#             */
/*   Updated: 2022/07/22 07:21:21 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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
	void	*ptr;
	int		addr_len;
	int		no_print;

	no_print = 0;
	ptr = va_arg(ps->args, void *);
	if (ptr == 0 && ps->dot && ps->precision == 0)
		addr_len = 2;
	else
		addr_len = ft_unbrlen_base((unsigned long)ptr, HEXA_LEN) + 2;
	if (ps->zero)
		ft_putstr_fd("0x", 1);
	unbr_left_padding(ps, addr_len, (unsigned long)ptr);
	if (!ps->zero)
		ft_putstr_fd("0x", 1);
	number_zero_padding(ps, addr_len - 2);
	if (ps->dot && !ptr)
		no_print = 1;
	if (addr_len && !no_print)
		ft_put_unbr_base_fd((unsigned long)ptr, HEXA, 1);
	ps->len += addr_len;
	if (ps->width && ps->minus)
		padding(ps, addr_len);
}
