/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:28 by chugon            #+#    #+#             */
/*   Updated: 2025/03/03 14:05:20 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_ERROR_H
# define C3D_ERROR_H

# include "c3d_types.h"

/**
 * @brief Outputs error message to standard error
 * @param error Error code
 * @param arg Optional text to display
 * @return Returns the value of the parameter `error`
 */
int	c3d_puterror(t_error error, const char *arg);

/**
 * @brief Sets the error code
 * @param error
 * @param code
 * @param arg
 */
int	c3d_seterror(t_error *error, t_error code, const char *arg);

/**
 * @brief Resets the error
 * @param error
 */
int	c3d_reseterror(t_error *error);

#endif
