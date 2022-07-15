/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:47:44 by angassin          #+#    #+#             */
/*   Updated: 2022/05/02 14:31:20 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Allocates (with malloc(3)) and returns a copy of’s1’ with the characters 
	specified in ’set’ removed from the beginning and the end of the string.
	Returns NULL if the allocation fails.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end]) && end)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
