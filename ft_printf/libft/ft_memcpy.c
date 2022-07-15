/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:57:26 by angassin          #+#    #+#             */
/*   Updated: 2022/04/14 17:28:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The memcpy() function copies n bytes from memory area src to memory area dst.  
	If dst and src overlap, behavior is undefined.  
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp;

	if (!dst && !src)
	{
		return (NULL);
	}
	temp = (unsigned char *)dst;
	while (n--)
	{
		*temp = *(unsigned char *)src;
		temp++;
		src++;
	}
	return (dst);
}
