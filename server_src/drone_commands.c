/*
** drone_commands.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun 16 13:10:02 2016 Barthelemy Gouby
** Last update Fri Jun 17 12:41:58 2016 Barthelemy Gouby
*/

#include <math.h>
#include "server.h"

int					voir_command(t_server *server,
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
      add_action(&server->game_data.pending_actions, new_action);
    }
  return (RETURN_SUCCESS);
}

int				        inventaire_command(t_server *server,
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
      add_action(&server->game_data.pending_actions, new_action);
    }
  return (RETURN_SUCCESS);
}

int					droite_command(t_server *server,
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
      add_action(&server->game_data.pending_actions, new_action);
    }
  return (RETURN_SUCCESS);
}

int				        gauche_command(t_server *server,
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
      add_action(&server->game_data.pending_actions, new_action);
      printf("finished creating action\n");
    }
  return (RETURN_SUCCESS);
}
