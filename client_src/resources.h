/*
** resources.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 10 16:59:26 2016 Erwan Dupard
** Last update Mon Jun 13 17:17:32 2016 Gabriel Goude
*/

#ifndef RESOURCES_H_
# define RESOURCES_H_

# define RETURN_SUCCESS			(0)
# define RETURN_FAILURE			(-1)

# include <netinet/ip.h>

typedef enum
{
  FOOD					= 0,
  LINEMATE				= 1,
  DERAUMERE				= 2,
  SIBUR					= 3,
  MENDIANE				= 4,
  PHIRAS				= 5,
  THYSTAME				= 6,
  NUMBER_OF_TYPES			= 7
}					e_object_type;

typedef unsigned int			t_quantity;

typedef struct				s_map
{
  t_quantity				obj[NUMBER_OF_TYPES];
  int					players;
}					t_map;

typedef struct				s_game
{
  int					world_x;
  int					world_y;
  int					world_size;
  int					pos_x;
  int					pos_y;
  t_map					*map;
  int					lvl;
  t_quantity				inv[NUMBER_OF_TYPES];
}					t_game;

typedef struct				s_client_settings
{
  char					*team_name;
  struct sockaddr_in			sock;
  int					s;

}					t_client_settings;

/*
** map.c
*/
t_map					*create_map(t_game *game);
void					init_map(t_map *map, t_game *game);

/*
** ai.c
*/
int					ai(t_client_settings *settings, t_game *game);

/*
** connect.c
*/
int					init_connection(t_client_settings *settings);
int					enter_game(t_client_settings *settings, t_game *game);
int					get_world_size(t_game *game, char *s);
void					init_inv(t_game *game);

/*
** parser.c
*/
int					get_param(int ac, char **av, t_client_settings *settings);
int					get_next_param(int i, char **av, t_client_settings *settings);

#endif /* ! RESOURCES_H_ */
