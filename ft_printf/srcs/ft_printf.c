/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:22:34 by angassin          #+#    #+#             */
/*   Updated: 2022/07/12 15:53:54 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/*
	DESCRIPTION
	The printf() family of functions produces output according to a format 
	that specifies how subsequent arguments (or arguments accessed via the 
	variable-length argument facilities of stdarg(3)) are converted for output.
	The printf() function writes output to stdout, the standard output stream.
	The format string is composed of zero or more directives: ordinary 
	characters (not %), which are copied unchanged to the output stream;
    and conversion specifications, each of which results in fetching zero or 
	more subsequent arguments.  Each conversion specification is introduced by 
	the % character.  The arguments must correspond properly (after type 
	promotion) with the conversion specifier.  
	After the %, an optional field consisting of a decimal digit string and 
	optional flags appear in sequence and are evaluated in eval_format.
	RETURN VALUES
	Returns the number of characters printed (not including the trailing `\0') 
	Returns a negative value if an error occurs.
*/
int	ft_printf(const char *format, ...)
{	
	t_print				print_struct;

	va_start(print_struct.args, format);
	print_struct.len = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%' && (format + 1))
		{	
			format = eval_format(&print_struct, format + 1);
		}
		else
			print_struct.len += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(print_struct.args);
	return (print_struct.len);
}
