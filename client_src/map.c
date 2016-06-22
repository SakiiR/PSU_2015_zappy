/*
** map.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 10 18:35:00 2016 Gabriel Goude
** Last update Wed Jun 22 16:12:15 2016 Erwan Dupard
*/

#include <stdlib.h>
#include <stdio.h>
#include "resources.h"

int					create_map(t_infos *infos)
{
  if ((infos->map->tiles = malloc(sizeof(t_tile) *
				  (infos->map->x *
				   infos->map->y + 1))) == NULL)
    return (RETURN_FAILURE);
  init_map(infos->map);
  return (RETURN_SUCCESS);
}

void					init_map(t_map *map)
{
  int					i;
  int					size;

  i = 0;
  size = map->x * map->y;
  while (i < size)
    {
      map->tiles[i].obj[FOOD] = 0;
      map->tiles[i].obj[LINEMATE] = 0;
      map->tiles[i].obj[DERAUMERE] = 0;
      map->tiles[i].obj[SIBUR] = 0;
      map->tiles[i].obj[MENDIANE] = 0;
      map->tiles[i].obj[PHIRAS] = 0;
      map->tiles[i].obj[THYSTAME] = 0;
      map->tiles[i].players = 0;
      i++;
    }
}
