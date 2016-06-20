/*
** SDL_test_textures.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Fri Jun 17 16:34:25 2016 Thomas Beaudet
** Last update Mon Jun 20 13:57:37 2016 Thomas Beaudet
*/

#include <SDL2/SDL.h>
#include <stdio.h>

int			main()
{
  int			state;
  SDL_Event		*event;

  state = 1;
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window		*window;

  window = SDL_CreateWindow("Graphical Client",
			    SDL_WINDOWPOS_UNDEFINED,
			    SDL_WINDOWPOS_UNDEFINED,
			    640, 480, 0);
  printf(" create win : Ok");


  SDL_Renderer		*renderer;
  SDL_Texture		*texture;

  renderer = SDL_CreateRenderer(window, -1, 0);
  printf(" renderer : Ok");
  texture = SDL_CreateTexture(renderer,
			      SDL_PIXELFORMAT_ARGB8888,
			      SDL_TEXTUREACCESS_STATIC,
			      640, 480);
  printf(" texture : Ok");

  Uint32		*pixels;

  //  pixels = malloc (sizeof(Uint32));
  pixels = (Uint32*) malloc(640 * 480 * sizeof(Uint32));
  memset(pixels, 255, 640 * 480 * sizeof(Uint32));
  printf(" memset 1 : Ok");

  while (state)
    {
      SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));
      printf(" update texture : Ok");
      SDL_WaitEvent(event);
      printf(" wait event : Ok");

      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      printf(" render copy : Ok");
      SDL_RenderPresent(renderer);
      printf(" render present : Ok");
    }
  free(pixels);
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return (0);
}
