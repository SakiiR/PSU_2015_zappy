/*
** graphical.h for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun  9 14:43:41 2016 Thomas Billot
** Last update Tue Jun 21 13:52:05 2016 Thomas Billot
*/

#ifndef GRAPHICAL_H_
# define GRAPHICAL_H_

# include <circular_buffer/circular_buffer.h>
# include <arpa/inet.h>
# include <SDL2/SDL.h>
# include <stdint.h>

# define RETURN_SUCCESS		(0)
# define RETURN_FAILURE		(-1)

# define SOCKET_ERROR		(-1)
# define USAGE			"./console -h [host-ip] -p [host-port]\n"
# define MSZ			"msz" /* Taille de la carte */
# define BCT			"bct" /* Contenu de la carte */
# define TNA			"tna" /* Nom des équipes */
# define PNW			"pnw" /* Connexion d'un nouveau joueur */
# define PPO			"ppo" /* Position d'un joueur */
# define PLV			"plv" /* Niveau d'un joueur */
# define PIN			"pin" /* Inventaire d'un joueur */
# define PEX			"pex" /* Expluse un joueur */
# define PBC			"pbc" /* Un joueur fait un broadcast */
# define PIC			"pic" /* incantation sur cette case */
# define PIE			"pie" /* Fin d'incantation avec resultat (1 ou 0) */
# define PFK			"pfk" /* Le joueur pond un oeuf */
# define PDR			"pdr" /* Le joueur jete une ressource */
# define PGT			"pgt" /* Le joueur prends une ressource */
# define PDI			"pdi" /* Le joueur est mort de faim */
# define ENW			"enw" /* oeuf pondu sur la case par le joueur */
# define EHT			"eht" /* L'oeuf eclos */
# define EBO			"ebo" /* Un joueur s'est connecte pour l'oeuf */
# define EBI			"ebi" /* L'oeuf eclos est mort de faim */
# define SGT			"sgt" /* Demande l'unite de temps du serveur */
# define SEG			"seg" /* Fin du jeu, l'equipe donne gagne */
# define SMG			"smg" /* Message du serveur */
# define SUC			"suc" /* Commande du serveur */
# define SBP			"sbp" /* Mauvais parametres de commande */

# define BIENVENUE		"BIENVENUE" /* Message du serveur pour
					       initialisé le moniteur graphique */

# define TILE_W			(32)
# define TILE_H			(32)
# define WIN_X			(800)
# define WIN_Y			(600)

# define T_GRASS		"graphic_src/Media/back.bmp"
# define T_BORDER_DARK		"graphic_src/Media/border_back.bmp"
# define T_BORDER_LIGHT		"graphic_src/Media/border_side.bmp"

/*
** Simple Typedefs
*/

typedef unsigned int	       	t_u64;
typedef unsigned int		t_quantity;
typedef int			t_socket;
typedef struct sockaddr_in	t_sockaddr;
typedef struct in_addr		t_inaddr;
typedef struct protoent		t_protocol;

/*
** Networking
*/

typedef struct		       	s_server
{
  t_socket	       	       	socket;
  t_circular_buffer    		buffer_in;
  t_circular_buffer    		buffer_out;
}	       			t_server;

typedef struct			s_option
{
  char				*ip;
  int				port;
}				t_option;

/*
** Graphical related
*/

typedef enum
  {
    GRASS			= 0,
    BORDER_BLACK		= 1,
    BORDER_LIGHT		= 2,
    NUMBER_OF_TEXTURES		= 3
  }				e_textures;

typedef enum
  {
    NORTH		       	= 1,
    EAST		       	= 2,
    SOUTH		       	= 3,
    WEST		       	= 4
  }			       	e_orientation;

typedef enum
  {
    FOOD			= 0,
    LINEMATE			= 1,
    DERAUMERE			= 2,
    SIBUR			= 3,
    MENDIANE			= 4,
    PHIRAS			= 5,
    THYSTAME			= 6,
    NUMBER_OF_TYPES		= 7
  }				e_object_types;

typedef struct			s_character
{
  t_u64				level;
  t_u64			        id;
  char 				*team;
  t_quantity   			inventory[NUMBER_OF_TYPES];
  e_orientation		        orientation;
  struct s_character   		*next_in_case;
}			       	t_character;

typedef struct			s_tile
{
  t_character			*characters;
  t_quantity			obj[NUMBER_OF_TYPES];
  unsigned int			players;
}				t_tile;

typedef struct		       	s_map
{
  int				x;
  int				y;
  t_tile			*tiles;
}				t_map;

typedef struct			s_texture
{
  SDL_Surface			*bmps[NUMBER_OF_TEXTURES];
  SDL_Texture			*textures[NUMBER_OF_TEXTURES];
}				t_texture;

typedef struct			s_render
{
  SDL_Window			*screen;
  SDL_Renderer			*rend;
  SDL_Event			event;
  SDL_Rect			dest_rect;
  t_texture			tileset[NUMBER_OF_TEXTURES];
}				t_render;

/*
** Function declaration
*/

int				setup_networking(t_option *options);
int				launch_client(t_server *server, t_render *render);
t_character			*get_player_by_id(t_map *map, t_u64 id);
int				map_rendering(t_map *map);
SDL_Surface			*load_bmp(const char *file);
SDL_Texture			*create_texture(t_render *render, SDL_Surface *bmp);
int				preload_textures(t_render *render);

/*
** SDL functions declaration
*/

int				sdl_init();
void				draw_backg(t_render *ress);
void				put_delay(int delay);
int				sdl_create_win(t_render *ress/*, t_map *map*/);
int				sdl_event(t_render *ress);
void				sdl_quit();

/*
** Function pointer definition
*/

typedef struct			s_ptr
{
  const char			*id;
  int				(*f)(t_map *map, t_server *server, char **cmd);
}				t_ptr;

/*
** Functions pointer functions
*/

int				fct_welcome(t_map *map,
					    t_server *server,
					    char **cmd __attribute__((unused)));
int				fct_msz(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_tna(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_suc(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_smg(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_sgt(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_seg(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_sbp(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_ppo(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pnw(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_plv(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pin(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pie(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pic(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pgt(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pfk(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pex(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pdr(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pdi(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_pbc(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_enw(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_eht(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_ebi(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_bct(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);
int				fct_ebo(t_map *map,
					t_server *server __attribute__((unused)),
					char **cmd);

#endif /* !GRAPHICAL_H_ */
