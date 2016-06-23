/*
** graphic_commands2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Jun 13 18:43:41 2016 Erwan Dupard
** Last update Thu Jun 23 15:09:33 2016 Erwan Dupard
*/

#include "server.h"

int					change_time_unit(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)))
{
  (void)server;
  (void)client;
  (void)operands;
  return (RETURN_SUCCESS);
}

int				        send_player_level(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)))
{
  (void)client;
  (void)server;
  (void)operands;
  return (RETURN_SUCCESS);
}

int					send_player_inventory(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)))
{
  (void)server;
  (void)client;
  (void)operands;
  return (RETURN_SUCCESS);
}

int					send_player_position(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)))
{
  (void)server;
  (void)client;
  (void)operands;
  return (RETURN_SUCCESS);
}
