/*
** handle3.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 21 17:58:50 2016 Gabriel Goude
** Last update Tue Jun 21 17:59:54 2016 Gabriel Goude
*/

#include "resources.h"

int				handle_connect_nbr(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}
