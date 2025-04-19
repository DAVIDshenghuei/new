/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:48:30 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 13:38:57 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes each digit of `nbr` to a string buffer. The size of the buffer must
 * be large enough for each of the digit plus the null-terminating character.
 * The buffer will be null-terminated.
 *
 * \param buffer Pointer to the buffer to write to.
 * \param nbr Integer to convert to.
 * \param size Size of the buffer.
 */
static void	ft_itoa__write(char *buffer, int nbr, size_t size);

char	*ft_itoa(int _nbr)
{
	size_t	var_size;
	int		var_nbr;
	char	*str_nbr;

	var_nbr = _nbr;
	var_size = 0;
	if (var_nbr <= 0)
		++var_size;
	while (var_nbr != 0)
	{
		var_nbr /= 10;
		++var_size;
	}
	str_nbr = (char *)malloc(sizeof(char) * (var_size + 1));
	if (str_nbr == NULL)
		return (NULL);
	ft_itoa__write(str_nbr, _nbr, var_size);
	return (str_nbr);
}

void	ft_itoa__write(char *_buffer, int _nbr, size_t _size)
{
	int	var_digit;

	_buffer[_size] = '\0';
	--_size;
	if (_nbr == 0)
		_buffer[0] = '0';
	if (_nbr < 0)
		_buffer[0] = '-';
	while (_size > 0)
	{
		var_digit = _nbr % 10;
		if (var_digit < 0)
			var_digit = -var_digit;
		_buffer[_size] = var_digit + '0';
		_nbr /= 10;
		--_size;
	}
	if (_nbr > 0)
		_buffer[0] = _nbr + '0';
}
