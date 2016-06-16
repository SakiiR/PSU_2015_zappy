/*
** voir.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jun 16 16:45:43 2016 Erwan Dupard
** Last update Thu Jun 16 17:06:08 2016 Erwan Dupard
*/

#include "server.h"

int					event_voir(t_server *server, va_list ap)
{
  t_client				*client;

  (void)server;
  client = (t_client *) va_arg(ap, void *);
  printf("client : %p\n", (void *)client);
  return (RETURN_SUCCESS);
}
