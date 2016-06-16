/*
** voir.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jun 16 16:45:43 2016 Erwan Dupard
** Last update Thu Jun 16 18:32:17 2016 Karine Aknin
*/

#include "server.h"

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

int		event_voir(t_server *server, va_list ap)
{
  t_client	*client;
  t_map		*map;
  t_case	*cases;
  int		max_size;

  client = (t_client *)va_arg(ap, (t_client *));
  printf("client : %p\n", client);
  map = &(server->game_data.map);
  max_size = generate_max_size(client->character->level);
  if (!(cases = malloc(sizeof(*character) * (max_size + 1))))
    return (RETURN_FAILURE);
  cases[max_size] = NULL;
  return (RETURN_SUCCESS);
}
