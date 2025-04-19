/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:27:30 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 13:34:50 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calculates and returns the starting index of the trimmed string.
 */
static size_t	ft_strtrim__start(char const *str, char const *set);

/**
 * Calculates and returns the ending index of the trimmed string.
 */
static size_t	ft_strtrim__end(const char *str, const char *set);

char	*ft_strtrim(char const *_str, char const *_set)
{
	char	*str_retval;
	size_t	idx_retval;
	size_t	var_start;
	size_t	var_size;

	var_start = ft_strtrim__start(_str, _set);
	var_size = ft_strtrim__end(_str, _set) - var_start;
	str_retval = (char *)malloc(sizeof(char) * (var_size + 1));
	if (str_retval == NULL)
		return (NULL);
	idx_retval = 0;
	while (idx_retval < var_size)
	{
		str_retval[idx_retval] = _str[var_start + idx_retval];
		++idx_retval;
	}
	str_retval[idx_retval] = '\0';
	return (str_retval);
}

size_t	ft_strtrim__start(char const *_str, char const *_set)
{
	size_t	idx_str;

	idx_str = 0;
	while (_str[idx_str] != '\0')
	{
		if (ft_strchr(_set, (int)_str[idx_str]) == NULL)
			break ;
		++idx_str;
	}
	return (idx_str);
}

size_t	ft_strtrim__end(char const *_str, char const *_set)
{
	size_t	var_size;
	size_t	idx_str;

	var_size = ft_strlen(_str);
	idx_str = 0;
	while (_str[idx_str] != '\0')
	{
		if (ft_strchr(_set, _str[var_size - 1 - idx_str]) == NULL)
			return (var_size - idx_str);
		++idx_str;
	}
	return (var_size);
}
