/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:34:26 by chugon            #+#    #+#             */
/*   Updated: 2024/11/08 12:11:57 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **_list, t_list *_element)
{
	t_list	*ptr_last;

	ptr_last = ft_lstlast(*_list);
	if (ptr_last == NULL)
		*_list = _element;
	else
		ptr_last->next = _element;
}
