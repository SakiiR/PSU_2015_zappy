/*
** drone_commands2.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Fri Jun 17 12:01:37 2016 Barthelemy Gouby
** Last update Fri Jun 17 12:03:06 2016 Barthelemy Gouby
*/

#include "server.h"

int				        avance_command(t_server *server,
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
      new_action->type = ADVANCE;
      new_action->origin = client;
      new_action->duration = 7;
      new_action->next = NULL;
      add_action(&server->game_data.pending_actions, new_action);
      printf("finished creating action\n");
    }
  return (RETURN_SUCCESS);
}
