/*
** fct_plv.c for PSU_2015_zappy in /home/mikaz3
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:27:39 2016 Thomas Billot
** Last update Sun Jun 26 20:44:23 2016 Karine Aknin
*/

#include <stdlib.h>
#include <stdio.h>
#include "../graphical.h"

int		fct_plv(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  int		i;

  (void)map;
  i = 0;
  printf("fct_%s args:", cmd[i]);
  while (cmd[++i])
    printf(" %s |", cmd[i]);
  printf("\n");
  return (0);
}
