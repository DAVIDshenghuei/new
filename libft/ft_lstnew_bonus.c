/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:31:50 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 14:34:12 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *_content)
{
	t_list	*ptr_new;

	ptr_new = (t_list *)malloc(sizeof(t_list));
	if (ptr_new == NULL)
		return (NULL);
	ptr_new->content = _content;
	ptr_new->next = NULL;
	return (ptr_new);
}
