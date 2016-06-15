/*
** event_sdl.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Tue Jun 14 12:33:59 2016 Thomas Beaudet
** Last update Wed Jun 15 15:30:34 2016 Thomas Beaudet
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "SDL_ressources.h"

void		event_sdl(t_sdl *s)
{
  while (SDL_PollEvent(&s->event))
    if (s->event.type == SDL_QUIT)
      s->action = 0;
    else if (s->event.type == SDL_QUIT)
      if (s->event.key.keysym.sym == SDLK_ESCAPE)
	s->action = 0;
}
