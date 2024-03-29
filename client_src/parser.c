/*
** parser.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Sun Jun 26 18:15:33 2016 Erwan Dupard
*/

#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "resources.h"

static void		usage()
{
  printf("Usage : ./zappy_ai -n team_name -p port -h host\n");
}

int			get_param(int ac, char **av, t_infos *infos)
{
  int			i;

  i = 1;
  if (ac != 7)
    return (RETURN_FAILURE);
  infos->in.sin_family = AF_INET;
  while (i < 6)
    {
      if (i % 2)
	{
	  if (get_next_param(i, av, infos) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
      i++;
    }
  return (RETURN_SUCCESS);
}

int			get_next_param(int i, char **av, t_infos *infos)
{
  if (strcmp(av[i], "-n") == 0)
    infos->client->team_name = av[i + 1];
  else if (strcmp(av[i], "-p") == 0)
    infos->in.sin_port = htons(atoi(av[i + 1]));
  else if (strcmp(av[i], "-h") == 0)
    {
      if (strcmp(av[i + 1], "localhost") == 0)
	{
	  if (inet_pton(AF_INET,  "127.0.0.1", &(infos->in.sin_addr)) != 1)
	    return (RETURN_FAILURE);
	}
      else
	{
	  if (inet_pton(AF_INET, av[i + 1], &(infos->in.sin_addr)) != 1)
	    return (RETURN_FAILURE);
	}
    }
  else
    {
      usage();
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}
