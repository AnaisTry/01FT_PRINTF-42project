/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:29:30 by angassin          #+#    #+#             */
/*   Updated: 2022/07/21 17:09:20 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void			initialise_flags(t_print *print_struct);
static int			eval_spec(t_print *print_struct, const char specifier);
static int			index_spec(const char *specifiers, char c);
static const char	*handle_width(t_print *print_struct, const char *format);

/*	
	Checks if the chars after % and before the specifier are flags 
	and set them accordingly.
	A '-' overrides a '0' if both are given.
	A '+' overrides a space if both are used.
	Checks if there is a digit string to implement the minimum width.
	If valid, converts the argument in the corresponding format given by the 
	specifier or prints the character if invalid.
*/
const char	*eval_format(t_print *print_struct, const char *format)
{
	initialise_flags(print_struct);
	while (*format && !ft_strchr(PLACEHOLDERS, *format))
	{	
		if (*format == '#')
			print_struct->hash = 1;
		else if (*format == '.')
			print_struct->dot = 1;
		else if (*format == '-')
			print_struct->minus = 1;
		else if (*format == '0' && !print_struct->dot && !print_struct->minus)
			print_struct->zero = 1;
		else if (*format == '+')
			print_struct->plus = 1;
		else if (*format == ' ' && !print_struct->plus)
			print_struct->space = 1;
		else if (ft_isdigit(*format))
			format = handle_width(print_struct, format);
		format++;
	}
	if ((eval_spec(print_struct, *format) < 0) && *format)
		print_struct->len += ft_putchar_fd(*format, 1);
	return (format);
}

/*	
	Variable precision to store the number after the dot.
	Variable width to store the field width to be printed.
*/
static void	initialise_flags(t_print *print_struct)
{
	print_struct->hash = 0;
	print_struct->space = 0;
	print_struct->plus = 0;
	print_struct->zero = 0;
	print_struct->minus = 0;
	print_struct->dot = 0;
	print_struct->precision = 0;
	print_struct->width = 0;
}

/*
	Checks if the given char is a specifier, prints the argument (formated 
	according to the specifier) and updates the print_struct accordingly.
	Returns -1 in case of an invalid specifier.
	Deactivates the hash flag for other specifiers than hexa.

	Conversion array :

	Index   Format   Function
	------|--------|---------
 	 [0]  |   %c   | spec_c
     [1]  |   %s   | spec_s
	 [2]  |   %p   | spec_p
	 [3]  |   %d   | spec_d
	 [4]  |   %i   | spec_i
	 [5]  |   %u   | spec_u
	 [6]  |   %x   | spec_x
	 [7]  |   %X   | spec_upper_x
	 [8]  |   %%   | spec_percent
*/
static int	eval_spec(t_print *print_struct, const char specifier)
{
	static t_conv_ptr	conv_arr[9] = {spec_c, spec_s, spec_p, spec_d, spec_i,
		spec_u, spec_x, spec_upper_x, spec_percent};
	int					spec_index;

	if (!specifier)
		return (-1);
	if (ft_strchr(PLACEHOLDERS, specifier))
	{	
		spec_index = index_spec(PLACEHOLDERS, specifier);
		if (!(spec_index == 6 || spec_index == 7))
			print_struct->hash = 0;
		conv_arr[spec_index](print_struct);
		return (0);
	}
	else
		return (-1);
}

/*
	Returns the index of the specifier in the conversion array
*/
static int	index_spec(const char *specifiers, char c)
{
	char	*ptr_to_spec;
	int		spec_index;

	spec_index = 0;
	ptr_to_spec = ft_strchr(specifiers, c);
	spec_index = (ptr_to_spec - specifiers);
	return (spec_index);
}

/* 
	If a precision is given, sets the minimum number of digits to appear for d,
	i, o, u, x and X or the maximum of characters to be printed from a string 
	for s conversions.
	Otherwise specifies a minimum field width given by the decimal digit string.
*/
static const char	*handle_width(t_print *print_struct, const char *format)
{
	if (print_struct->dot)
		print_struct->precision = ft_atoi(format);
	else
		print_struct->width = ft_atoi(format);
	while (*(format + 1) && ft_isdigit(*(format + 1)))
		format++;
	return (format);
}
