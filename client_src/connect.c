/*
** connect.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Fri Jun 10 17:06:55 2016 Erwan Dupard
*/

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "resources.h"

int					enter_game(t_client_settings *settings, t_game *game)
{
  char					s[4096];
  ssize_t				i;

  i = read(settings->s, s, 4096);
  s[i - 1] = 0;
  if (strcmp(s, "BIENVENUE") == 0)
  {
    write(settings->s, settings->team_name, strlen(settings->team_name));
    write(settings->s, "\n", 1);
    i = read(settings->s, s, 4096);
    s[i - 1] = 0;
    if (atoi(s) > 0)
    {
      i = read(settings->s, s, 4096);
      s[i - 1] = 0;
      if (get_world_size(game, s) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      return (RETURN_SUCCESS);
    }
      return (RETURN_SUCCESS);
  }
  return (RETURN_FAILURE);
}

int					get_world_size(t_game *game, char *s)
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
  game->world_x = atoi(x);
  game->world_y = atoi(y);
  init_inv(game);
  return (RETURN_SUCCESS);
}

void					init_inv(t_game *game)
{
  game->inv.food = 0;
  game->inv.linemate = 0;
  game->inv.deraumere = 0;
  game->inv.sibur = 0;
  game->inv.mendiane = 0;
  game->inv.phiras = 0;
  game->inv.thystame = 0;
}

int					init_connection(t_client_settings *settings)
{
  if ((settings->s = socket(AF_INET, SOCK_STREAM, getprotobyname("tcp")->p_proto)) < 0)
    return (RETURN_FAILURE);
  if (connect(settings->s, (struct sockaddr *) &(settings->sock), sizeof(settings->sock)) < 0)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
