/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:52:37 by chugon            #+#    #+#             */
/*   Updated: 2024/11/12 11:03:34 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *_prefix, const char *_suffix)
{
	size_t	var_size;
	char	*str_retval;

	var_size = ft_strlen(_prefix) + ft_strlen(_suffix) + 1;
	str_retval = (char *)malloc(var_size);
	if (str_retval == NULL)
		return (NULL);
	ft_strlcpy(str_retval, _prefix, var_size);
	ft_strlcat(str_retval, _suffix, var_size);
	return (str_retval);
}
