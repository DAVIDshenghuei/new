/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:41:53 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 13:34:36 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FT_FLAG_NEWWORD 1
#define FT_FLAG_ENDWORD 0

/**
 * Calculates and returns the number of strings obtaining by splitting `str`.
 */
static size_t	ft_split__count(const char *str, char c);

/**
 * Allocates and returns a substring starting from the position `start`.
 */
static char		*ft_split__substr(const char *str, size_t *start, char c);

char	**ft_split(char const *_str, char _c)
{
	char	**tab_retval;
	size_t	var_count;
	size_t	idx_count;
	size_t	var_start;

	var_count = ft_split__count(_str, _c);
	tab_retval = (char **)malloc(sizeof(char *) * (var_count + 1));
	if (tab_retval == NULL)
		return (NULL);
	idx_count = 0;
	var_start = 0;
	while (idx_count < var_count)
	{
		tab_retval[idx_count] = ft_split__substr(_str, &var_start, _c);
		++idx_count;
	}
	tab_retval[var_count] = NULL;
	return (tab_retval);
}

size_t	ft_split__count(const char *_str, char _c)
{
	int		var_flag;
	size_t	var_count;

	var_flag = FT_FLAG_NEWWORD;
	var_count = 0;
	while (*_str != '\0')
	{
		if (*_str != _c)
		{
			if (var_flag == FT_FLAG_NEWWORD)
			{
				++var_count;
				var_flag = FT_FLAG_ENDWORD;
			}
		}
		else
			var_flag = FT_FLAG_NEWWORD;
		++_str;
	}
	return (var_count);
}

char	*ft_split__substr(const char *_str, size_t *_start, char _c)
{
	char	*str_retval;
	size_t	var_length;

	while (_str[*_start] == _c)
		*_start += 1;
	var_length = 0;
	while (_str[*_start + var_length] != '\0')
	{
		if (_str[*_start + var_length] == _c)
			break ;
		++var_length;
	}
	str_retval = ft_substr(_str, *_start, var_length);
	*_start += var_length;
	return (str_retval);
}
