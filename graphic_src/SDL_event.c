/*
** SDL_event.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Thu Jun 16 14:44:04 2016 Thomas Beaudet
** Last update Thu Jun 23 13:58:15 2016 Thomas Beaudet
*/

#include <SDL2/SDL.h>
#include "graphical.h"

int			sdl_event(t_render *ress, t_texture *tile)
{
  const Uint8		*keys;

  keys = SDL_GetKeyboardState(NULL);
  if (ress->event.type == SDL_QUIT)
    {
      sdl_quit();
      return (RETURN_FAILURE);
    }
  if (keys[SDL_SCANCODE_ESCAPE])
    {
      sdl_quit();
      return (RETURN_FAILURE);
    }
  if (keys[SDL_SCANCODE_DOWN])
    {
      printf("DOWN");
    }
  if (keys[SDL_SCANCODE_UP])
    {
      zoom(ress, tile, 10, 10, 2, 2);
      printf("UP");
    }
  return (RETURN_SUCCESS);
}

void			zoom(t_render *ress, t_texture *tile,
			     int x, int y,
			     float scale_W, float scale_H)
{
  ress->scaleW = 1;
  ress->scaleH = 1;
  if (ress->dest_rect.x != x || ress->dest_rect.y != y
      || ress->scaleW != scale_W || ress->scaleH != scale_H)
    {
      SDL_QueryTexture(tile->texture, NULL, NULL,
		       &ress->dest_rect.w, &ress->dest_rect.h);
      ress->dest_rect.x =
	(int) x - (ress->dest_rect.w * scale_W - ress->dest_rect.w) / 2;
      ress->dest_rect.y =
	(int) y - (ress->dest_rect.h * scale_H - ress->dest_rect.h) / 2;
      printf("%d\n", ress->dest_rect.x);
      printf("%d\n", ress->dest_rect.y);
      ress->dest_rect.w = (int) ress->dest_rect.w * scale_W;
      ress->dest_rect.h = (int) ress->dest_rect.h * scale_H;
      printf("%d\n", ress->dest_rect.w);
      printf("%d\n", ress->dest_rect.h);
      ress->scaleW = scale_W;
      ress->scaleH = scale_H;
      SDL_RenderCopy(ress->rend, tile->texture, NULL, &ress->dest_rect);
    }
}

/*SDL_Rect		sdl_mouse_motion(t_render *ress)
{
  int			state;
  SDL_Rect		surface_pos;

  state = 0;
  if (ress->event.type == SDL_MOUSEBUTTONDOWN)
    {
      ress->mouse_buttons[ress->event.button.button] = 1;
      state = 1;
    }
  if (ress->event.type == SDL_MOUSEBUTTONUP)
    {
      ress->mouse_buttons[ress->event.button.button] = 0;
      state = 0;
    }
  if (ress->event.type == SDL_MOUSEMOTION)
    {
      if (state)
	{
	  surface_pos.x = ress->event.motion.x;
	  surface_pos.y = ress->event.motion.y;
	        ress->mouse_x = ress->event.motion.x;
		  ress->mouse_y = ress->event.motion.y;
		  ress->mouse_x_rel = ress->event.motion.xrel;
		  ress->mouse_y_rel = ress->event.motion.yrel;
	  printf("Mousemotion and mousebutton\n");
	}
    }
  return (surface_pos);
}*/
