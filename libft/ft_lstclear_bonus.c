/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:40:50 by chugon            #+#    #+#             */
/*   Updated: 2024/09/22 20:17:17 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **_lst, void (*_del)(void *))
{
	t_list	*ptr_curr;
	t_list	*ptr_clear;

	ptr_curr = *_lst;
	while (ptr_curr != NULL)
	{
		ptr_clear = ptr_curr;
		ptr_curr = ptr_curr->next;
		ft_lstdelone(ptr_clear, _del);
	}
	*_lst = NULL;
}
