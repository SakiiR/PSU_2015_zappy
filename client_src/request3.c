/*
** request3.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 16:43:03 2016 Gabriel Goude
** Last update Fri Jun 17 16:35:29 2016 Gabriel Goude
*/

#include <unistd.h>
#include <stdlib.h>
#include "resources.h"

int					connect_nbr(t_infos *infos)
{
  if (write_buf(infos, "connect_nbr") == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (add_elem(infos, CONNECT_NBR) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
