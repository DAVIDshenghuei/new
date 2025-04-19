/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:31 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 18:58:26 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_EVENT_H
# define C3D_EVENT_H

# include <X11/X.h>
# include <X11/keysym.h>

# include "c3d_types.h"

enum e_key
{
	C3D_KEY_MOVE_LEFT = XK_a,
	C3D_KEY_MOVE_RIGHT = XK_d,
	C3D_KEY_MOVE_DOWN = XK_s,
	C3D_KEY_MOVE_UP = XK_w,
	C3D_KEY_QUIT = XK_Escape,
	C3D_KEY_ROTATE_LEFT = XK_Left,
	C3D_KEY_ROTATE_RIGHT = XK_Right
};

enum e_event
{
	C3D_EVENT_PRESS = KeyPress,
	C3D_EVENT_RELEASE = KeyRelease,
	C3D_EVENT_MOUSE = MotionNotify,
	C3D_EVENT_CLOSE = DestroyNotify
};

enum e_event_mask
{
	C3D_MASK_PRESS = KeyPressMask,
	C3D_MASK_RELEASE = KeyReleaseMask,
	C3D_MASK_MOUSE = PointerMotionMask,
	C3D_MASK_CLOSE = StructureNotifyMask
};

/**
 * @brief Handles window closing
 */
int		c3d_event_quit(t_data *data);

/**
 * @brief Handles key presses
 * @param key
 * @param data
 */
int		c3d_event_key(int key, t_data *data);

/**
 * @brief Handles mouse movements
 * @param button
 * @param x
 * @param y
 * @param data
 */
int		c3d_event_mouse(int x, int y, t_data *data);

/**
 * @brief Handles mouse clicks
 * @param button
 * @param x
 * @param y
 * @param data
 */
int		c3d_event_click(int button, int x, int y, t_data *data);

/**
 * @brief Moves forward
 * @param data
 */
void	c3d_move_up(t_data *data);

/**
 * @brief Moves backward
 * @param data
 */
void	c3d_move_down(t_data *data);

/**
 * @brief Moves left
 * @param data
 */
void	c3d_move_left(t_data *data);

/**
 * @brief Moves right
 * @param data
 */
void	c3d_move_right(t_data *data);

/**
 * @brief Rotates the camera
 * @param player Current position
 * @param direction `C3D_DIRECTION_EAST` to turn clockwise,
 * `C3D_DIRECTION_WEST` to turn anti-clockwise
 */
void	c3d_rotate(t_data *data, t_direction direction);

#endif
