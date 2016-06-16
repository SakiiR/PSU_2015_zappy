/*
** fct_pic.c for PSU_2015_zappy in /home/mikaz3
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun 16 14:29:28 2016 Thomas Billot
** Last update Thu Jun 16 14:46:19 2016 Thomas Billot
*/

#include <stdlib.h>
#include <stdio.h>
#include "graphical.h"

int		fct_pic(t_map *map,
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
