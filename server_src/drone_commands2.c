/*
** drone_commands2.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Jun 17 12:01:37 2016 Barthelemy Gouby
** Last update Thu Jun 23 15:11:01 2016 Erwan Dupard
*/

#include "server.h"

int				        avance_command(t_server *server
						       __attribute__((unused)),
						       t_client *client,
						       char *operands
						       __attribute__((unused)))
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      if ((new_action = malloc(sizeof(*new_action))) == NULL)
	return (RETURN_FAILURE);
      new_action->type = ADVANCE;
      new_action->origin = client;
      new_action->duration = 7;
      new_action->next = NULL;
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);
}

int					incantation_command(t_server *server
							    __attribute__((unused)),
							    t_client *client,
							    char *operands
							    __attribute__((unused)))
{
  t_action				*new_action;
  t_incantation				*incantation;
  t_character				**players;

  incantation = get_incantation_by_level(client->character->level + 1);
  if (check_incantation(incantation, client->character->current_case, &players) == RETURN_FAILURE)
    return (RETURN_SUCCESS);
  if (client->type == DRONE && incantation)
    {
      if ((new_action = malloc(sizeof(*new_action))) == NULL)
	return (RETURN_FAILURE);
      new_action->type = INCANTATION;
      new_action->origin = client;
      new_action->argument = players;
      new_action->duration = 300;
      new_action->next = NULL;
      incantation_broadcast_b(server, incantation, players);
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);
}

int					prend_command(t_server *server
						      __attribute__((unused)),
						      t_client *client,
						      char *operands)
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      if ((new_action = malloc(sizeof(*new_action))) == NULL)
	return (RETURN_FAILURE);
      new_action->type = TAKE_RESOURCE;
      new_action->origin = client;
      new_action->duration = 7;
      if (!(new_action->argument = malloc(strlen(operands))))
	return (RETURN_FAILURE);
      strcpy(new_action->argument, operands);
      new_action->next = NULL;
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);
}

int					pose_command(t_server *server
						     __attribute__((unused)),
						     t_client *client,
						     char *operands)
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      if (!(new_action = malloc(sizeof(*new_action))))
	return (RETURN_FAILURE);
      new_action->type = THROW_RESOURCE;
      new_action->origin = client;
      new_action->duration = 7;
      if (!(new_action->argument = malloc(strlen(operands))))
	return (RETURN_FAILURE);
      strcpy(new_action->argument, operands);
      new_action->next = NULL;
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);
}
