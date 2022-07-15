/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:26:03 by angassin          #+#    #+#             */
/*   Updated: 2022/04/26 12:18:33 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Appends string src to the end of dst.  
	It will append at most dstsize - strlen(dst) - 1 characters.  
	It will then NUL-terminate, unless dstsize is 0 or the original dst string 
	was longer than dstsize.
	Take the full size of the destination buffer and guarantee NUL-termination 
	if there is room.  Note that room for the NUL should be included in dstsize.
	If the src and dst strings overlap, the behavior is undefined.
	Return the total length  of dst plus the length of src.
	However, if strlcat() traverses size characters without finding a NUL, 
	the length of the string is considered to be dstsize and the destination string 
	will not be NUL-terminated (since there was no space for the NUL).
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cat_size;
	size_t	src_size;
	size_t	i;

	cat_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (cat_size >= dstsize || !src || !dst)
		return (src_size + dstsize);
	i = cat_size;
	while ((i < dstsize - 1) && *src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (src_size + cat_size);
}
