/*
** map.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 10 18:35:00 2016 Gabriel Goude
** Last update Sun Jun 12 17:16:33 2016 Erwan Dupard
*/

#include <stdlib.h>
#include "resources.h"

t_map			**create_map(t_game *game)
{
  t_map			**map;
  int			i;

  i = 0;
  if ((map = malloc(sizeof(*map) * game->world_x)) == NULL)
    return (NULL);
  while (i < game->world_y)
    {
      if ((map[i] = malloc(sizeof(**map) * game->world_y)) == NULL)
	return (NULL);
      init_map(&map[i]);
      i++;
    }
  return (map);
}

void			init_map(t_map *map)
{
  map->food = 0;
  map->linemate = 0;
  map->deraumere = 0;
  map->sibur = 0;
  map->mendiane = 0;
  map->phiras = 0;
  map->thystame = 0;
}
