/*
** init_sdl.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Mon Jun 13 14:15:31 2016 Thomas Beaudet
** Last update Mon Jun 13 14:16:18 2016 Thomas Beaudet
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void		init_sdl()
{
  if ((SDL_Init(SDL_INIT_VIDEO)) != 0)
    {
      fprintf(stderr, "\nProblem when SDL_init: %s\n", SDL_GetError());
      exit (EXIT_FAILURE);
    }
}
