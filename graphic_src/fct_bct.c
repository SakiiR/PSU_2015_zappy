/*
** fct_bct.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 13:51:36 2016 Thomas Billot
** Last update Thu Jun 16 19:19:22 2016 Thomas Beaudet
*/

#include <stdlib.h>
#include <stdio.h>
#include "graphical.h"

int		fct_bct(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  int		i;
  int		x;
  int		y;

  i = 0;
  printf("fct_%s args:", cmd[i]);
  while (cmd[++i])
    printf(" %s |", cmd[i]);
  printf("\n");
  y = atoi(cmd[1]);
  x = atoi(cmd[2]);
  map->tiles[(x * y)].obj[FOOD] = atoi(cmd[3]);
  map->tiles[(x * y)].obj[LINEMATE] = atoi(cmd[4]);
  map->tiles[(x * y)].obj[DERAUMERE] = atoi(cmd[5]);
  map->tiles[(x * y)].obj[SIBUR] = atoi(cmd[6]);
  map->tiles[(x * y)].obj[MENDIANE] = atoi(cmd[7]);
  map->tiles[(x * y)].obj[PHIRAS] = atoi(cmd[8]);
  map->tiles[(x * y)].obj[THYSTAME] = atoi(cmd[9]);
  i = -1;
  while (++i < NUMBER_OF_TYPES)
    {
      printf("obj[%d]: %d\n", i, map->tiles[(x * y)].obj[i]);
    }
  return (0);
}
