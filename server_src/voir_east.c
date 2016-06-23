/*
** voir_north.c for voir_north in /home/aknin_k/rendu/tek2/reseau/zappy/PSU_2015_zappy/server_src
** 
** Made by Karine Aknin
** Login   <aknin_k@epitech.net>
** 
** Started on  Mon Jun 20 15:25:23 2016 Karine Aknin
** Last update Wed Jun 22 20:14:47 2016 Karine Aknin
*/

#include "server.h"

int		generate_x_east(t_character *character, int level,
				t_map *map)
{
  int		x;
  int		x_count;

  if ((x = character->current_case->x + level) > (int)map->width - 1)
    {
      x_count = x - (map->width - 1);
      x = 0;
      while (x_count > 1)
	{
	  if ((x += 1) > (int)map->width - 1)
	    x = 0;
	  --x_count;
        }
    }
  return (x);
}

int             generate_y_east(t_character *character, int base_size,
				t_map *map)
{
  int           y;
  int           y_count;

  if ((y = character->current_case->y - (base_size / 2)) < 0)
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

t_case		*find_first_case_east(t_map *map, t_character *character,
				int level, int base_size)
{
  int		x;
  int		y;

  x = generate_x_east(character, level, map);
  y = generate_y_east(character, base_size, map);
  return (map_get_case_at(x, y, map));
}

int             save_case_line_east(t_map *map, t_case **cases,
				    t_case *case_it, int base_size)
{
  int           i;
  int           x;
  int           y;

  i = 0;
  x = case_it->x;
  while (cases[i])
    i++;
  cases[i] = case_it;
  i++;
  y = case_it->y;
  while (base_size > 1)
    {
      if (++y > (int)map->height - 1)
        y = 0;
      cases[i] = map_get_case_at(x, y, map);
      ++i;
      --base_size;
    }
  return (RETURN_SUCCESS);
}

int		voir_east(t_map *map, t_character *character,
			   t_case **cases)
{
  unsigned int	level;
  int		base_size;
  t_case	*case_it;
  int		i;

  i = 0;
  level = 1;
  cases[0] = character->current_case;
  printf("inside voir east\n");
  while (level <= character->level)
    {
      base_size = generate_base_size_level(level);
      case_it = find_first_case_east(map, character, level, base_size);
      save_case_line_east(map, cases, case_it, base_size);
      ++level;
    }
  printf("current case x = %d  y = %d\n",
         character->current_case->x,
         character->current_case->y);
  while (cases[i])
    {
      printf("case %d  x = %d  y = %d\n", i, cases[i]->x, cases[i]->y);
      i++; 
    }
  return (RETURN_SUCCESS);
}
