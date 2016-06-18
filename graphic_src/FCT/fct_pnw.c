/*
** fct_pnw.c for PSU_2015_zappy in /home/mikaz3
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:25:33 2016 Thomas Billot
** Last update Sat Jun 18 16:13:50 2016 Thomas Billot
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

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->id = id;
  if (orentation >= 0 && orentation <= 4)
    new->orientation = (e_orientation)orentation;
  new->level = level;
  if (team == NULL)
    return (NULL);
  if ((new->team = my_strdup(team)) == NULL)
    return (NULL);
  new->next_in_case = NULL;
  return (new);
}

int		fct_pnw(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  /* DEBUG */
  int		i;
  /**/
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
  
  /* DEBUG DOESNT COUNT ON 25 LINES */
  i = 0;
  printf("fct_%s args:", cmd[i]);
  while (cmd[++i])
    printf(" %s |", cmd[i]);
  printf("\n");
  return (0);
}
