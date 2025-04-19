/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:43:53 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 14:19:27 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr__recursive_write(long int nbr, int fd);

void	ft_putnbr_fd(int _nbr, int _fd)
{
	long int	var_nbr;

	var_nbr = _nbr;
	if (var_nbr < 0)
	{
		write(_fd, "-", 1);
		var_nbr = -var_nbr;
	}
	if (var_nbr == 0)
		write(_fd, "0", 1);
	else
		ft_putnbr__recursive_write(var_nbr, _fd);
}

void	ft_putnbr__recursive_write(long int _nbr, int _fd)
{
	char	var_digit;

	if (_nbr > 9)
		ft_putnbr__recursive_write(_nbr / 10, _fd);
	var_digit = _nbr % 10 + '0';
	write(_fd, &var_digit, 1);
}
