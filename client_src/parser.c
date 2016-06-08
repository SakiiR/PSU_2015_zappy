/*
** parser.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Wed Jun 08 13:19:58 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "drone.h"

int			get_param(int ac, char **av, t_client_settings *settings)
{
  int			i;

  i = 1;
  if (ac != 7)
    return (EXIT_FAILURE);
  while (i < 6)
  {
    if (i % 2 == 1)
      get_next_param(i, av, settings);
  }
  return (EXIT_SUCCESS);
}

int			get_next_param(int i, char **av, t_client_settings *settings)
{
  if (strcmp(av[i], "-n") == 0)
    settings->team_name = av[i + 1];
  else if (strcmp(av[i], "-p") == 0)
    settings->sock.sin_port = atoi(av[i + 1]);
  else if (strcmp(av[i], "-h") == 0)
  {
    if (strcmp(av[i + 1], "localhost") == 0)
    {
      if (inet_pton(AF_INET,  "127.0.0.1", &(settings->sock.sin_addr)) != 1)
	return (EXIT_FAILURE);
    }
    else
    {
      if (inet_pton(AF_INET, av[i + 1], &(settings->sock.sin_addr)) != 1)
	return (EXIT_FAILURE);
    }
  }
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
