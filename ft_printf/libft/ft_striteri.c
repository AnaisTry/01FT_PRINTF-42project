/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:13:19 by angassin          #+#    #+#             */
/*   Updated: 2022/05/02 14:38:47 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Applies the function ’f’ on each character of the string passed as argument
	, passing its index as first argument. Each character is passed by
	address to ’f’ to be modified if necessary
*/

void	ft_striteri(char const *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, (char *)&s[i]);
		i++;
	}
}
