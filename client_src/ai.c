/*
** ai.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 10 14:31:29 2016 Gabriel Goude
** Last update Fri Jun 17 15:54:59 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <circular_buffer/circular_buffer.h>
#include "resources.h"

int			prend(t_infos *infos, char *str);

int			ai(t_infos *infos)
{
  char			*msg;

  write_buf(infos, "voir");
  msg = read_buf(infos);
  if (msg)
    printf("%s", msg);
  prend(infos, "nourriture");
  msg = read_buf(infos);
  if (msg)
    printf("%s", msg);
  return (RETURN_SUCCESS);
}
