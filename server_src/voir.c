/*
** voir.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jun 16 16:45:43 2016 Erwan Dupard
** Last update Fri Jun 17 18:07:18 2016 Karine Aknin
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

t_case		*find_first_case(t_map *map, t_character *character,
				 int level, int base_size)
{
  t_case	*first_case;
  int		x;
  int		y;

  if (character->orientation == NORTH)
    {
      if (character->current_case->y == 0)
	y
    }
}

void		take_cases_line(t_map *map, t_character *character,
				t_case *cases, int level)
{
  int		base_size;
  t_case	*case_it;

  base_size = generate_max_size(level) - 1;
  case_it = find_first_case(map, character, level, base_size);
  while (base_size > 0)
    {
      
      --base_size;
    }
  
}

void		find_my_cases(t_map *map, t_character *character,
			      t_case *cases, int max_size)
{
  int		level;
  int		base_size;

  level = 1;
  cases[0] = charater->current_case;
  while (level <= character->level)
    {
      take_cases_line(map, character, cases, level);
      ++level;
    }
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
  find_my_cases(map, client->character, cases, max_size);
  return (RETURN_SUCCESS);
}
