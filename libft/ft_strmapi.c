/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:32:05 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 13:44:51 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *_str, char (*_f)(unsigned int, char))
{
	char			*str_retval;
	unsigned int	idx_str;

	str_retval = (char *)malloc(sizeof(char) * (ft_strlen(_str) + 1));
	if (str_retval == NULL)
		return (NULL);
	idx_str = 0;
	while (_str[idx_str] != '\0')
	{
		str_retval[idx_str] = (*_f)(idx_str, _str[idx_str]);
		++idx_str;
	}
	str_retval[idx_str] = '\0';
	return (str_retval);
}
