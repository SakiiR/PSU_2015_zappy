/*
** fct_msz.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Wed Jun 15 14:14:15 2016 Thomas Billot
** Last update Thu Jun 16 14:29:37 2016 Thomas Billot
*/

#include <stdlib.h>
#include <stdio.h>
#include "graphical.h"

int		fct_msz(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  (void)map;
  printf("map size = h: %d | l: %d\n", atoi(cmd[1]), atoi(cmd[2]));
  return (0);
}
