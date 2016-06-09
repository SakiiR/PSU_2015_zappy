/*
** main.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Thu Jun 09 16:29:21 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "drone.h"

int			main(int ac, char **av)
{
  t_client_settings	settings;
  t_game		game;

  if (get_param(ac, av, &settings) == EXIT_FAILURE)
    return (0);
  printf("param ok \n");
  if (init_connection(&settings) == EXIT_FAILURE)
    return (0);
  printf("connection ok \n");
  if (enter_game(&settings, &game) == EXIT_FAILURE)
    return (0);
  printf("enter ok \n");
  return (0);
}
