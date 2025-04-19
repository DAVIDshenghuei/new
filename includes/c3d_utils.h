/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:49 by chugon            #+#    #+#             */
/*   Updated: 2025/04/08 13:56:54 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_UTILS_H
# define C3D_UTILS_H

# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef M_PI_2
#  define M_PI_2 1.57079632679489661923
# endif

/**
 * \note The returned pointed may need to be passed as parameter of `free(3)`
 * to avoid memory leak.
 * 
 * @param fd File descriptor to read from
 * @return Returns a line from the text file pointed by `fd`.
 * If an error occurred or there is nothing to read, `NULL` is returned.
 */
char	*get_next_line(int fd);

/**
 * @brief Returns the number of strings in an array
 * @param array
 * @return
 */
size_t	c3d_strslen(char **array);

/**
 * @brief Appends a new string
 * @param array
 * @param str
 * @return Pointer to the array of strings
 */
char	**c3d_strscat(char **array, const char *str);

/**
 * @brief Deallocates the array of strings
 * @param array
 */
char	**c3d_strsclear(char **array);

/**
 * @brief Displays debugging messages
 * @param data
 */
void	c3d_debug(t_data *data);

#endif
