/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:48 by chugon            #+#    #+#             */
/*   Updated: 2025/04/11 09:13:56 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "c3d_log.h"

#define TAG_DEBUG	"\033[104m\033[1mDEBUG\033[0m: "
#define TAG_END		"\033[0m"
#define COLOR_GRAY	"\033[37m"

#ifndef C3D_DEBUG_ENABLED

t_bool	c3d_log(const char *_fct, t_logid _d, const char *_format, ...)
{
	(void)_fct;
	(void)_d;
	(void)_format;
	return (FT_FALSE);
}

t_bool	c3d_logid(t_logid _id, ...)
{
	(void)_id;
	return (FT_FALSE);
}

#else

t_bool	c3d_log(const char *_fct, t_logid _id, const char *_format, ...)
{
	va_list	v_args;

	if (_id == C3D_LOG_NONE || c3d_logid(_id) == FT_FALSE)
		return (FT_FALSE);
	fprintf(stderr, TAG_DEBUG "\033[1min function `%s`:\033[0m ", _fct);
	fprintf(stderr, COLOR_GRAY);
	va_start(v_args, _format);
	vfprintf(stderr, _format, v_args);
	va_end(v_args);
	fprintf(stderr, TAG_END "\n");
	return (FT_TRUE);
}

t_bool	c3d_logid(t_logid _id, ...)
{
	static t_logid	logid = C3D_LOG_NONE;
	va_list			v_arg;

	if (_id == C3D_LOG_SETID)
	{
		va_start(v_arg, _id);
		logid = va_arg(v_arg, t_logid);
		va_end(v_arg);
	}
	if (logid == C3D_LOG_ALL || (logid & _id) == _id)
		return (FT_TRUE);
	return (FT_FALSE);
}

#endif
