/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:24 by chugon            #+#    #+#             */
/*   Updated: 2025/04/14 13:17:23 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_DISPLAY_H
# define C3D_DISPLAY_H

# include "c3d_types.h"

# define C3D_IMAGE_WIDTH 16
# define C3D_IMAGE_HEIGHT 16

# define C3D_BYTES_PER_COLOR 4

/**
 * @brief Structure used for texture rendering
 */
typedef struct renderdata
{
	double		step;
	double		pos;
	int			x;
	int			y;
	t_texture	*texture;
}	t_renderdata;

/**
 * @brief Loads texture of walls
 * @param data
 */
t_error	c3d_load_textures(t_data *data);

/**
 * @brief Unloads texture of walls
 * @param data
 */
void	c3d_unload_textures(t_data *data);

/**
 * @brief Returns each color component
 * @param buffer
 * @param endian
 * @return
 */
t_color	c3d_getpixel(const char buffer[], int endian);

/**
 * @brief Returns color from an image
 * @param img
 * @param x
 * @param y
 * @return
 */
t_color	c3d_getpixel_from_image(t_image *img, int x, int y);

/**
 * @brief Sets the color to the buffer
 * @param buffer
 * @param color
 * @param endian
 */
void	c3d_setpixel(char buffer[], t_color color, int endian);

/**
 * @brief Creates an image
 * @param data
 * @param img
 * @param width
 * @param height
 * @return
 */
t_error	c3d_create_image(t_data *data, t_image *img, int width, int height);

/**
 * @brief Fills an image with color
 * @param img
 * @param color
 */
void	c3d_setcolor(t_image *img, t_color color);

/**
 * @brief Creates a minimap
 * @param data
 */
void	c3d_create_minimap(t_data *data);

/**
 * @brief Destroys the minimap
 * @param data
 */
void	c3d_destroy_minimap(t_data *data);

/**
 * @brief Displays the minimap on the window
 * @param data
 */
void	c3d_update_minimap(t_data *data);

/**
 * @brief Creates an animation
 * @param data
 * @return
 */
t_error	c3d_create_animation(t_data *data);

/**
 * @brief Destroys the animation
 * @param data
 * @return
 */
t_error	c3d_destroy_animation(t_data *data);

/**
 * @brief Displays the animation on the window
 * @param data
 * @param elapsed
 */
void	c3d_update_animation(t_data *data, long elapsed);

/**
 * @brief Clears the window then redraws all elements on the windows
 * @param data
 */
int		c3d_update_window(t_data *data);

/**
 * @brief Renders pixel
 * @param data
 * @param pixel
 * @param x
 * @param y
 */
void	c3d_render_pixel(t_data *data, t_color pixel, int x, int y);

/**
 * @brief Renders image
 * @param data
 * @param ray
 * @param x
 * @param y
 */
void	c3d_render_image(t_data *data, t_image *image, int x, int y);

/**
 * @brief Renders texture hit by ray
 * @param data
 * @param ray
 * @param x
 */
void	c3d_render_texture(t_data *data, t_ray *ray, int x);

/**
 * @brief Performs raycasting
 * @param data
 */
void	c3d_raycasting(t_data *data);

#endif
