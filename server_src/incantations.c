/*
** incantations.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 17 12:46:39 2016 Erwan Dupard
** Last update Fri Jun 17 16:22:47 2016 Erwan Dupard
*/

#include "server.h"

static  t_incantation			g_incatations[] = {
  {2, 1, {0, 1, 0, 0, 0, 0, 0}},
  {3, 2, {0, 1, 1, 1, 0, 0, 0}},
  {4, 2, {0, 2, 0, 1, 0, 2, 0}},
  {4, 4, {0, 1, 1, 2, 0, 1, 0}},
  {5, 4, {0, 1, 2, 1, 3, 0, 0}},
  {6, 6, {0, 1, 2, 3, 0, 1, 0}},
  {7, 6, {0, 2, 2, 2, 2, 2, 1}},
  {0, 0, {0, 0, 0, 0, 0, 0, 0}}
};

static t_u64				count_client_by_level(t_case *c, t_u64 level)
{
  t_u64					i;
  t_character				*iterator;

  i = 0;
  iterator = c->characters;
  while (iterator)
    {
      if (iterator->level == level - 1)
	++i;
      iterator = iterator->next_in_case;
    }
  return (i);
}

static t_incantation			*get_incantation_by_level(t_u64 level)
{
  int					i;

  i = -1;
  while (g_incatations[++i].level > 0)
    {
      if (g_incatations[i].level == (int)level)
	return (&g_incatations[i]);
    }
  return (NULL);
}

static int				check_incantation_requirement(t_incantation *incantation, t_case *c)
{
  int					i;

  i = -1;
  while (++i < NUMBER_OF_TYPES)
    {
      if (c->quantities[i] < incantation->obj[i])
	return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}

static void			        do_incantation(t_case *c, t_u64 level)
{
  t_character				*iterator;
  t_incantation				*incantation;
  int					i;

  iterator = c->characters;
  while (iterator)
    {
      if (iterator->level == level - 1)
	++iterator->level;
      iterator = iterator->next_in_case;
    }
  if ((incantation = get_incantation_by_level(level - 1)) != NULL)
    {
      i = -1;
      while (++i < 7)
	c->quantities[i] -= incantation->obj[i];
    }
}

int					try_incantation(t_case *c, t_u64 next_level)
{
  t_incantation				*incantation;
  t_u64					players_count;

  if ((incantation = get_incantation_by_level(next_level)) == NULL)
    return (RETURN_FAILURE);
  players_count = count_client_by_level(c, next_level);
  if ((int)players_count == incantation->level &&
      check_incantation_requirement(incantation, c) == RETURN_SUCCESS)
    do_incantation(c, next_level);
  /* Can't do incantation ! :( */
  return (RETURN_FAILURE);
}


