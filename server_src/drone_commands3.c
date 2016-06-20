/*
** drone_commands3.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Jun 20 14:21:45 2016 Barthelemy Gouby
** Last update Mon Jun 20 15:24:21 2016 Barthelemy Gouby
*/

#include "server.h"

int				fork_command(t_server *server
					     __attribute__((unused)),
					     t_client *client,
					     char *operands)
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      if (!(new_action = malloc(sizeof(*new_action))))
	return (RETURN_FAILURE);
      new_action->type = LAY_EGG;
      new_action->origin = client;
      new_action->duration = 7;
      new_action->argument = NULL;
      new_action->next = NULL;
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);

}
