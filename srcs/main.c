/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:19 by chugon            #+#    #+#             */
/*   Updated: 2025/03/03 15:36:08 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	usage(const char *name);

int	main(int argc, const char *argv[])
{
	t_data	v_data;

	c3d_logid(C3D_LOG_SETID, C3D_LOG_ALL);
	if (argc != 2)
		return (usage(argv[0]));
	ft_memset(&v_data, 0, sizeof(t_data));
	c3d_parse(&v_data, argv[1]);
	c3d_create(&v_data);
	c3d_debug(&v_data);
	c3d_run(&v_data);
	c3d_destroy(&v_data);
	return (v_data.error);
}

int	usage(const char *_name)
{
	c3d_puterror(C3D_ESYNTAX, NULL);
	ft_putstr_fd("Usage: ", STDERR_FILENO);
	ft_putstr_fd((char *)_name, STDERR_FILENO);
	ft_putendl_fd(" <map>", STDERR_FILENO);
	return (EXIT_FAILURE);
}
