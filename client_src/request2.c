/*
** request2.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 16:02:31 2016 Gabriel Goude
** Last update Wed Jun 08 16:24:37 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "drone.h"

int			prend(t_client_settings *settings, char *obj)
{
  char			*str;
  int			len;

  len = strlen(obj);
  if ((str = malloc(sizeof(char) * (7 + len))) == NULL)
    return (EXIT_FAILURE);
  strcpy(str, "prend ");
  strcpy(str + 6, obj);
  str[6 + len] = '\n';
  write(settings->s, str, 7 + len);
  free(str);
  return (EXIT_SUCCESS);
}

int			pose(t_client_settings *settings, char *obj)
{
  char			*str;
  int			len;

  len = strlen(obj);
  if ((str = malloc(sizeof(char) * (6 + len))) == NULL)
    return (EXIT_FAILURE);
  strcpy(str, "pose ");
  strcpy(str + 5, obj);
  str[5 + len] = '\n';
  write(settings->s, str, 6 + len);
  free(str);
  return (EXIT_SUCCESS);
}

int			expulse(t_client_settings *settings)
{
  write(settings->s, "expulse\n", 8);
  return (EXIT_SUCCESS);
}

int			broadcast(t_client_settings *settings, char *text)
{
  char			*str;
  int			len;

  len = strlen(text);
  if ((str = malloc(sizeof(char) * (11 + len))) == NULL)
    return (EXIT_FAILURE);
  strcpy(str, "broadcast ");
  strcpy(str + 10, text);
  str[10 + len] = '\n';
  write(settings->s, str, 11 + len);
  free(str);
  return (EXIT_SUCCESS);
}

int			incantation(t_client_settings *settings)
{
  write(settings->s, "incantation\n", 12);
  return (EXIT_SUCCESS);
}
