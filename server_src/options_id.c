/*
** options_id.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun  7 16:16:22 2016 Erwan Dupard
** Last update Fri Jun 10 15:30:01 2016 Barthelemy Gouby
*/

#include "server.h"

int					option_id_port(char **args, t_server *server)
{
  if (args[1])
    server->port = atoi(args[1]);
  return (RETURN_SUCCESS);
}

int					option_id_worldx(char **args, t_server *server)
{
  if (args[1])
    server->game_data.map.width = atoi(args[1]);
  return (RETURN_SUCCESS);
}

int					option_id_worldy(char **args, t_server *server)
{
  if (args[1])
    server->game_data.map.height = atoi(args[1]);
  return (RETURN_SUCCESS);
}

int					option_id_maxmembers(char **args, t_server *server)
{
  if (args[1])
    server->game_data.base_max_members = atoi(args[1]);
  return (RETURN_SUCCESS);
}

int					option_id_speed(char **args, t_server *server)
{
  if (args[1])
    server->game_data.speed = atoi(args[1]);
  return (RETURN_SUCCESS);
}
