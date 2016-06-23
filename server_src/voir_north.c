/*
** voir_north.c for voir_north in /home/aknin_k/rendu/tek2/reseau/zappy/PSU_2015_zappy/server_src
** 
** Made by Karine Aknin
** Login   <aknin_k@epitech.net>
** 
** Started on  Mon Jun 20 15:25:23 2016 Karine Aknin
** Last update Thu Jun 23 17:43:37 2016 Karine Aknin
*/

#include "server.h"

int		generate_y_north(t_character *character, int level,
			   t_map *map)
{
  int		y;
  int		y_count;

  if ((y = character->current_case->y - level) < 0)
    {
      y_count = y * -1;
      y = map->height;
      while (y_count > 0)
        {
          if ((y -= 1) < 0)
            y = map->height - 1;
          --y_count;
        }
    }
  return (y);
}

int		generate_x_north(t_character *character, int base_size,
			   t_map *map)
{
  int		x;
  int		x_count;

  if ((x = character->current_case->x - (base_size / 2)) < 0)
    {
      x_count = x * -1;
      x = map->width;
      while (x_count > 0)
        {
          if ((x -= 1) < 0)
            x = map->width - 1;
          --x_count;
        }
    }
  return (x);
}

t_case		*find_first_case_north(t_map *map, t_character *character,
				int level, int base_size)
{
  int		x;
  int		y;

  y = generate_y_north(character, level, map);
  x = generate_x_north(character, base_size, map);
  return (map_get_case_at(x, y, map));
}

int		save_case_line_north(t_map *map, t_case **cases,
			       t_case *case_it, int base_size)
{
  int		i;
  int		x;
  int		y;

  i = 0;
  y = case_it->y;
  while (cases[i])
    i++;
  cases[i] = case_it;
  i++;
  x = case_it->x;
  while (base_size > 1)
    {
      if (++x > (int)map->width - 1)
	x = 0;
      cases[i] = map_get_case_at(x, y, map);
      ++i;
      --base_size;
    }
  return (RETURN_SUCCESS);
}

int		voir_north(t_map *map, t_client *client,
			   t_case **cases)
{
  unsigned int	level;
  int		base_size;
  t_case	*case_it;

  level = 1;
  cases[0] = client->character->current_case;
  while (level <= client->character->level)
    {
      base_size = generate_base_size_level(level);
      case_it = find_first_case_north(map, client->character,
				      level, base_size);
      save_case_line_north(map, cases, case_it, base_size);
      ++level;
    }
  return (generate_message_voir(client, cases));
}
