/*
** drone_commands3.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Mon Jun 20 14:21:45 2016 Barthelemy Gouby
** Last update Sat Jun 25 23:41:08 2016 Erwan Dupard
*/

#include "server.h"

int					fork_command(t_server *server,
						     t_client *client,
						     char *operands
						     __attribute__((unused)))
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      if (!(new_action = malloc(sizeof(*new_action))))
	return (RETURN_FAILURE);
      new_action->type = LAY_EGG;
      new_action->origin = client;
      new_action->duration = 42;
      new_action->argument = NULL;
      new_action->next = NULL;
      sprintf(server->buffer, "pfk %i\n", client->character->id);
      graphic_broadcast(server, server->buffer);
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);
}

int					connect_nbr_command(t_server *server,
							    t_client *client,
							    char *operands
							    __attribute__((unused)))
{
  sprintf(server->buffer, "%i\n",
	  number_of_hatched_eggs(client->character->team->eggs)
	  + server->game_data.base_max_members
	  - client->character->team->base_members);
  write_to_buffer(&client->buffer_out, server->buffer, strlen(server->buffer));
  return (RETURN_SUCCESS);
}

int					broadcast_command(t_server *server
							  __attribute__((unused)),
							  t_client *client,
							  char *operands)
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      if ((new_action = malloc(sizeof(*new_action))) == NULL)
	return (RETURN_FAILURE);
      new_action->type = BROADCAST;
      new_action->origin = client;
      new_action->duration = 7;
      new_action->argument = operands;
      new_action->next = NULL;
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);
}

int					end_command(t_client *client)
{
  t_action				*new_action;

  if (!(new_action = malloc(sizeof(*new_action))))
    return (RETURN_FAILURE);
  new_action->type = END_GAME;
  new_action->origin = NULL;
  new_action->duration = 7;
  new_action->argument = NULL;
  new_action->next = NULL;
  add_action(&client->character->action_queue, new_action);
  return (RETURN_SUCCESS);
}
