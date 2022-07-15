/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:40:50 by angassin          #+#    #+#             */
/*   Updated: 2022/04/26 12:18:12 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	Locates the first occurrence of c (converted to a char) in the string 
	pointed to by s.  The terminating null character is considered to be part 
	of the string; 
	therefore if c is `\0', the functions locate the terminating `\0'
	Return a pointer to the located character, or NULL if the character does 
	not appear in the string.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
