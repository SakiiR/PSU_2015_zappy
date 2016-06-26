/*
** resources.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 10 16:59:26 2016 Erwan Dupard
** Last update Sun Jun 26 17:18:11 2016 Erwan Dupard
*/

#ifndef RESOURCES_H_
# define RESOURCES_H_

# define RETURN_SUCCESS			(0)
# define RETURN_FAILURE			(-1)

# include <netinet/ip.h>
# include <sys/times.h>
# include <sys/select.h>
# include <circular_buffer/circular_buffer.h>

typedef enum
  {
    FOOD				= 0,
    LINEMATE				= 1,
    DERAUMERE				= 2,
    SIBUR				= 3,
    MENDIANE				= 4,
    PHIRAS				= 5,
    THYSTAME				= 6,
    NUMBER_OF_TYPES			= 7
  }					e_object_type;

typedef enum
  {
    AVANCE				= 0,
    DROITE				= 1,
    GAUCHE				= 2,
    VOIR				= 3,
    INVENTAIRE				= 4,
    PREND				= 5,
    POSE				= 6,
    EXPULSE				= 7,
    BROADCAST				= 8,
    INCANTATION				= 9,
    CONNECT_NBR				= 10,
    NUMBER_OF_REQUESTS			= 11
  }					e_request_type;

typedef struct				s_request
{
  int					request;
  struct s_request			*next;
}					t_request;

typedef unsigned int			t_quantity;

typedef struct				s_select
{
  fd_set				rfds;
  fd_set				wfds;
  struct timeval			tv;
}					t_select;

typedef struct				s_infos
{
  struct s_client			*client;
  struct s_map				*map;
  struct s_request			*request;
  struct sockaddr_in			in;
  struct s_select			select;
  t_circular_buffer			buffer;
  int					socket;
}					t_infos;

typedef struct				s_client
{
  unsigned int				x;
  unsigned int				y;
  char					*team_name;
  t_quantity				inventory[NUMBER_OF_TYPES];
  unsigned int				level;
  int					orientation;
  unsigned int				alive;
}					t_client;

typedef struct				s_tile
{
  t_quantity				obj[NUMBER_OF_TYPES];
  unsigned int				players;
}					t_tile;

typedef struct				s_map
{
  unsigned int				x;
  unsigned int				y;
  t_tile				*tiles;
}					t_map;

/*
** main.c
*/
int					init_client(int ac,
						    char **av,
						    t_infos *infos);
int					play_loop(t_infos *infos);
void					init_fct(int (**fct)(t_infos *, char *));

/*
** handle.c
*/
int					handle_msg(t_infos *infos,
						   char *msg,
						   int (**fct)(t_infos *, char *));

/*
** update.c
*/
int					update(t_infos *infos,
					       int (**fct)(t_infos *, char *));
int					send_update(t_infos *infos);

/*
** buf.c
*/
char					*read_buf(t_infos *infos);
int					write_buf(t_infos *infos,
						  char *str);
void					fill_set(t_infos *infos);

/*
** map.c
*/
int					create_map(t_infos *infos);
void					init_map(t_map *map);

/*
** ai.c
*/
int					ai(t_infos *infos);

/*
** connect.c
*/
int					init_connection(t_infos *infos);
int					enter_game(t_infos *infos);
int					get_world_size(t_infos *infos, char *s);
void					init_pos(t_infos *infos, int x, int y);
void					init_inv(t_infos *infos);

/*
** parser.c
*/
int					get_param(int ac, char **av, t_infos *infos);
int					get_next_param(int i, char **av, t_infos *infos);

/*
** list_fct.c
*/
int					add_elem(t_infos *infos, int id);
int					remove_elem(t_infos *infos);

/*
** handle1.c
*/
int					handle_avance(t_infos *infos, char *msg);
int					handle_droite(t_infos *infos, char *msg);
int					handle_gauche(t_infos *infos, char *msg);
int					handle_voir(t_infos *infos, char *msg);
int					handle_inventaire(t_infos *infos, char *msg);

/*
** handle2.c
*/
int					handle_prend(t_infos *infos, char *msg);
int					handle_pose(t_infos *infos, char *msg);
int					handle_expulse(t_infos *infos, char *msg);
int					handle_broadcast(t_infos *infos, char *msg);
int					handle_incantation(t_infos *infos, char *msg);

int					prend(t_infos *infos, char *str);
int					voir(t_infos *infos);
int					inventaire(t_infos *infos);
int					avance(t_infos *infos);
int					gauche(t_infos *infos);


/*
** handle3.c
*/
int					handle_connect_nbr(t_infos *infos, char *msg);

#endif /* ! RESOURCES_H_ */
