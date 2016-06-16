/*
** voir.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jun 16 16:45:43 2016 Erwan Dupard
** Last update Thu Jun 16 16:46:44 2016 Erwan Dupard
*/

#include "server.h"

int					event_voir(t_server *server, va_list ap)
{
  t_client				*client;

  client = (t_client *)va_arg(ap, (t_client *));
  printf("client : %p\n", client);
  return (RETURN_SUCCESS);
}
