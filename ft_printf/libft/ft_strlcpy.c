/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:03:06 by angassin          #+#    #+#             */
/*   Updated: 2022/04/26 12:18:35 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	strlcpy() copies up to dstsize - 1 characters from the string src to dst, 
	NUL-terminating the result if dstsize is not 0
	If the src and dst strings overlap, the behavior is undefined.
	return the total length of src (without \0)
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while ((dstsize > 1) && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize)
		dst[i] = '\0';
	return (ft_strlen(src));
}
