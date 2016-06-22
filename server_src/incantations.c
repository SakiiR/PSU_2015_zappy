/*
** incantations.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 17 12:46:39 2016 Erwan Dupard
** Last update Wed Jun 22 18:13:33 2016 Erwan Dupard
*/

#include "server.h"

static  t_incantation			g_incantations[] = {
  {2, 1, {0, 1, 0, 0, 0, 0, 0}},
  {3, 2, {0, 1, 1, 1, 0, 0, 0}},
  {4, 2, {0, 2, 0, 1, 0, 2, 0}},
  {4, 4, {0, 1, 1, 2, 0, 1, 0}},
  {5, 4, {0, 1, 2, 1, 3, 0, 0}},
  {6, 6, {0, 1, 2, 3, 0, 1, 0}},
  {7, 6, {0, 2, 2, 2, 2, 2, 1}},
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

  i = -1;
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

  iterator = c->characters;
  while (iterator)
    {
      if (iterator->level != incantation->level)
	return (RETURN_FAILURE);
      iterator = iterator->next_in_case;;
      ++i;
    }
  if (i != incantation->players)
    return (RETURN_FAILURE);
  if ((players = malloc(sizeof(*players) * (i + 1))) == NULL)
    return (RETURN_FAILURE);
  i = 0;
  while (iterator)
    {
      players[i] = iterator;
      iterator = iterator->next_in_case;
    }
  players[i] = NULL;
  characters = &players;
  return (RETURN_SUCCESS);
}

int					do_incantation(t_case *c,
						       t_incantation *incantation)
{
  t_character				*iterator;
  int					i;

  iterator = c->characters;
  while (iterator)
    {
      iterator->level = incantation->level + 1;
      iterator = iterator->next_in_case;
    }
  i = -1;
  while (++i < NUMBER_OF_TYPES)
    c->quantities[i] -= incantation->obj[i];
  return (RETURN_SUCCESS);
}
