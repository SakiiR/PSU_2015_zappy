/*
** SDL_event.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Thu Jun 16 14:44:04 2016 Thomas Beaudet
** Last update Thu Jun 16 16:50:33 2016 Thomas Beaudet
*/

#include <SDL2/SDL.h>
#include "graphical.h"

int			sdl_event(t_res *ress)
{
  int			state;

  state = 0;
  while (state == 0)
    {
      while (SDL_PollEvent(&ress->event))
	{
	  if (ress->event.type == SDL_QUIT)
	    {
	      state = 1;
	      sdl_quit();
	      return (1);
	    }
	}
    }
  return (0);
}