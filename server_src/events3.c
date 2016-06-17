/*
** events3.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Jun 17 14:53:51 2016 Barthelemy Gouby
** Last update Fri Jun 17 14:55:00 2016 Barthelemy Gouby
*/

#include "server.h"

int					event_take(t_server *server, va_list ap)
{
  t_client			*client;

  client = va_arg(ap, t_client *);

}

int					event_throw(t_server *server, va_list ap)
{
  t_client			*client;

  client = va_arg(ap, t_client *);
}

