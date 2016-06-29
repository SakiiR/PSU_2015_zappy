/*
** fct_pgt.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:46:08 2016 Thomas Billot
** Last update Sun Jun 26 11:39:11 2016 Thomas Beaudet
*/

#include <stdlib.h>
#include <stdio.h>
#include "../graphical.h"

int		fct_pgt(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  t_character	*drone;
  int		i;

  i = atoi(cmd[2]);
  if ((drone = get_player_by_id(map, (t_u64)atoi(cmd[1]))) == NULL)
    return (RETURN_FAILURE);
  drone->inventory[i] += 1;
  return (0);
}
