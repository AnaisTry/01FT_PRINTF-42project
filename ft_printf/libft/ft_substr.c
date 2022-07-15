/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:12:22 by angassin          #+#    #+#             */
/*   Updated: 2022/05/02 14:28:49 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	Allocates and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
	Returns the substring or NULL if allocation fails.
*/
char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub_size = ft_strlen(&s[start]);
	if (sub_size > len)
		sub_size = len;
	sub = malloc(sizeof(*sub) * (sub_size + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], sub_size + 1);
	return (sub);
}
