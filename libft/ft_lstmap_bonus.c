/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:52:10 by chugon            #+#    #+#             */
/*   Updated: 2024/11/08 12:21:07 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *_lst, void *(*_f)(void *), void (*_del)(void *))
{
	t_list	*ptr_ret;
	t_list	*ptr_new;

	ptr_ret = NULL;
	while (_lst != NULL)
	{
		ptr_new = ft_lstnew((*_f)(_lst->content));
		if (ptr_new == NULL)
		{
			ft_lstclear(&ptr_ret, _del);
			return (NULL);
		}
		ft_lstadd_back(&ptr_ret, ptr_new);
		_lst = _lst->next;
	}
	return (ptr_ret);
}
