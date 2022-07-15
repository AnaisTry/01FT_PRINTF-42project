/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:08:13 by angassin          #+#    #+#             */
/*   Updated: 2022/04/14 12:57:41 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The memmove() function copies len bytes from string src to string dst.  
	The two strings may overlap; 
	the copy is always done in a non-destructive manner.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	p_dst = dst;
	p_src = src;
	if (dst > src)
	{
		while (len--)
			*(p_dst + len) = *(p_src + len);
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
