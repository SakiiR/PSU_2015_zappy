/*
** main.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Wed Jun 08 16:19:08 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <netdb.h>
#include "drone.h"

int			main(int ac, char **av)
{
  t_client_settings	settings;

  if (get_param(ac, av, &settings) == EXIT_FAILURE)
    return (0);
  if (init_connection(&settings) == EXIT_FAILURE)
    return (0);
  return (0);
}

int			init_connection(t_client_settings *settings)
{
  if ((settings->s = socket(AF_INET, SOCK_STREAM, getprotobyname("tcp")->p_proto)) < 0)
    return (EXIT_FAILURE);
  if (bind(settings->s, (struct sockaddr *) &(settings->sock), sizeof(settings->sock)) < 0)
    return (EXIT_FAILURE);
  if (connect(settings->s, (struct sockaddr *) &(settings->sock), sizeof(settings->sock)) < 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
