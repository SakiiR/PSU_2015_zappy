/*
** fct_sgt.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:47:53 2016 Thomas Billot
** Last update Sat Jun 25 19:25:43 2016 Thomas Beaudet
*/

#include <stdlib.h>
#include <stdio.h>
#include "../graphical.h"

int		fct_sgt(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  map->time_u = atoi(cmd[1]);
  printf("%d\n", map->time_u);
  return (RETURN_SUCCESS);
}
