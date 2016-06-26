/*
** handle.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 21 17:02:35 2016 Gabriel Goude
** Last update Sun Jun 26 17:41:42 2016 Karine Aknin
*/

#include "resources.h"

int				handle_msg(t_infos *infos,
					   char *msg,
					   int (**fct)(t_infos *, char *))
{
  printf("msg received : %s", msg);
  printf("msg is of type : %d\n", infos->request->request);
  if (fct[infos->request->request](infos, msg) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
