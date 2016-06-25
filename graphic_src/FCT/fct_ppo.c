/*
** fct_ppo.c for PSU_2015_zappy in /home/mikaz3
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:26:57 2016 Thomas Billot
** Last update Sat Jun 25 17:25:23 2016 Thomas Beaudet
*/

#include <stdlib.h>
#include <stdio.h>
#include "../graphical.h"

int		fct_ppo(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  /* int		i; */

  /* (void)map; */
  /* i = 0; */
  /* printf("fct_%s args:", cmd[i]); */
  /* while (cmd[++i]) */
  /*   printf(" %s |", cmd[i]); */
  /* printf("\n"); */
  /* return (0); */
  int		x;
  int		y;
  t_character	*drone;

  x = atoi(cmd[2]);
  y = atoi(cmd[3]);
  if ((drone = get_player_by_id(map, (t_u64)atoi(cmd[1]))) == NULL)
    return (RETURN_FAILURE);
  drone->orientation = atoi(cmd[4]);
  printf("%d\n", drone->orientation);
  return (RETURN_SUCCESS);
}
