/*
** options.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun  7 15:51:44 2016 Erwan Dupard
** Last update Thu Jun 23 16:25:18 2016 Erwan Dupard
*/

#include "server.h"

static t_option_id			g_options_ids[] = {
  {'p', &option_id_port},
  {'x', &option_id_worldx},
  {'y', &option_id_worldy},
  {'c', &option_id_maxmembers},
  {'t', &option_id_speed},
  {'n', &option_id_teams},
  {0, NULL}
};

static void				usage(const char *file_name)
{
  printf("usage: %s ", file_name);
  printf("[[[-p port] -p port] ...] ");
  printf("[-x world_x] ");
  printf("[-y world_y] ");
  printf("[-c max_clients] ");
  printf("[-t speed] ");
  printf("-n team_name_1 team_name_2 ...\n");
}

void					init_options(t_server *server)
{
  server->port = 0;
  server->game_data.map.width = 0;
  server->game_data.map.height = 0;
  server->game_data.base_max_members = 1;
  server->game_data.speed = 100;
  server->game_data.teams = NULL;
  server->game_data.nbr_of_teams = 0;
}

int					get_options(t_u64 argc,
						    char **argv,
						    t_server *server)
{
  int					i;

  i = 0;
  init_options(server);
  while (i < (int)argc)
    {
      if (argv[i][0] == '-')
	{
	  if (handle_option_id(argv[i][1], &argv[i], server) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
      ++i;
    }
  i = -1;
  while (++i < (int)server->game_data.nbr_of_teams)
    server->game_data.teams[i].max_members =
      server->game_data.base_max_members;
  return (check_options(server, argv[0]));
}

int					handle_option_id(const char id,
							 char **args,
							 t_server *server)
{
  t_u64					i;

  i = 0;
  while (g_options_ids[i].id)
    {
      if (id == g_options_ids[i].id)
	{
	  if (g_options_ids[i].f(args, server) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
      ++i;
    }
  return (RETURN_SUCCESS);
}

int					check_options(t_server *server, char *file_name)
{
  if (!(server->game_data.teams
	&& server->game_data.nbr_of_teams > 0) ||
      !(server->port >= MIN_PORT && server->port <= MAX_PORT) ||
      !(server->game_data.map.width >= MIN_WORLD_X) ||
      !(server->game_data.map.height >= MIN_WORLD_Y) ||
      !(server->game_data.base_max_members >= MIN_MAX_CLIENTS) ||
      !(server->game_data.speed >= MIN_SPEED) ||
      !(server->game_data.teams[0].name &&
	server->game_data.teams[1].name)
      
      )
    {
      usage(file_name);
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}
