/*
** fct_pdi.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:41:17 2016 Thomas Billot
** Last update Sat Jun 25 15:42:54 2016 Thomas Billot
*/

#include <stdlib.h>
#include <stdio.h>
#include "../graphical.h"

int		fct_pdi(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  t_character	*drone;

  if ((drone = get_player_by_id(map, (t_u64)atoi(cmd[1]))) == NULL)
    return (-1);
  drone->status = DEAD;
  return (0);
}
