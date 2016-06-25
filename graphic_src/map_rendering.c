/*
** map_rendering.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Mon Jun 20 15:14:51 2016 Thomas Billot
<<<<<<< HEAD
** Last update Sat Jun 25 17:29:07 2016 Thomas Billot
=======
** Last update Sat Jun 25 15:56:23 2016 Thomas Beaudet
>>>>>>> a98d0bc76efafd10e863c61f66656e6eee5d5b49
*/

#include "graphical.h"

void		render_characters(t_render *render, t_character *root,
				  int x, int y)
{
  t_character	*current;

  if (root->next_in_case != NULL)
    {
      current = root->next_in_case;
      while (current != NULL)
	{
	  if (current->status != DEAD)
	    display_texture(render,
			    &render->tileset[current->texture],
			    x, y);
	  current = current->next_in_case;
	}
<<<<<<< HEAD
=======

>>>>>>> a98d0bc76efafd10e863c61f66656e6eee5d5b49
    }
}

int		map_rendering(t_render *render, t_map *map)
{
  int		i;
  int		map_x;
  int		map_y;
  int		screen_x;
  int		screen_y;

  i = -1;
  while (++i < (map->x * map->y))
    {
      map_x = i % map->x;
      map_y = i / map->x;
      screen_x = CONVERT_X(map_x, map_y) + (WIN_W / 2);
      screen_y = CONVERT_Y(map_x, map_y);
      display_texture(render,
		      &render->tileset[GRASS],
		      screen_x, screen_y);
      if (map->tiles[i].players >= 1)
	render_characters(render, map->tiles[i].characters, screen_x, screen_y);
    }
  return (RETURN_SUCCESS);
}

int		ress_rendering(t_render *render, t_map *map)
{
  int		i;
  int		j;

  i = -1;
  j = -1;
  while (++i << (map->x * map->y))
    {
      while (++j << (map->tiles->obj[1]))
	{
	  display_texture(render,
			  &render->tileset[LINEMATE_T],
			  (640 - 5) / 2,
			  (480 - 5) / 2);
	}
    }
  return (RETURN_SUCCESS);
}
