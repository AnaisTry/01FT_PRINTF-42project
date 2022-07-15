/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:21:30 by angassin          #+#    #+#             */
/*   Updated: 2022/04/26 12:19:05 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Converts a lower-case letter to the corresponding upper-case letter.  
	The argument must be representable as an unsigned char or the value of EOF.
	If the argument is a lower-case letter, the toupper() function returns the 
	corresponding upper-case letter if there is one; otherwise, the argument is 
	returned unchanged.
*/

int	ft_toupper(int c)
{
	if (ft_isalpha(c) && c >= 'a')
		c -= 32;
	return (c);
}
