/*
** main.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Mon Jun 13 16:53:36 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "resources.h"

int			main(int ac, char **av)
{
  t_client_settings	settings;
  t_game		game;

  if (get_param(ac, av, &settings) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (init_connection(&settings) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (enter_game(&settings, &game) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (ai(&settings, &game) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
