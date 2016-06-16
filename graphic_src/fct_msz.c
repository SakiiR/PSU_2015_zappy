/*
** fct_msz.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Wed Jun 15 14:14:15 2016 Thomas Billot
** Last update Thu Jun 16 15:38:48 2016 Thomas Billot
*/

#include <stdlib.h>
#include <stdio.h>
#include "graphical.h"

int		fct_msz(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  int		i;
  
  i = 0;
  alloc_map
  printf("fct_%s args:", cmd[i]);
  while (cmd[++i])
    printf(" %s |", cmd[i]);
  printf("\n");
  return (0);
}
