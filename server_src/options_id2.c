/*
** options_id2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun  7 16:17:21 2016 Erwan Dupard
** Last update Fri Jun 10 15:14:14 2016 Barthelemy Gouby
*/

#include "server.h"

int					option_id_teams(char **args, t_server *server)
{
  u64					i;
  t_team				*teams;

  i = 0;
  ++args;
  while (args[i])
    ++i;
  if ((teams = malloc(sizeof(*teams) * (i + 1))) == NULL)
    return (RETURN_FAILURE);
  i = 0;
  while (args[i])
    {
      teams[i].name = args[i];
      teams[i].members = NULL;
      teams[i].max_members = 0;
      ++i;
    }
  server->game_data.teams = teams;
  server->game_data.nbr_of_teams = i;
  return (RETURN_SUCCESS);
}
