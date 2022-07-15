/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:05:08 by angassin          #+#    #+#             */
/*   Updated: 2022/04/25 11:47:58 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The strdup() function allocates sufficient memory for a copy of the 
	string s1, does the copy, and returns a pointer to it.  
	The pointer may subsequently be used as an argument to the function free.
	If insufficient memory is available, NULL is returned and errno is set 
	to ENOMEM.
*/

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = malloc(sizeof(*cpy) * (ft_strlen(s1) + 1));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, ft_strlen(s1) + 1);
	return (cpy);
}
