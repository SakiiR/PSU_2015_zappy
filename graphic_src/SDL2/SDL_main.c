/*
** SDL_main.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Thu Jun 16 11:24:43 2016 Thomas Beaudet
** Last update Thu Jun 16 15:34:55 2016 Thomas Beaudet
*/

#include <SDL2/SDL.h>
#include "SDL_ressources.h"

int			Draw(t_res *ress)
{
  ress->rect.w = 1;
  ress->rect.h = 1;
  for (ress->i = 0; ress->i < 640; ress->i++)
    {
      for (ress->j = 0; ress->j < 480; ress->j++)
	{
	  ress->rect.x = ress->i;
	  ress->rect.y = ress->j;
	  if ((ress->result = SDL_RenderReadPixels(ress->rend,
					  &ress->rect, SDL_PIXELFORMAT_ARGB8888,
					  &ress->value, 32 * 640)) < 0)
	    {
	      fprintf(stderr, "Lecture error -> SDL Error : %s\n", SDL_GetError());
	      return (1);
	    }
	  SDL_SetRenderDrawColor(ress->rend, 255, 255, 255, 0);
	  SDL_RenderDrawPoint(ress->rend, ress->i, ress->j);
	}
      printf("%d\n", ress->i);
    }
  SDL_RenderPresent(ress->rend);
  return (0);
}

int			main()
{
  t_res			res;

  memset(&res, 0, sizeof(t_res));
  printf("memset : ok\n");
  sdl_init();
  printf("init : ok\n");
  sdl_create_win(&res);
  printf("create_win : ok\n");
  draw_backg(&res);
  printf("backg : ok\n");
  //  put_delay(4000);
  printf("delay : ok\n");
  sdl_event(&res);
  Draw(&res);
  printf("Draw : ok\n");
  put_delay(4000);
  printf("event : ok\n");
  sdl_quit();
  return (0);
}
