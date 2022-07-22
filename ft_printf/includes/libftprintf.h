/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:25:14 by angassin          #+#    #+#             */
/*   Updated: 2022/07/22 10:50:29 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

/*									[Includes]								*/
# include "../libft/libft.h"
# include <stdarg.h>

/*									[Macros]								*/
# define PLACEHOLDERS "cspdiuxX%"
# define DECIMAL "0123456789"
# define HEXA "0123456789abcdef"
# define UPPER_HEXA "0123456789ABCDEF"
# define DECIMAL_LEN 10
# define HEXA_LEN 16

/*									[Typedefs]								*/
typedef struct s_print
{
	va_list	args;
	int		len;
	int		hash;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		dot;
	int		precision;
	int		width;
}t_print;

// pointer for format functions
typedef void	(*t_conv_ptr)(t_print *print_struct);

/*									[Functions]								*/

//ft_printf.c  
/* 
	The __attribute__ directive checks that the format requirements 
	are the same than for printf 
*/
int			ft_printf(const char *format, ...)
			__attribute__((format(printf, 1, 2)));

//eval.c
const char	*eval_format(t_print *print_struct, const char *format);

//print_char.c 
void		spec_c(t_print *print_struct);
void		spec_s(t_print	*print_struct);
void		spec_percent(t_print *ps);

//print_integer.c
void		spec_d(t_print *ps);
void		spec_i(t_print *ps);

//print_unsigned.c
void		spec_u(t_print *ps);
void		spec_x(t_print *ps);
void		spec_upper_x(t_print *ps);
void		unbr_left_padding(t_print *ps, int nb_len, unsigned int nb);

//print_address.c
void		spec_p(t_print *ps);

//padding.c
void		padding(t_print *print_struct, int nb_len);
void		number_zero_padding(t_print *print_struct, int nb_len);
#endif