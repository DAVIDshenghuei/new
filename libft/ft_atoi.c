/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:06:43 by chugon            #+#    #+#             */
/*   Updated: 2024/11/09 12:18:41 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FT_WHITESPACE " \f\n\r\t\v"

int	ft_atoi(const char *_str)
{
	int			var_sign;
	long int	var_ret;

	var_sign = 1;
	var_ret = 0;
	while (*_str != '\0' && ft_strchr(FT_WHITESPACE, (int)(*_str)) != NULL)
		++_str;
	if (*_str == '-')
	{
		var_sign = -1;
		++_str;
	}
	else if (*_str == '+')
		++_str;
	while (ft_isdigit((int)*_str) == FT_TRUE)
	{
		var_ret = (var_ret * 10) + *_str - '0';
		++_str;
	}
	return ((int)(var_ret * var_sign));
}
