/*
** main.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Thu Jun 09 15:30:40 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "drone.h"

FILE			*fdopen(int fd, const char *mode);

int			main(int ac, char **av)
{
  t_client_settings	settings;
  t_game		game;

  if (get_param(ac, av, &settings) == EXIT_FAILURE)
    return (0);
  if (init_connection(&settings) == EXIT_FAILURE)
    return (0);
  if (enter_game(&settings, &game) == EXIT_FAILURE)
    return (0);
  return (0);
}

int			enter_game(t_client_settings *settings, t_game *game)
{
  char			s[4096];
  FILE			*fd;

  if ((fd = fdopen(settings->s, "r+")) == NULL)
    return (EXIT_FAILURE);
  if (fgets(s, 4096, fd) == NULL)
    return (EXIT_FAILURE);
  if (strcmp(s, "BIENVENUE") == 0)
  {
    /* CHEUMALARACE */
    strcpy(s, settings->team_name);
    s[strlen(settings->team_name)] = '\n';
    s[strlen(settings->team_name) + 1] = 0;
    fputs(s, fd);
    if (fgets(s, 4096, fd) == NULL)
      return (EXIT_FAILURE);
    if (atoi(s) > 0)
    {
      if (fgets(s, 4096, fd) == NULL)
	return (EXIT_SUCCESS);
      if (get_world_size(game, s) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      return (EXIT_SUCCESS);
    }
  }
  return (EXIT_FAILURE);
}

int			get_world_size(t_game *game, char *s)
{
  char			x[2048];
  char			y[2048];
  int			i;
  int			j;

  /* MOOOCHE TODO */
  i = 0;
  while (s[i] && s[i] != ' ')
  {
    x[i] = s[i];
    i++;
  }
  x[i] = 0;
  if (s[i] == 0)
    return (EXIT_FAILURE);
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
  return (EXIT_SUCCESS);
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
