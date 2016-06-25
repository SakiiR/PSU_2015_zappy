/*
** voir.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jun 16 16:45:43 2016 Erwan Dupard
** Last update Sat Jun 25 22:39:26 2016 Karine Aknin
*/

#include "server.h"

static const t_voir		g_voir[] = {
  {NORTH, &voir_north},
  {EAST, &voir_east},
  {SOUTH, &voir_south},
  {WEST, &voir_west},
  {10, NULL}
};

int				generate_base_size_level(int level)
{
  int				size;

  size = 1;
  while (level > 0)
    {
      size += 2;
      --level;
    }
  return (size);
}

int				event_voir(t_server *server, va_list ap)
{
  t_client			*client;
  t_map				*map;
  t_case			**cases;
  int			        number_of_cases;
  int				i;

  i = 0;
  client = (t_client *)va_arg(ap, t_client *);
  map = &(server->game_data.map);
  number_of_cases = pow(client->character->level + 1, 2);
  if ((cases = malloc(sizeof(*cases) * (number_of_cases + 1))) == NULL)
    return (RETURN_FAILURE);
  while (i < number_of_cases + 1)
    {
      cases[i] = NULL;
      i++;
    }
  i = -1;
  while (g_voir[++i].orientation != 10)
    {
      if (g_voir[i].orientation == client->character->orientation)
	return (g_voir[i].f(map, client, cases));
    }
  return (RETURN_SUCCESS);
}
