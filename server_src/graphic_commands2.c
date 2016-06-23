/*
** graphic_commands2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Jun 13 18:43:41 2016 Erwan Dupard
** Last update Thu Jun 23 18:50:15 2016 Barthelemy Gouby
*/

#include "server.h"

int					change_time_unit(t_server *server,
							 t_client *client,
							 char *operands)
{
  int					new_speed;

  if (operands && (new_speed = atoi(operands)) > 0)
    {
      server->game_data.speed = new_speed;
      set_time_speed(server);
    }
  send_speed(server, client, NULL);
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
