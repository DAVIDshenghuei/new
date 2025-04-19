/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:42 by chugon            #+#    #+#             */
/*   Updated: 2025/02/27 12:07:43 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>

#include <libft.h>

#include "c3d_error.h"

#define TAG_ERROR	"\033[91m\033[1mERROR: "
#define TAG_END		"\033[0m"

static char	*c3d_tostring(t_error error);

int	c3d_seterror(t_error *_error, t_error _code, const char *_arg)
{
	if (*_error == C3D_ENONE)
		*_error = c3d_puterror(_code, _arg);
	return (*_error);
}

int	c3d_reseterror(t_error *_error)
{
	*_error = C3D_ENONE;
	return (C3D_ENONE);
}

int	c3d_puterror(t_error _error, const char *_arg)
{
	if (_error == C3D_ENONE)
		return (C3D_ENONE);
	ft_putstr_fd(TAG_ERROR, STDERR_FILENO);
	if (_error < C3D_ESYSTEM)
		ft_putstr_fd(c3d_tostring(_error), STDERR_FILENO);
	else if (_error == C3D_ESYSTEM)
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	else
		ft_putstr_fd("unknown error", STDERR_FILENO);
	if (_arg != NULL)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd((char *)_arg, STDERR_FILENO);
	}
	ft_putendl_fd(TAG_END, STDERR_FILENO);
	return (_error);
}

char	*c3d_tostring(t_error _error)
{
	static const char	*string[] = {
		"No error",
		"Syntax error",
		"Invalid file",
		"Parse error",
		"Unknown identifier",
		"Identifier already used",
		"Bad format",
		"Invalid map",
		"Minilibx error",
		"Failed to load asset"
	};

	return ((char *)string[_error]);
}
