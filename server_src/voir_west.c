/*
** voir_north.c for voir_north in /home/aknin_k/rendu/tek2/reseau/zappy/PSU_2015_zappy/server_src
** 
** Made by Karine Aknin
** Login   <aknin_k@epitech.net>
** 
** Started on  Mon Jun 20 15:25:23 2016 Karine Aknin
** Last update Sun Jun 26 17:44:55 2016 Erwan Dupard
*/

#include "server.h"

int		generate_x_west(t_character *character, int level,
				t_map *map)
{
  int		x;
  int		x_count;

  if ((x = character->current_case->x - level) < 0)
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

int		generate_y_west(t_character *character, int base_size,
				t_map *map)
{
  int		y;
  int		y_count;

  if ((y = character->current_case->y + (base_size / 2))
      > (int)map->height - 1)
    {
      y_count = y - (map->height - 1);
      y = 0;
      while (y_count > 1)
        {
          if ((y += 1) > (int)map->height - 1)
            y = 0;
          --y_count;
        }
    }
  return (y);
}

t_case		*find_first_case_west(t_map *map, t_character *character,
				int level, int base_size)
{
  int		x;
  int		y;

  x = generate_x_west(character, level, map);
  y = generate_y_west(character, base_size, map);
  return (map_get_case_at(x, y, map));
}

int		save_case_line_west(t_map *map, t_case **cases,
				    t_case *case_it, int base_size)
{
  int		i;
  int		x;
  int		y;

  i = 0;
  x = case_it->x;
  while (cases[i])
    i++;
  cases[i] = case_it;
  i++;
  y = case_it->y;
  while (base_size > 1)
    {
      if (--y < 0)
        y = map->height - 1;
      cases[i] = map_get_case_at(x, y, map);
      ++i;
      --base_size;
    }
  return (RETURN_SUCCESS);
}

int		voir_west(t_map *map, t_client *client,
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
      case_it = find_first_case_west(map, client->character,
				     level, base_size);
      save_case_line_west(map, cases, case_it, base_size);
      ++level;
    }
  return (generate_message_voir(client, cases));
}
