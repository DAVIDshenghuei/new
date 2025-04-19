/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:35 by chugon            #+#    #+#             */
/*   Updated: 2025/03/03 14:15:16 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_GAME_H
# define C3D_GAME_H

# include "c3d_types.h"

/**
 * @brief Initializes game data
 * @param data
 */
void	c3d_create(t_data *data);

/**
 * @brief Deallocates game data
 * @param data
 */
void	c3d_destroy(t_data *data);

/**
 * @brief Game loop
 * @param data
 */
void	c3d_run(t_data *data);

/**
 * @brief Calls `c3d_destroy` and exit the program
 * @param data
 * @param error
 * @param arg
 */
void	c3d_exit(t_data *data, t_error error, const char *arg);

#endif
