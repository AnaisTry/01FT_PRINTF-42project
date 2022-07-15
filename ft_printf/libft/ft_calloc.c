/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:24:36 by angassin          #+#    #+#             */
/*   Updated: 2022/04/22 00:29:31 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The calloc() function contiguously allocates enough space for count objects 
	that are size bytes of memory each and returns a pointer to the allocated 
	memory.  The allocated memory is filled with bytes of value zero.
	If successful return a pointer to allocated memory. 
	If there is an error, they return a NULL pointer and set errno to ENOMEM.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*em;

	em = malloc(count * size);
	if (!em)
		return (NULL);
	ft_bzero(em, count * size);
	return (em);
}
