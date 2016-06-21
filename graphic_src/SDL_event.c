/*
** SDL_event.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Thu Jun 16 14:44:04 2016 Thomas Beaudet
** Last update Tue Jun 21 17:39:07 2016 Thomas Beaudet
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
