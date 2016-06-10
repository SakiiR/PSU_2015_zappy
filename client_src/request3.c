/*
** request3.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 16:43:03 2016 Gabriel Goude
** Last update Fri Jun 10 17:08:43 2016 Erwan Dupard
*/

#include <unistd.h>
#include <stdlib.h>
#include "resources.h"

int					connect_nbr(t_client_settings *settings)
{
  write(settings->s, "connect_nbr\n", 12);
  return (RETURN_SUCCESS);
}
