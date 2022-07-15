/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angassin <angassin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:30:25 by angassin          #+#    #+#             */
/*   Updated: 2022/05/02 17:11:43 by angassin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c);
static char		**create_array(char **arr, char *str, char c);
static char		*get_next_word(char *str, char delimiter, int start);
static void		*free_array(char **arr, int row);

/*
	Allocates (with malloc(3)) and returns an array of strings obtained by 
	splitting ’s’ using the character ’c’ as a delimiter. The array must end
	with a NULL pointer.
	Returns NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(*arr) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	return (create_array(arr, (char *)s, c));
}

//	return the number of rows necessary to contain the sub_strings
static size_t	count_words(const char *str, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	**create_array(char **arr, char *str, char c)
{
	size_t	row;

	row = 0;
	while (row < count_words(str, c))
	{
		arr[row] = get_next_word(str, c, row + 1);
		if (!arr[row])
			return (free_array(arr, row));
		row++;
	}
	arr[row] = NULL;
	return (arr);
}

/*
	Passes the part of the string before start 
	and allocates and return the next part of the string situated before 
	the next delimiter or before the end of the string
*/
static	char	*get_next_word(char *str, char delimiter, int start)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (start)
	{
		while (str[i] && str[i] == delimiter)
			i++;
		start--;
		while (start && str[i] && str[i] != delimiter)
			i++;
	}
	j = i;
	while (str[j] && str[j] != delimiter)
	{
		len++;
		j++;
	}
	return (ft_substr(&str[i], 0, len));
}

static void	*free_array(char **arr, int row)
{
	while (row--)
		free(arr[row]);
	free(arr);
	return (NULL);
}
