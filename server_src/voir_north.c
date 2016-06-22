/*
** voir_north.c for voir_north in /home/aknin_k/rendu/tek2/reseau/zappy/PSU_2015_zappy/server_src
** 
** Made by Karine Aknin
** Login   <aknin_k@epitech.net>
** 
** Started on  Mon Jun 20 15:25:23 2016 Karine Aknin
** Last update Mon Jun 20 21:05:21 2016 Karine Aknin
*/

#include "server.h"

int	generate_base_size_level(int level)
{
  int	size;

  size = 1;
  while (level > 0)
    {
      size += 2;
      --level;
    }
  return (size);
}

t_case		*find_first_case(t_map *map, t_character *character,
				int level, int base_size)
{
  int		x;
  int		y;
  int		y_count;
  int		x_count;

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
  return (map_get_case_at(x, y, map));
}

int		save_case_line(t_map *map, t_case **cases,
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

int		take_cases_line(t_map *map, t_character *character,
				t_case **cases, int level)
{
  int		base_size;
  t_case	*case_it;
  int		i;

  i = 0;
  base_size = generate_base_size_level(level);
  case_it = find_first_case(map, character, level, base_size);
  printf("case_it->x = %d ->y = %d\n", case_it->x, case_it->y);
  save_case_line(map, cases, case_it, base_size);
  printf("current case x = %d  y = %d\n", character->current_case->x, character->current_case->y);
  while (cases[i])
    {
      printf("case %d  x = %d  y = %d\n", i, cases[i]->x, cases[i]->y);
      i++;
    }
  return (RETURN_SUCCESS);
}

int		voir_north(t_map *map, t_character *character,
			   t_case **cases, int max_size)
{
  unsigned int	level;

  printf("inside voir_north\n");
  level = 1;
  cases[0] = character->current_case;
  while (level <= character->level)
    {
      if ((take_cases_line(map, character, cases, level))
	  == RETURN_FAILURE)
	return (RETURN_FAILURE);
      ++level;
    }
  return (RETURN_SUCCESS);
  (void)max_size;
}
