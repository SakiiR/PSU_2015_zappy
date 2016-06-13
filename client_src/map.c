/*
** map.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 10 18:35:00 2016 Gabriel Goude
** Last update Mon Jun 13 17:01:21 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <stdio.h>
#include "resources.h"

t_map			*create_map(t_game *game)
{
  t_map			*map;

  if ((map = malloc(sizeof(t_map) * (game->world_size))) == NULL)
    return (NULL);
  init_map(map, game);
  game->map = map;
  printf("done\n");
  return (map);
}

void			init_map(t_map *map, t_game *game)
{
  int			i;

  i = 0;
  while (i < game->world_x * game->world_y)
  {
    map->obj[FOOD] = 0;
    map->obj[LINEMATE] = 0;
    map->obj[DERAUMERE] = 0;
    map->obj[SIBUR] = 0;
    map->obj[MENDIANE] = 0;
    map->obj[PHIRAS] = 0;
    map->obj[THYSTAME] = 0;
    map->players = 0;
    i++;
  }
}
