/*
** SDL_init.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 17:59:09 2016 Thomas Beaudet
** Last update Wed Jun 22 14:37:00 2016 Thomas Billot
*/

#include <stdio.h>
#include "graphical.h"

int			sdl_init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
      fprintf(stderr,
	      "Problem ecountered while initializing SDL --> SDL Error : %s\n",
	      SDL_GetError());
      exit (EXIT_FAILURE);
    }
  return (RETURN_SUCCESS);
}
