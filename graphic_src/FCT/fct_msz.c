/*
** fct_msz.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Wed Jun 15 14:14:15 2016 Thomas Billot
** Last update Mon Jun 20 13:57:16 2016 Erwan Dupard
*/

#include <stdlib.h>
#include <stdio.h>
#include "../graphical.h"

t_character	*init_characters(void)
{
  t_character	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->id = -1;
  new->level = 0;
  new->orientation = NORTH;
  new->team = NULL;
  new->next_in_case = NULL;
  return (new);
}

void		init_obj(t_quantity *obj)
{
  int		i;

  i = -1;
  while (obj[++i])
    obj[i] = 0;
}

int		generate_map(t_map *map)
{
  t_tile	*new;
  int		x;
  int		y;

  if ((new = malloc(sizeof(*new) * (map->x * map->y))) == NULL)
    return (RETURN_FAILURE);
  map->tiles = new;
  y = -1;
  while (++y <= map->y)
    {
      x = -1;
      while (x++ <= map->x)
	{
	  if ((map->tiles[(x * y)].characters = init_characters()) == NULL)
	    return (RETURN_FAILURE);
	  init_obj(map->tiles[(x * y)].obj);
	  map->tiles[(x * y)].players = 0;
	}
    }
  return (RETURN_SUCCESS);
}

int		fct_msz(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  int		i;

  i = 0;
  if (map)
    {
      map->x = atoi(cmd[1]);
      map->y = atoi(cmd[2]);
      if (generate_map(map) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      printf("fct_%s args:", cmd[i]);
      while (cmd[++i])
	printf(" %s |", cmd[i]);
      printf("\n");
      return (RETURN_SUCCESS);
    }
  return (RETURN_FAILURE);
}
