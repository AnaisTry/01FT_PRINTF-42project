/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:34:10 by angassin          #+#    #+#             */
/*   Updated: 2022/07/12 19:33:14 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

// %c
/*
	Prints the character given in argument where the placeholder %c stands.
	If a width is given, in the form of a digit string, pads spaces or 0 
	(in case the 0 flag is given) before the character or, in the case the '-'
	flag is given, the converted value is padded on the right with blanks, 
	rather than on the left with blanks or zeros.
*/
void	spec_c(t_print *print_struct)
{
	char	c;

	c = va_arg(print_struct->args, int);
	if (print_struct->width && !print_struct->minus)
		padding(print_struct, 1);
	print_struct->len += ft_putchar_fd(c, 1);
	if (print_struct->width && print_struct->minus)
		padding(print_struct, 1);
}

// %s
/*
	Checks the validity of the string.
	Checks if it needs to be truncated.
	Outputs the string (or (null)) in the place of the placeholder %s padding 
	the string accordingly with spaces or 0 (in case the 0 flag is given) 
	if a width, in the form of a digit is given.
	In case the '-' flag is given, the string is left justified.
	For the optional precision, in the form of a dot '.' followed by an optional 
	digit string stored in the variable precision:
	The precision gives the maximum number of characters to be printed 
	from the string (or from (null) in case of a NULL string). 
	Doesn't print the string for the cases %0.s , %-.s and %.0s 
*/
void	spec_s(t_print	*print_struct)
{
	char	*s;
	char	*s_trunc;
	int		s_len;

	s_len = 0;
	s = va_arg(print_struct->args, char *);
	if (!s)
		s = "(null)";
	if (print_struct->dot && (print_struct->precision < (int)ft_strlen(s)))
		s_len = print_struct->precision;
	else
		s_len = ft_strlen(s);
	if (print_struct->width && !print_struct->minus)
		padding(print_struct, s_len);
	if (print_struct->dot)
	{
		s_trunc = ft_substr(s, 0, s_len);
		print_struct->len += ft_putstr_fd(s_trunc, 1);
		free(s_trunc);
	}
	else
		print_struct->len += ft_putstr_fd(s, 1);
	if (print_struct->width && print_struct->minus)
		padding(print_struct, s_len);
}

// %%
/*
	Prints a percent where it stands, same padding rules as 
	for char.
*/
void	spec_percent(t_print *ps)
{
	if (ps->width && !ps->minus)
		padding(ps, 1);
	ps->len += ft_putchar_fd('%', 1);
	if (ps->width && ps->minus)
		padding(ps, 1);
}
