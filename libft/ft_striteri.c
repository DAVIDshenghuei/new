/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:16:25 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 13:48:45 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *_str, void (*_f)(unsigned int, char *))
{
	unsigned int	idx_str;

	idx_str = 0;
	while (_str[idx_str] != '\0')
	{
		(*_f)(idx_str, _str + idx_str);
		++idx_str;
	}
}
