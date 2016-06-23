/*
** handle.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 21 17:02:35 2016 Gabriel Goude
** Last update Thu Jun 23 15:19:00 2016 Gabriel Goude
*/

#include "resources.h"

int				handle_msg(t_infos *infos, char *msg, int (**fct)(t_infos *, char *))
{
  printf("msg received : %s", msg);
  printf("msg is of type : %d\n", infos->request->request);
  fct[infos->request->request](infos, msg);
  return (RETURN_SUCCESS);
}
