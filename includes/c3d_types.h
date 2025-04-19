/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshenghu <lshenghu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:46 by chugon            #+#    #+#             */
/*   Updated: 2025/04/19 12:27:39 by lshenghu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_TYPES_H
# define C3D_TYPES_H

# include <sys/time.h>

# include <libft.h>

# define C3D_BUFFSIZE 1024

# define C3D_GAME_NAME "Cub3D"
# define C3D_WINDOW_WIDTH 1024
# define C3D_WINDOW_HEIGHT 720

# define C3D_MINIMAP_WIDTH 11
# define C3D_MINIMAP_HEIGHT 11

# define C3D_FRAME_COUNT 20

typedef struct timeval	t_fps;

/**
 * @brief Code error
 */
typedef enum e_error
{
	C3D_ENONE = 0,
	C3D_ESYNTAX,
	C3D_EFILE,
	C3D_EPARSE,
	C3D_EBADID,
	C3D_EALREADY,
	C3D_EFORMAT,
	C3D_EMAP,
	C3D_EMLX,
	C3D_ELOAD,
	C3D_ESYSTEM
}	t_error;

/**
 * @brief Texture identifier
 */
typedef enum e_texture_id
{
	C3D_TID_N = 0,
	C3D_TID_S,
	C3D_TID_W,
	C3D_TID_E,
	C3D_TEXTURE_COUNT,
	C3D_TID_F = C3D_TEXTURE_COUNT,
	C3D_TID_C,
	C3D_TOTAL_COUNT
}	t_tid;

/**
 * @brief RGBA color
 */
typedef union u_color
{
	int	rgb;
	struct
	{
		char	b;
		char	g;
		char	r;
		char	a;
	};
}	t_color;

/**
 * @brief Image
 */
typedef struct s_image
{
	void	*data;
	char	*buffer;
	int		width;
	int		height;
	int		bpp;
	int		bytes;
	int		endian;
}	t_image;

/**
 * @brief Texture
 */
typedef struct s_texture
{
	char	*filename;
	t_image	image;
	t_color	color;
	t_bool	set;
}	t_texture;

/**
 * @brief Map type
 */
enum e_map_type
{
	C3D_MAP_SPACE = '0',
	C3D_MAP_WALL = '1',
	C3D_MAP_EMPTY = '_',
	C3D_MAP_PLAYER = 'P',
	C3D_MAP_OTHER = 'X'
};

/**
 * @brief Map
 */
/// @todo need it
typedef struct s_map
{
	int		width;
	int		height;
	char	**data;
}	t_map;

/**
 * @brief Initial direction of the player
 */
typedef enum e_direction
{
	C3D_DIRECTION_NONE = 0,
	C3D_DIRECTION_NORTH = 'N',
	C3D_DIRECTION_SOUTH = 'S',
	C3D_DIRECTION_WEST = 'W',
	C3D_DIRECTION_EAST = 'E'
}	t_direction;

/**
 * @brief Vector for ray casting calculation
 */
/// @todo need it
typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

/**
 * @brief Coordinates
 */
/// @todo need it
typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

/**
 * @brief Player structure
 */
/// @todo need it
typedef struct s_player
{
	t_bool		set;
	double		angle;
	t_vector	position;
}	t_player;

typedef struct s_display
{
	void	*mlx;
	void	*window;
}	t_display;

typedef struct s_minimap
{
	char	data[C3D_MINIMAP_HEIGHT][C3D_MINIMAP_WIDTH];
	t_image	wall;
	t_image	space;
	t_image	player;
	t_image	empty;
}	t_minimap;

typedef struct s_animation
{
	t_image	frames[C3D_FRAME_COUNT];
	long	duration;
	int		index;
	int		x;
	int		y;
	t_bool	show;
}	t_animation;

/**
 * @brief Ray
 */
/// @todo need it
typedef struct s_ray
{
	t_vector	camera;
	t_vector	dir;
	t_vector	ray_dir;
	t_vector	side;
	t_vector	delta;
	t_vector	plane;
	t_coord		map;
	t_coord		step;
	double		wall_dist;
	double		wallx;
	int			surface;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

typedef struct s_data
{
	t_display	display;
	t_texture	texture[C3D_TOTAL_COUNT];
	t_animation	animation;
	t_map		map;
	t_minimap	minimap;
	t_player	player;
	t_ray		ray;
	t_fps		fps;
	t_error		error;
	t_bool		update;
	t_image		screen;
}	t_data;

#endif
