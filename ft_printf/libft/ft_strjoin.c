/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:47:06 by angassin          #+#    #+#             */
/*   Updated: 2022/06/09 01:32:14 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Allocates (with malloc(3)) and returns a new string, which is the result of 
	the concatenation of ’s1’ and ’s2’.
	Returns the new string or NULL if allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	cat_size;

	if (!s1 || !s2)
		return (NULL);
	cat_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	cat = malloc(sizeof(*cat) * cat_size);
	if (!cat)
		return (NULL);
	ft_strlcpy(cat, s1, ft_strlen(s1) + 1);
	ft_strlcat(cat, s2, cat_size);
	return (cat);
}
