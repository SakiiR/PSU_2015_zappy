/*
** options_id2.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun  7 16:17:21 2016 Erwan Dupard
** Last update Tue Jun  7 16:30:52 2016 Erwan Dupard
*/

#include "resources.h"

int					option_id_teams(char **args, t_options *options)
{
  u64					i;
  char					**teams;

  i = 0;
  ++args;
  while (args[i])
    ++i;
  if ((teams = malloc(sizeof(*teams) * (i + 1))) == NULL)
    return (RETURN_FAILURE);
  i = 0;
  while (args[i])
    {
      teams[i] = args[i];
      ++i;
    }
  teams[i] = NULL;
  options->teams = teams;
  return (RETURN_SUCCESS);
}
