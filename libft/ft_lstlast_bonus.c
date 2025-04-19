/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:28:01 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 14:44:36 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *_lst)
{
	if (_lst == NULL)
		return (NULL);
	while (_lst->next != NULL)
		_lst = _lst->next;
	return (_lst);
}
