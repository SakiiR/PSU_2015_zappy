/*
** run_sdl.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Tue Jun 14 12:41:33 2016 Thomas Beaudet
** Last update Wed Jun 15 17:14:43 2016 Thomas Beaudet
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "SDL_ressources.h"

int		run(t_sdl *s)
{
  init_sdl();
  while (s->action)
    {
      event_sdl(s);
      /* run loop */
    }
}

int		set_vals(t_sdl *s)
{
  s->action = 1;
  s->screen = SDL_CreateWindow(640, 480, 32, SDL_HWSURFACE
			    | SDL_RESIZABLE | SDL_DOUBLEBUF);
  if (s->screen == NULL)
    {
      fprintf(stderr, "Problem ecountered while setting video mode -> SDL Error : %s\n",
	      SDL_GetError());
      exit (EXIT_FAILURE);
    }
  SDL_WM_SetCaption("ZAPPY UNITED", NULL);
}

int		main()
{
  t_sdl		world;

  memset(&world, 0, sizeof(t_sdl));
  printf("memset : ok\n");
  set_vals(&world);
  printf("set_vals : ok\n");
  //  run(&world);
  printf("run : ok\n");
  SDL_quit(&world);
  printf("sdl_quit : ok\n");
  return (0);
}
