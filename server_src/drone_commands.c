/*
** drone_commands.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun 16 13:10:02 2016 Barthelemy Gouby
** Last update Wed Jun 22 17:07:32 2016 Erwan Dupard
*/

#include <math.h>
#include "server.h"

int					voir_command(t_server *server
						     __attribute__((unused)),
						     t_client *client,
						     char *operands
						     __attribute__((unused)))
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      printf("creating voir action\n");
      if ((new_action = malloc(sizeof(*new_action))) == NULL)
	return (RETURN_FAILURE);
      new_action->type = VOIR;
      new_action->origin = client;
      new_action->duration = 7;
      new_action->next = NULL;
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);
}

int				        inventaire_command(t_server *server
							   __attribute__((unused)),
							   t_client *client,
							   char *operands
							   __attribute__((unused)))
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      printf("creating inventaire action\n");
      if ((new_action = malloc(sizeof(*new_action))) == NULL)
	return (RETURN_FAILURE);
      new_action->type = INVENTORY;
      new_action->origin = client;
      new_action->duration = 7;
      new_action->next = NULL;
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);
}

int					droite_command(t_server *server
						       __attribute__((unused)),
						       t_client *client,
						       char *operands
						       __attribute__((unused)))
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      printf("creating droite action\n");
      if ((new_action = malloc(sizeof(*new_action))) == NULL)
	return (RETURN_FAILURE);
      new_action->type = TURN;
      new_action->origin = client;
      new_action->duration = 7;
      new_action->argument = (char *) RIGHT;
      new_action->next = NULL;
      add_action(&client->character->action_queue, new_action);
    }
  return (RETURN_SUCCESS);
}

int				        gauche_command(t_server *server
						       __attribute__((unused)),
						       t_client *client,
						       char *operands
						       __attribute__((unused)))
{
  t_action				*new_action;

  if (client->type == DRONE)
    {
      printf("creating gauche action\n");
      if ((new_action = malloc(sizeof(*new_action))) == NULL)
	return (RETURN_FAILURE);
      new_action->type = TURN;
      new_action->origin = client;
      new_action->duration = 7;
      new_action->argument = (char *) LEFT;
      new_action->next = NULL;
      add_action(&client->character->action_queue, new_action);
      printf("finished creating action\n");
    }
  return (RETURN_SUCCESS);
}

int				        expulse_command(t_server *server,
							t_client *client,
							char *operands
							__attribute__((unused)))
{
  t_action				*new_action;

  if (client->type == DRONE)
    {

      if ((new_action = malloc(sizeof(*new_action))) == NULL)
	return (RETURN_FAILURE);
      write_to_buffer(client->buffer_out, "elevation en cours", strlen("elevation en cours"));
      new_action->type = EXPULSE;
      new_action->origin = client;
      new_action->duration = 7;
      new_action->argument = NULL;
      new_action->next = NULL;
      add_action(&server->game_data.pending_actions, new_action);
    }
  return (RETURN_SUCCESS);
}
