/*
** request2.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 16:02:31 2016 Gabriel Goude
** Last update Mon Jun 13 17:54:31 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "resources.h"

int					prend(t_infos *infos, char *obj)
{
  char					*str;
  int					len;

  len = strlen(obj);
  if ((str = malloc(sizeof(char) * (7 + len))) == NULL)
    return (RETURN_FAILURE);
  strcpy(str, "prend ");
  strcpy(str + 6, obj);
  str[6 + len] = '\n';
  write(infos->socket, str, 7 + len);
  free(str);
  return (RETURN_SUCCESS);
}

int					pose(t_infos *infos, char *obj)
{
  char					*str;
  int					len;

  len = strlen(obj);
  if ((str = malloc(sizeof(char) * (6 + len))) == NULL)
    return (RETURN_FAILURE);
  strcpy(str, "pose ");
  strcpy(str + 5, obj);
  str[5 + len] = '\n';
  write(infos->socket, str, 6 + len);
  free(str);
  return (RETURN_SUCCESS);
}

int					expulse(t_infos *infos)
{
  write(infos->socket, "expulse\n", 8);
  return (RETURN_SUCCESS);
}

int					broadcast(t_infos *infos, char *text)
{
  char					*str;
  int					len;

  len = strlen(text);
  if ((str = malloc(sizeof(char) * (11 + len))) == NULL)
    return (RETURN_FAILURE);
  strcpy(str, "broadcast ");
  strcpy(str + 10, text);
  str[10 + len] = '\n';
  write(infos->socket, str, 11 + len);
  free(str);
  return (RETURN_SUCCESS);
}

int					incantation(t_infos *infos)
{
  write(infos->socket, "incantation\n", 12);
  return (RETURN_SUCCESS);
}
