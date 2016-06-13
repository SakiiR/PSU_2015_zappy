/*
** main.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Mon Jun 13 17:51:12 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "resources.h"

int			main(int ac, char **av)
{
  t_infos		infos;
  t_map			map;
  t_client		client;

  infos.client = &client;
  infos.map = &map;
  if (get_param(ac, av, &infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (init_connection(&infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (enter_game(&infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (ai(&infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
