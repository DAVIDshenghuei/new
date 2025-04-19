/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:23:06 by chugon            #+#    #+#             */
/*   Updated: 2024/11/05 15:36:48 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *_src)
{
	size_t	var_length;
	char	*str_ret;

	var_length = ft_strlen(_src);
	str_ret = (char *)malloc(sizeof(char) * (var_length + 1));
	if (str_ret == NULL)
		return (NULL);
	ft_strlcpy(str_ret, _src, var_length + 1);
	return (str_ret);
}
