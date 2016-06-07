/*
** main.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Sat Jun  4 17:48:27 2016 Erwan Dupard
** Last update Tue Jun  7 16:52:48 2016 Erwan Dupard
*/

#include "resources.h"

static void			usage(const char *file_name)
{
  printf("usage: %s ", file_name);
  printf("[[[-p port] -p port] ...] ");
  printf("[-x world_x] ");
  printf("[-y world_y] ");
  printf("[-c max_clients] ");
  printf("[-c max_clients] ");
  printf("[-t speed] ");
  printf("-n team_name_1 team_name_2 ...\n");
}

int				main(int argc, char **argv)
{
  t_options			options;

  init_options(&options);
  if (get_options(argc, argv, &options) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (check_options(&options) == RETURN_FAILURE)
    {
      usage(argv[0]);
      return (RETURN_SUCCESS);
    }
  printf("OPTIONS!\n");
  printf("options->port : %d\n", options.port);
  printf("options->world_x : %d\n", options.world_x);
  printf("options->world_y : %d\n", options.world_y);
  printf("options->max_clients : %d\n", options.max_clients);
  printf("options->speed : %d\n", options.speed);
  printf("options->teams : %p\n", (void *)options.teams);
  return (RETURN_SUCCESS);
}
