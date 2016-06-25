/*
** connect.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Sat Jun 25 19:10:42 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/select.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "resources.h"

int					enter_game(t_infos *infos)
{
  char					*msg;

  if ((msg = read_buf(infos)) == NULL)
    return (RETURN_FAILURE);
  if (strcmp(msg, "BIENVENUE\n") == 0)
  {
    free(msg);
    if (write_buf(infos, infos->client->team_name) == RETURN_FAILURE ||
	send_update(infos) == RETURN_FAILURE)
      return (RETURN_FAILURE);
    if ((msg = read_buf(infos)) == NULL)
      return (RETURN_FAILURE);
    if (atoi(msg) > 0)
    {
      free(msg);
      msg = read_buf(infos);
      if (msg == NULL || get_world_size(infos, msg) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      free(msg);
      if (create_map(infos) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      return (RETURN_SUCCESS);
    }
  }
  return (RETURN_FAILURE);
}

int					get_world_size(t_infos *infos, char *s)
{
  char					x[2048];
  char					y[2048];
  int					i;
  int					j;

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
  init_pos(infos, atoi(x), atoi(y));
  return (RETURN_SUCCESS);
}

void					init_pos(t_infos *infos, int x, int y)
{
  infos->map->x = x;
  infos->map->y = y;
  infos->client->x = 0;
  infos->client->y = 0;
  infos->client->level = 1;
  infos->client->alive = 1;
  infos->client->orientation = 0;
}

int					init_connection(t_infos *infos)
{
  if ((infos->socket = socket(AF_INET,
			      SOCK_STREAM,
			      getprotobyname("tcp")->p_proto)) < 0)
    return (RETURN_FAILURE);
  if (connect(infos->socket,
	      (struct sockaddr *) &(infos->in),
	      sizeof(infos->in)) < 0)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
