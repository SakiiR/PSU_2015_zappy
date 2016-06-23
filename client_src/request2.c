/*
** request2.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 16:02:31 2016 Gabriel Goude
** Last update Wed Jun 22 16:10:45 2016 Erwan Dupard
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
  str[6 + len] = 0;
  write_buf(infos, str);
  free(str);
  add_elem(infos, PREND);
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
  str[5 + len] = 0;
  write_buf(infos, str);
  free(str);
  add_elem(infos, POSE);
  return (RETURN_SUCCESS);
}

int					expulse(t_infos *infos)
{
  write_buf(infos, "expulse");
  add_elem(infos, EXPULSE);
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
  str[10 + len] = 0;
  write_buf(infos, str);
  free(str);
  add_elem(infos, BROADCAST);
  return (RETURN_SUCCESS);
}

int					incantation(t_infos *infos)
{
  write_buf(infos, "incantation");
  add_elem(infos, INCANTATION);
  return (RETURN_SUCCESS);
}
