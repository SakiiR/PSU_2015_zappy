
/*
** map_rendering.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Mon Jun 20 15:14:51 2016 Thomas Billot
** Last update Sat Jun 25 13:01:28 2016 Thomas Beaudet
*/

#include "graphical.h"

int		map_rendering(t_render *render, t_map *map)
{
  int		i;
  int		map_x;
  int		map_y;

  i = -1;
  while (++i < (map->x * map->y))
    {
      map_x = i % map->x;
      map_y = i / map->x;
      display_texture(render,
		      &render->tileset[GRASS],
		      CONVERT_X(map_x, map_y) + (WIN_W / 2),
		      CONVERT_Y(map_x, map_y));
    }
  display_texture(render,
		  &render->tileset[CHARACTER],
		  640 / 2, 480 / 2);
  display_texture(render,
		  &render->tileset[FOOD_T],
		  360, 270);

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
