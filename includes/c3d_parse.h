/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parse.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:42 by chugon            #+#    #+#             */
/*   Updated: 2025/02/27 12:08:43 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_PARSE_H
# define C3D_PARSE_H

# include "c3d_types.h"

/**
 * @brief Parses .cub file
 * @param data
 * @param filename
 */
void	c3d_parse(t_data *data, const char *filename);

/**
 * @brief Parses texture and color
 * @param data
 * @param line
 * @return
 */
t_error	c3d_parse_header(t_data *data, const char *line);

/**
 * @brief Parses map
 * @param data
 * @param line
 * @return
 */
t_error	c3d_parse_map(t_data *data, const char *line);

/**
 * @brief Checks whether map is valid
 * @param data
 * @return
 */
t_error	c3d_map_data(t_data *data);

#endif
