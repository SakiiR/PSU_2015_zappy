/*
** fct_pgt.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:46:08 2016 Thomas Billot
** Last update Mon Jun 20 15:05:27 2016 Thomas Billot
*/

#include <stdlib.h>
#include <stdio.h>
#include "../graphical.h"

int		fct_pgt(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  int		i;

  i = 0;
  get_player_by_id(map, 3);
  printf("fct_%s args:", cmd[i]);
  while (cmd[++i])
    printf(" %s |", cmd[i]);
  printf("\n");
  return (0);
}
