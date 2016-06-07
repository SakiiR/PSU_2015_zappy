/*
** server.h for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jun  7 16:22:59 2016 Barthelemy Gouby
** Last update Tue Jun  7 16:58:58 2016 Barthelemy Gouby
*/

#ifndef _SERVER_H_
# define _SERVER_H_

enum object_type
  {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  };

typedef struct		s_object
{
  object_type		type;
  unsigned int		quantity;
}			t_object;

typedef struct		s_player
{
  unsigned int		level;
  char			*team;
  t_object		objects[7];
}			t_player;

typedef struct		s_case
{
  t_player		*players;
  t_objects		objects[7];
}			t_case;

#endif /* !_SERVER_H_ */
