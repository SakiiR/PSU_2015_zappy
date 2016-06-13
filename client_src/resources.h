/*
** resources.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 10 16:59:26 2016 Erwan Dupard
** Last update Mon Jun 13 17:55:22 2016 Gabriel Goude
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

typedef struct				s_infos
{
  struct s_client			*client;
  struct s_map				*map;
  struct sockaddr_in			in;
  int					socket;
}					t_infos;

typedef struct				s_client
{
  unsigned int				x;
  unsigned int				y;
  char					*team_name;
  t_quantity			        inventory[NUMBER_OF_TYPES];
  unsigned int				level;
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
** map.c
*/
int					create_map(t_infos *infos);
void					init_map(t_infos *infos);

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
void					init_inv(t_infos *infos);

/*
** parser.c
*/
int					get_param(int ac, char **av, t_infos *infos);
int					get_next_param(int i, char **av, t_infos *infos);

#endif /* ! RESOURCES_H_ */
