/*
** fct_msz.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Wed Jun 15 14:14:15 2016 Thomas Billot
** Last update Thu Jun 16 16:37:33 2016 Thomas Billot
*/

#include <stdlib.h>
#include <stdio.h>
#include "graphical.h"

int		generate_map(t_map *map)
{
  t_tile	*new;

  if ((new = malloc(sizeof(*new) * (map->x * map->y))) == NULL)
    return (RETURN_FAILURE);
  map->tiles = new;
  return (RETURN_SUCESS);
}

int		fct_msz(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  int		i;

  i = 0;
  map->x = atoi(cmd[1]);
  map->y = atoi(cmd[2]);
  if (generate_map(map) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  printf("fct_%s args:", cmd[i]);
  while (cmd[++i])
    printf(" %s |", cmd[i]);
  printf("\n");
  return (RETURN_SUCESS);
}
