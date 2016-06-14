/*
** connect.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Mon Jun 13 17:55:42 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "resources.h"

int					enter_game(t_infos *infos)
{
  char					s[4096];
  ssize_t				i;

  i = read(infos->socket, s, 4096);
  s[i - 1] = 0;
  if (strcmp(s, "BIENVENUE") == 0)
  {
    write(infos->socket, infos->client->team_name, strlen(infos->client->team_name));
    write(infos->socket, "\n", 1);
    i = read(infos->socket, s, 4096);
    s[i - 1] = 0;
    if (atoi(s) > 0)
    {
      i = read(infos->socket, s, 4096);
      s[i - 1] = 0;
      if (get_world_size(infos, s) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      if (create_map(infos) == RETURN_FAILURE)
	return (RETURN_FAILURE);
    }
      return (RETURN_SUCCESS);
  }
  return (RETURN_FAILURE);
}

int					get_world_size(t_infos *infos, char *s)
{
  char					x[2048];
  char					y[2048];
  int					i;
  int					j;

  /* MOOOCHE TODO */
  i = 0;
  while (s[i] && s[i] != ' ')
  {
    x[i] = s[i];
    i++;
  }
  x[i] = 0;
  if (s[i] == 0)
    return (RETURN_FAILURE);
  i++;
  j = 0;
  while (s[i + j])
  {
    y[j] = s[i + j];
    j++;
  }
  y[j] = 0;
  infos->map->x = atoi(x);
  infos->map->y = atoi(y);
  infos->client->x = 0;
  infos->client->y = 0;
  infos->client->level = 1;
  return (RETURN_SUCCESS);
}

int					init_connection(t_infos *infos)
{
  if ((infos->socket = socket(AF_INET, SOCK_STREAM, getprotobyname("tcp")->p_proto)) < 0)
    return (RETURN_FAILURE);
  if (connect(infos->socket, (struct sockaddr *) &(infos->in), sizeof(infos->in)) < 0)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
