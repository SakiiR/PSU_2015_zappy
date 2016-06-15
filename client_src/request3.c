/*
** request3.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 16:43:03 2016 Gabriel Goude
** Last update Mon Jun 13 17:54:59 2016 Gabriel Goude
*/

#include <unistd.h>
#include <stdlib.h>
#include "resources.h"

int					connect_nbr(t_infos *infos)
{
  write(infos->socket, "connect_nbr\n", 12);
  return (RETURN_SUCCESS);
}
