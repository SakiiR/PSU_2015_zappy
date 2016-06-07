/*
** options.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun  7 15:51:44 2016 Erwan Dupard
** Last update Tue Jun  7 16:49:03 2016 Erwan Dupard
*/

#include "resources.h"

static t_option_id			g_options_ids[] = {
  {'p', &option_id_port},
  {'x', &option_id_worldx},
  {'y', &option_id_worldy},
  {'c', &option_id_maxclients},
  {'t', &option_id_speed},
  {'n', &option_id_teams},
  {'\0', NULL}
};

void					init_options(t_options *options)
{
  options->port = 0;
  options->port = 0;
  options->world_x = 0;
  options->world_y = 0;
  options->max_clients = 0;
  options->speed = 0;
  options->teams = NULL;
}

int					get_options(u64 argc,
						    char **argv,
						    t_options *options)
{
  u64					i;

  i = 0;
  while (i < argc)
    {
      if (argv[i][0] == '-')
	{
	  if (handle_option_id(argv[i][1], &argv[i], options) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
      ++i;
    }
  return (RETURN_SUCCESS);
}

int					handle_option_id(const char id,
							 char **args,
							 t_options *options)
{
  u64					i;

  i = 0;
  while (g_options_ids[i].id)
    {
      if (id == g_options_ids[i].id)
	{
	  if (g_options_ids[i].f(args, options) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
      ++i;
    }
  return (RETURN_SUCCESS);
}

int					check_options(t_options *options)
{
  if (!(options->teams && options->teams[0] && options->teams[1]) ||
      !(options->port >= MIN_PORT && options->port <= MAX_PORT) ||
      !(options->world_x >= MIN_WORLD_X && options->world_x <= MAX_WORLD_X) ||
      !(options->world_y >= MIN_WORLD_Y && options->world_y <= MAX_WORLD_Y) ||
      !(options->max_clients >= MIN_MAX_CLIENTS &&
	options->max_clients <= MAX_MAX_CLIENTS) ||
      !(options->speed >= MIN_SPEED && options->speed <= MAX_SPEED)
      )
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
