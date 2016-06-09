/*
** get_next_line.c for get_next_line in /home/billot_t/rendu/SBMLparser
** 
** Made by Thomas Billot
** Login   <billot_t@epitech.net>
** 
** Started on  Mon Jun 15 13:21:49 2015 Thomas Billot
** Last update Tue May 10 18:06:03 2016 Thomas Billot
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "myftp.h"

char		*add_char(char **str, const int l, const char c)
{
  char		*result;
  int		i;

  if ((result = malloc(sizeof(char*) * (l + 1))) != NULL)
  {
    i = -1;
    while (++i < l)
      result[i] = (*str)[i];
    result[i] = c;
    free(*str);
    *str = result;
    return (result);
  }
  fprintf(stderr, "Error: malloc in get_next_line() failed\n");
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFF_SIZE];
  char		*tmp;
  int		l;
  int		i;

  l = 0;
  tmp = NULL;
  while (buffer[0] != '\n')
  {
    if (buffer[0] == '\0')
      if (read(fd, buffer, BUFF_SIZE) <= 0)
	return (tmp);
    if (add_char(&tmp, l++, buffer[0]) == NULL)
      return (NULL);
    i = -1;
    while (++i < BUFF_SIZE - 1)
      buffer[i] = buffer[i + 1];
    buffer[i] = 0;
  }
  i = -1;
  while (++i < BUFF_SIZE - 1)
    buffer[i] = buffer[i + 1];
  buffer[i] = 0;
  add_char(&tmp, l++, 0);
  return (tmp);
}
