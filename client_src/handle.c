/*
** handle.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 21 17:02:35 2016 Gabriel Goude
** Last update Tue Jun 21 17:12:04 2016 Gabriel Goude
*/

#include "resources.h"

int				handle_msg(t_infos *infos, char *msg)
{
  printf("msg received : %s", msg);
  printf("msg is of type : %d\n", infos->request->request);
  remove_elem(infos);
  return (RETURN_SUCCESS);
}
