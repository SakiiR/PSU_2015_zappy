/*
** incantations.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 17 12:46:39 2016 Erwan Dupard
** Last update Sun Jun 26 15:09:08 2016 Erwan Dupard
*/

#include "server.h"

static  t_incantation			g_incantations[] = {
  {2, 1, {0, 1, 0, 0, 0, 0, 0}},
  {3, 2, {0, 1, 1, 1, 0, 0, 0}},
  {4, 2, {0, 2, 0, 1, 0, 2, 0}},
  {5, 4, {0, 1, 1, 2, 0, 1, 0}},
  {6, 4, {0, 1, 2, 1, 3, 0, 0}},
  {7, 6, {0, 1, 2, 3, 0, 1, 0}},
  {8, 6, {0, 2, 2, 2, 2, 2, 1}},
  {0, 0, {0, 0, 0, 0, 0, 0, 0}}
};

t_incantation				*get_incantation_by_level(t_u64 level)
{
  int					i;

  i = -1;
  while (g_incantations[++i].level)
    {
      if (g_incantations[i].level == level)
	return (&g_incantations[i]);
    }
  return (NULL);
}

int					check_characters_incase(t_case *c,
								t_character **characters)
{
  t_character				*iterator;
  int					i;
  int					found;

  iterator = c->characters;
  while (iterator)
    {
      i = -1;
      found = 0;
      while (characters[++i])
	{
	  if (iterator == characters[i])
	    found = 1;
	}
      if (!found)
	return (RETURN_FAILURE);
      iterator = iterator->next_in_case;
    }
  return (RETURN_SUCCESS);
}

int					check_resources(t_case *c,
							t_incantation *incantation)
{
  int					i;

  i = 0;
  while (++i < NUMBER_OF_TYPES)
    {
      if (c->quantities[i] != incantation->obj[i])
	return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}

int					check_incantation(t_incantation *incantation,
							  t_case *c,
							  t_character ***characters
							  __attribute__((unused)))
{
  t_character				*iterator;
  int				        i;
  t_character				**players;

  i = 0;
  iterator = c->characters;
  while (iterator)
    {
      if (iterator->level + 1 != incantation->level)
	return (RETURN_FAILURE);
      iterator = iterator->next_in_case;
      ++i;
    }
  if (i != incantation->players)
    return (RETURN_FAILURE);
  if ((players = get_incantation_players(i, c->characters)) == NULL)
    return (RETURN_FAILURE);
  *characters = players;
  if (check_resources(c, incantation) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

int					do_incantation(t_case *c,
						       t_incantation *incantation)
{
  t_character				*iterator;
  int					i;

  printf("[+] Incantation on (%d, %d)\n", c->x, c->y);
  iterator = c->characters;
  while (iterator)
    {
      ++iterator->level;
      iterator = iterator->next_in_case;
    }
  i = -1;
  while (++i < NUMBER_OF_TYPES)
    c->quantities[i] -= incantation->obj[i];
  return (RETURN_SUCCESS);
}
