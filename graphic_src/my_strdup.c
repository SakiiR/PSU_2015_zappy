/*
** my_strdup.c for xfunc in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Sat Jun 18 14:22:58 2016 Thomas Billot
** Last update Sat Jun 18 17:23:40 2016 Thomas Billot
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "xfunc.h"

char		*my_strdup(char *str)
{
  char		*new;
  int		i;

  if (str == NULL ||
      (new = malloc(sizeof(*new) * strlen(str))) == NULL)
    {
      fprintf(stderr, "Error in my_strdup(): %s", strerror(errno));
      return (NULL);
    }
  i = -1;
  while (str[++i])
    new[i] = str[i];
  new[strlen(str)] = '\0';
  return (new);
}
