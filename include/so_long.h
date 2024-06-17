/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:03:19 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/11 18:27:29 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/***********************/
/*  LIBRARIES IMPORTS  */
/***********************/

# include "../Libraries/pedro_lib/pedro_lib.h"
# include "../Libraries/mlx/mlx.h"
# include "../Libraries/mlx/mlx_int.h"
# include <sys/stat.h>
# include <fcntl.h>

# define HERO_FRAME 2
# define COLLECTIBLE_FRAME 6
# define SPAWN_FRAME 4
# define BG_FRAME 2
# define FRAME_DELAY 1000
# define HERO_DELAY 22000
# define COLLECTIBLE_DELAY 30000
# define SPAWN_DELAY 2000
# define BG_DELAY 50000
/************************/
/*      STRUCTURES      */
/************************/

// Touches du clavier

enum	e_touches
{
	W = 119,
	UP_arrow = 65362,
	A = 97,
	LEFT_arrow = 65361,
	S = 115,
	DOWN_arrow = 65364,
	D = 100,
	RIGHT_arrow = 65363,
	ESC = 65307,
};

// Animations

typedef struct s_spawn
{
	void	*anim[SPAWN_FRAME];
	int		frame;
}		t_spawn;

typedef struct s_hero
{
	void	*anim[HERO_FRAME];
	int		frame;
}		t_hero;

typedef struct s_collectible
{
	void	*anim[COLLECTIBLE_FRAME];
	int		frame;	
}		t_collectible;

typedef struct s_bad_guy
{
	void	*anim[BG_FRAME];
	int		frame;
}		t_bad_guy;

// Images 

typedef struct s_image
{
	void	*floor;
	void	*wall;
	void	*exit;
}		t_image;

// Menu

typedef struct s_menu
{
	void	*pegi18;
	void	*photo;
	char	*jouer;
	char	*quitter;
	char	*credit;
}		t_menu;

// Getting the map

typedef struct s_get
{
	int		fd;
	char	*line;
	char	*fline;
	char	*tmp;
	char	**map;
}		t_get;

// Position du joueur

typedef struct s_coor
{
	int	x;
	int	y;
}		t_coor;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

// Le jeu

typedef struct s_jeu
{
	int				x;
	int				y;
	int				p_x;
	int				p_y;
	int				map_height;
	int				map_width;
	int				screen_height;
	int				screen_width;
	int				c;
	int				e;
	int				p;
	int				n;
	int				steps;
	char			**map;
	void			*mlx;
	void			*win;
	t_get			get;
	t_pos			pos;
	t_coor			coor;
	t_spawn			spawn;
	t_hero			hero;
	t_bad_guy		bad_guy;
	t_collectible	collectible;
	t_image			image;
	t_menu			menu;
}		t_jeu;

/************************/
/*	    PROTOTYPES	    */
/************************/

// Utils

void			visual_map(char **ap);
void			init_data_get(t_jeu *g);
void			init_data_co(t_jeu *v);
void			init_x_y(t_jeu *v);
int				map_width(t_jeu *v);
int				map_height(t_jeu *v);
void			player_pos(t_jeu *v, int y, int x);

// Parsing

const char		*final_flash(int ac, char **av);

// Getting the map

char			*read_the_map(t_jeu *g, char*s);
char			**get_the_map(t_jeu *g, char *s);

// Checking the map

bool			check_map(t_jeu *v);
bool			check_limits(t_jeu *v);
bool			check_square(t_jeu *v);
bool			check_content(t_jeu *v);
bool			check_viability(t_jeu *v);
bool			check_characters(t_jeu *v);
void			flood_fill(t_jeu *v, int y, int x);

// Demarrage du jeu

void			init_pointers(t_jeu *jeu);
void			ignite_game(t_jeu *jeu);

// Telechargement des images

void			dl_anim_pics(t_jeu *jeu);

// Images management

void			get_image(t_jeu *jeu, char *img_path, void **img_ptr);
void			get_anim(t_jeu *jeu, char **img_path,
					void **img_ptr, int frames);
void			put_image(t_jeu *jeu, char c, int x, int y);
void			display(t_jeu *jeu);

// Animation

int				refresh_anim(t_jeu *jeu);
void			display_steps(t_jeu *jeu);

// Mouvements

void			move_up(t_jeu *jeu);
void			move_down(t_jeu *jeu);
void			move_to_the_left(t_jeu *jeu);
void			move_to_the_right(t_jeu *jeu);
int				inputs(int code_touche, t_jeu *jeu);

// Destruction des images

void			destroy_images(t_jeu *jeu);
void			destroy_hero(t_jeu *jeu);
void			destroy_bad_guy(t_jeu *jeu);
void			destroy_spawn(t_jeu *jeu);
void			destroy_collectible(t_jeu *jeu);

// fermeture du jeu

int				close_game(t_jeu *jeu);
void			exit_game(t_jeu *jeu, int outcome);

#endif