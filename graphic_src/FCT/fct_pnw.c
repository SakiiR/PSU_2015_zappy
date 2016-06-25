/*
** fct_pnw.c for PSU_2015_zappy in /home/mikaz3
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:25:33 2016 Thomas Billot
** Last update Sat Jun 25 17:42:06 2016 Thomas Billot
*/

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "../xfunc.h"
#include "../graphical.h"

t_character	*create_new_player(int id,
				   int orentation,
				   int level,
				   char *team)
{
  t_character	*new;
  int		i;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->id = (t_u64)id;
  new->status = ALIVE;
  if (orentation >= 0 && orentation <= 4)
    new->orientation = (e_orientation)orentation;
  new->level = level;
  if (team == NULL)
    return (NULL);
  if ((new->team = my_strdup(team)) == NULL)
    return (NULL);
  i = -1;
  while (++i < NUMBER_OF_TYPES)
    new->inventory[i] = 0;
  new->next_in_case = NULL;
  new->texture = CHARACTER;
  return (new);
}

int		fct_pnw(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  int		x;
  int		y;
  t_character	*new;
  t_character	*current;

  x = atoi(cmd[2]);
  y = atoi(cmd[3]);
  if ((map->x * map->y) < (x * y))
    return (RETURN_FAILURE);
  if ((new = create_new_player(atoi(cmd[1]),
			       atoi(cmd[4]),
			       atoi(cmd[5]),
			       cmd[6])) == NULL)
    return (RETURN_FAILURE);
  current = map->tiles[(x * y)].characters;
  map->tiles[(x * y)].players += 1;
  while (current->next_in_case != NULL)
    current = current->next_in_case;
  current->next_in_case = new;
  new->prev_in_case = current;
  return (RETURN_SUCCESS);
}
