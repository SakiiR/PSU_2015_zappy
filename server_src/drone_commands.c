/*
** drone_commands.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun 16 13:10:02 2016 Barthelemy Gouby
** Last update Thu Jun 16 16:43:07 2016 Barthelemy Gouby
*/

#include <math.h>
#include "server.h"

int		test_command(t_server *server,
			     t_client *client,
			     char *operands)
{
  t_action	*new_action;
  double	length;

  (void) operands;
  (void) client;
  printf("creating test\n");
  new_action = malloc(sizeof(*new_action));
  gettimeofday(&new_action->start_of_action, NULL);
  length = 7.0 / server->game_data.speed;
  new_action->length_of_action.tv_sec = (int) length;
  new_action->length_of_action.tv_usec = (int)((length - (int) length) * 1000000);
  add_action(&server->game_data.pending_actions, new_action);
  return (RETURN_SUCCESS);
}
