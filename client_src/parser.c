/*
** parser.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Mon Jun 13 16:47:36 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "resources.h"

int			get_param(int ac, char **av, t_client_settings *settings)
{
  int			i;

  i = 1;
  if (ac != 7)
    return (RETURN_FAILURE);
  settings->sock.sin_family = AF_INET;
  while (i < 6)
  {
    if (i % 2)
    {
      if (get_next_param(i, av, settings) == RETURN_FAILURE)
	return (RETURN_FAILURE);
    }
    i++;
  }
  return (RETURN_SUCCESS);
}

int			get_next_param(int i, char **av, t_client_settings *settings)
{
  if (strcmp(av[i], "-n") == 0)
    settings->team_name = av[i + 1];
  else if (strcmp(av[i], "-p") == 0)
    settings->sock.sin_port = htons(atoi(av[i + 1]));
  else if (strcmp(av[i], "-h") == 0)
  {
    if (strcmp(av[i + 1], "localhost") == 0)
    {
      if (inet_pton(AF_INET,  "127.0.0.1", &(settings->sock.sin_addr)) != 1)
	return (RETURN_FAILURE);
    }
    else
    {
      if (inet_pton(AF_INET, av[i + 1], &(settings->sock.sin_addr)) != 1)
	return (RETURN_FAILURE);
    }
  }
  else
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
