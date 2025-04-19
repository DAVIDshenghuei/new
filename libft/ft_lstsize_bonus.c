/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:24:12 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 14:45:20 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *_lst)
{
	int	var_count;

	var_count = 0;
	while (_lst != NULL)
	{
		++var_count;
		_lst = _lst->next;
	}
	return (var_count);
}
