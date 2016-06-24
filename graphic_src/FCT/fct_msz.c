/*
** fct_msz.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Wed Jun 15 14:14:15 2016 Thomas Billot
** Last update Fri Jun 24 15:48:35 2016 Thomas Beaudet
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

int		generate_map(t_map *map)
{
  t_tile	*new;
  int		i;

  if ((new = malloc(sizeof(*new) * (map->x * map->y))) == NULL)
    return (RETURN_FAILURE);
  map->tiles = new;
  i = -1;
  while (++i < (map->y * map->x))
    {
      if ((map->tiles[i].characters = init_characters()) == NULL)
	return (RETURN_FAILURE);
      map->tiles[i].players = 0;
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
