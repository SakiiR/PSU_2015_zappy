/*
** SDL_event.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Thu Jun 16 14:44:04 2016 Thomas Beaudet
** Last update Wed Jun 22 16:23:48 2016 Thomas Beaudet
*/

#include <SDL2/SDL.h>
#include "graphical.h"

int			sdl_event(t_render *ress)
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
  return (RETURN_SUCCESS);
}

SDL_Rect		sdl_mouse_motion(t_render *ress)
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
	  /*      ress->mouse_x = ress->event.motion.x;
		  ress->mouse_y = ress->event.motion.y;
		  ress->mouse_x_rel = ress->event.motion.xrel;
		  ress->mouse_y_rel = ress->event.motion.yrel;*/
	  printf("Mousemotion and mousebutton\n");
	}
    }
  return (surface_pos);
}
