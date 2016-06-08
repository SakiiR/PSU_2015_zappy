/*
** request2.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 16:02:31 2016 Gabriel Goude
** Last update Wed Jun 08 16:14:37 2016 Gabriel Goude
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
