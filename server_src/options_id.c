/*
** options_id.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun  7 16:16:22 2016 Erwan Dupard
** Last update Tue Jun  7 16:27:16 2016 Erwan Dupard
*/

#include "resources.h"

int					option_id_port(char **args, t_options *options)
{
  if (args[1])
    options->port = atoi(args[1]);
  return (RETURN_SUCCESS);
}

int					option_id_worldx(char **args, t_options *options)
{
  if (args[1])
    options->world_x = atoi(args[1]);
  return (RETURN_SUCCESS);
}

int					option_id_worldy(char **args, t_options *options)
{
  if (args[1])
    options->world_y = atoi(args[1]);
  return (RETURN_SUCCESS);
}

int					option_id_maxclients(char **args, t_options *options)
{
  if (args[1])
    options->max_clients = atoi(args[1]);
  return (RETURN_SUCCESS);
}

int					option_id_speed(char **args, t_options *options)
{
  if (args[1])
    options->speed = atoi(args[1]);
  return (RETURN_SUCCESS);
}
