/*
** SDL_test_textures.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Fri Jun 17 16:34:25 2016 Thomas Beaudet
** Last update Fri Jun 17 16:58:00 2016 Thomas Beaudet
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


  SDL_Renderer		*renderer;
  SDL_Texture		*texture;

  renderer = SDL_CreateRenderer(window, -1, 0);
  texture = SDL_CreateTexture(renderer,
			      SDL_PIXELFORMAT_ARGB8888,
			      SDL_TEXTUREACCESS_STATIC,
			      640, 480);

  Uint32		*pixels;

  pixels = (Uint32*)640 * 480;
  memset(pixels, 255, 640 * 480 * sizeof(Uint32));

  while (state)
    {
      SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));
      SDL_WaitEvent(&event);

      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      SDL_RenderPresent(renderer);
    }
  free(pixels);
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyPresent(window);
  SDL_Quit();

  return (0);
}
