NAME			=	cub3d

CC				=	cc
RM				=	rm -rf
MAKE			=	make -C
MKDIR			=	mkdir -p

SRC_DIR			=	srcs
INC_DIR			=	includes
OBJ_DIR			=	objs
LIB_DIR			=	libs

VPATH			=	$(SRC_DIR) \
					$(SRC_DIR)/parser \
					$(SRC_DIR)/event \
					$(SRC_DIR)/utils \
					$(SRC_DIR)/display

LIBFT_DIR		=	$(LIB_DIR)/libft
MINILIBX_DIR	=	$(LIB_DIR)/minilibx-linux

CFLAGS			=	-Wall -Wextra -Werror -pedantic -MMD
CFLAGS			+=	-I$(INC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
# CFLAGS			+=	-Wno-strict-prototypes

LDFLAGS			=	-lft -L$(LIBFT_DIR) -lm
LDFLAGS			+=	-lmlx -L$(MINILIBX_DIR) -lX11 -lXext

ifneq (,$(filter debug, $(MAKECMDGOALS)))
CFLAGS			+=	-g3 -DC3D_DEBUG_ENABLED
else
CFLAGS			+=	-O2
endif

LIBFT			=	$(LIBFT_DIR)/libft.a
MINILIBX		=	$(MINILIBX_DIR)/libmlx.a

SRCS_PARSE		=	c3d_parse.c \
					c3d_header.c \
					c3d_map.c \
					c3d_map2.c

SRCS_DISPLAY	=	c3d_texture.c \
					c3d_image.c \
					c3d_minimap.c \
					c3d_window.c \
					c3d_animation.c \
					c3d_render.c \
					c3d_raycasting.c

SRC_EVENT		=	c3d_event.c \
					c3d_move.c \
					c3d_position.c

SRCS_UTILS		=	get_next_line.c \
					c3d_error.c \
					c3d_log.c \
					c3d_strings.c \
					c3d_debug.c

SRCS			=	main.c \
					c3d_game.c \
					$(SRCS_PARSE) \
					$(SRCS_DISPLAY) \
					$(SRC_EVENT) \
					$(SRCS_UTILS)

OBJS			=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.d)))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(LIBFT):
	$(MAKE) $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) $(MINILIBX_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	$(MKDIR) $@

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	$(MAKE) $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)
	$(MAKE) $(LIBFT_DIR) fclean
	$(MAKE) $(MINILIBX_DIR) clean

debug: clean $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re debug
