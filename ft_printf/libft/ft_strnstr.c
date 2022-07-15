/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:37:23 by angassin          #+#    #+#             */
/*   Updated: 2022/05/02 17:43:57 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Locates the first occurrence of the null-terminated string needle in
	the string haystack, where not more than len characters are searched.
	Characters that appear after a `\0' character are not searched.
	If needle is an empty string, haystack is returned; 
	if needle occurs nowhere in haystack, NULL is returned; 
	otherwise a pointer to the first character of the first occurrence 
	of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (len && *haystack)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0
			&& len >= ft_strlen(needle))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
