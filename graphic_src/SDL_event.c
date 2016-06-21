/*
** SDL_event.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Thu Jun 16 14:44:04 2016 Thomas Beaudet
** Last update Mon Jun 20 16:52:49 2016 Thomas Billot
*/

#include <SDL2/SDL.h>
#include "graphical.h"

int			sdl_event(t_render *ress)
{
  if (ress->event.type == SDL_QUIT)
    {
      sdl_quit();
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}
