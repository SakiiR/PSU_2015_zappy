/*
** server.h for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jun  7 16:22:59 2016 Barthelemy Gouby
// Last update Tue Jun  7 17:31:01 2016 Barthelemy Gouby
*/

#ifndef _SERVER_H_
# define _SERVER_H_

enum			object_type
  {
    FOOD		= 0,
    LINEMATE		= 1,
    DERAUMERE		= 2,
    SIBUR		= 3,
    MENDIANE		= 4,
    PHIRAS		= 5,
    THYSTAME		= 6,
    NUMBER_OF_TYPES	= 7
  };

typedef unsigned int	quantity;

typedef struct		s_player
{
  unsigned int		level;
  char			*team;
  quantity		quantities[NUMBER_OF_TYPES];
  unsigned int		orientation;
}			t_player;

typedef struct		s_case
{
  t_player		*players;
  quantity		quantities[NUMBER_OF_TYPES];
}			t_case;

typedef struct		s_map
{
  t_case		*cases;
  unsigned int		width;
  unsigned int		height;
}			t_map;

t_map			*initialize_map(const unsigned int width, const unsigned int height);
t_case			*map_get_case_at(const unsigned int x, const unsigned int y, const t_map *map);


#endif /* !_SERVER_H_ */
