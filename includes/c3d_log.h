/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_log.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:39 by chugon            #+#    #+#             */
/*   Updated: 2025/04/11 09:13:25 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_LOG_H
# define C3D_LOG_H

# include <stdarg.h>
# include <stdio.h>

# include <libft.h>

typedef enum e_logid
{
	C3D_LOG_NONE = 0,
	C3D_LOG_ALL = 1,
	C3D_LOG_GAME = 1 << 1,
	C3D_LOG_PARSE = 1 << 2,
	C3D_LOG_EVENT = 1 << 3,
	C3D_LOG_IMAGE = 1 << 4,
	C3D_LOG_SETID = 1 << 16
}	t_logid;

/**
 * @brief Logs
 * @param fct
 * @param id
 * @param format
 * @param ...
 * @return
 */
t_bool	c3d_log(const char *fct, t_logid id, const char *format, ...);

/**
 * @brief Sets logger id
 * @param id
 * @param ...
 */
t_bool	c3d_logid(t_logid id, ...);

#endif
