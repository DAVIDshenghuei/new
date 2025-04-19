/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:04:32 by chugon            #+#    #+#             */
/*   Updated: 2024/11/05 12:51:33 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *_str)
{
	size_t	var_length;

	var_length = 0;
	while (_str[var_length] != '\0')
		++var_length;
	return (var_length);
}
