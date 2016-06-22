/*
** voir.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jun 16 16:45:43 2016 Erwan Dupard
** Last update Wed Jun 22 20:22:59 2016 Karine Aknin
*/

#include "server.h"

static const t_voir	g_voir[] = {
  {NORTH, &voir_north},
  {EAST, &voir_east},
  {SOUTH, &voir_south},
  {WEST, &voir_west},
  {10, NULL}
};

int		generate_max_size(t_u64 level)
{
  int		size;
  int		base_size;

  size = 1;
  base_size = 1;
  while (level > 0)
    {
      base_size += 2;
      size += base_size;
      --level;
    }
  return (size);
}

int	generate_base_size_level(int level)
{
  int   size;

  size = 1;
  while (level > 0)
    {
      size += 2;
      --level;
    }
  return (size);
}

int		event_voir(t_server *server, va_list ap)
{
  t_client	*client;
  t_map		*map;
  t_case	**cases;
  int		max_size;
  int		i;

  i = 0;
  client = (t_client *)va_arg(ap, t_client *);
  printf("client : %p inside event_voir\n", (void *)client);
  map = &(server->game_data.map);
  max_size = generate_max_size(client->character->level);
  if (!(cases = malloc(sizeof(*cases) * (max_size + 1))))
    return (RETURN_FAILURE);
  while (i <= max_size)
    {
      cases[i] = NULL;
      i++;
    }
  i = -1;
  printf("character->orientation = %d\n", client->character->orientation);
  while (g_voir[++i].orientation != 10)
    {
      if (g_voir[i].orientation == client->character->orientation)
	return (g_voir[i].f(map, client->character, cases));
    }
  return (RETURN_SUCCESS);
}
