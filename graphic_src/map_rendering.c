/*
** map_rendering.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Mon Jun 20 15:14:51 2016 Thomas Billot
** Last update Sun Jun 26 20:54:52 2016 Thomas Billot
*/

#include "xfunc.h"
#include "graphical.h"

void		render_characters(t_render *render,
				  t_character *root,
				  int x,
				  int y)
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
    }
}

void		render_ressources(t_render *render,
				  t_quantity obj[NUMBER_OF_TYPES],
				  int screen_x,
				  int screen_y)
{
  if (obj[FOOD] >= 1)
    display_texture(render, &render->tileset[FOOD_T],
  		    screen_x + 2, screen_y);
  if (obj[LINEMATE] >= 1)
    display_texture(render, &render->tileset[LINEMATE_T],
  		    screen_x + 2, screen_y);
  if (obj[DERAUMERE] >= 1)
    display_texture(render, &render->tileset[DERAUMERE_T],
  		    screen_x + 2, screen_y);
  if (obj[SIBUR] >= 1)
    display_texture(render, &render->tileset[SIBUR_T],
  		    screen_x + 2, screen_y);
  if (obj[MENDIANE] >= 1)
    display_texture(render, &render->tileset[MENDIANE_T],
  		    screen_x + 2, screen_y);
  if (obj[PHIRAS] >= 1)
    display_texture(render, &render->tileset[PHIRAS_T],
  		    screen_x + 2, screen_y);
  if (obj[THYSTAME] >= 1)
    display_texture(render, &render->tileset[THYSTAME_T],
  		    screen_x + 2, screen_y);
}

int		map_rendering(t_render *render, t_map *map)
{
  int		i;
  int		map_x;
  int		map_y;
  int		screen_x;
  int		screen_y;

  i = map->x * map->y;
  draw_backg(render);
  while (i-- > 0)
    {
      map_x = i % map->x;
      map_y = i / map->x;
      screen_x = CONVERT_X(map_x, map_y) + (WIN_W / 2);
      screen_y = CONVERT_Y(map_x, map_y) + (WIN_H / 2);
      display_texture(render,
		      &render->tileset[GRASS],
		      screen_x, screen_y);
      if (map->tiles[i].players >= 1)
	render_characters(render, map->tiles[i].characters, screen_x, screen_y);
      render_ressources(render, map->tiles[i].obj, screen_x, screen_y);
    }
  SDL_RenderPresent(render->rend);
  clear_surface(render);
  return (RETURN_SUCCESS);
}
