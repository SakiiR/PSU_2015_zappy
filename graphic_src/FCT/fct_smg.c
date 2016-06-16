/*
** fct_smg.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:48:14 2016 Thomas Billot
** Last update Thu Jun 16 17:23:27 2016 Thomas Beaudet
*/

#include <stdlib.h>
#include <stdio.h>
#include "../graphical.h"

int		fct_smg(t_map *map,
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
