/*
** SDL_load_textures.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Tue Jun 21 12:17:09 2016 Thomas Beaudet
** Last update Tue Jun 21 13:59:58 2016 Thomas Billot
*/

#include "graphical.h"

SDL_Surface			*load_bmp(const char *file)
{
  SDL_Surface		*bmp;

  if ((bmp = SDL_LoadBMP(file)) == NULL)
    {
      fprintf(stderr,
              "Problem encountered while loading bmp -> SDL Error : %s\n",
              SDL_GetError());
      return (NULL);
    }
  return (bmp);
}

SDL_Texture			*create_texture(t_render *ress, SDL_Surface *bmp)
{
  SDL_Texture		*texture;

  if ((texture = SDL_CreateTextureFromSurface(ress->rend, bmp)) == NULL)
    {
      fprintf(stderr,
	      "Problem encountered while creating texture -> SDL Error : %s\n",
	      SDL_GetError());
      return (NULL);
    }
  return (texture);
}

int				display_texture(t_render *ress,
						SDL_Surface *bmp,
						SDL_Texture *texture)
{
  if (ress->rend)
    {
      ress->dest_rect.x = WIN_X / 2 - bmp->w / 2;
      ress->dest_rect.y = WIN_Y / 2 - bmp->h / 2;
      ress->dest_rect.w = bmp->w;
      ress->dest_rect.h = bmp->h;
      SDL_RenderCopy(ress->rend, texture, NULL, &ress->dest_rect);
      SDL_RenderPresent(ress->rend);
      SDL_DestroyTexture(texture);
    }
  else if (!ress->rend)
    {
      fprintf(stderr,
	      "Problem encountered while finding renderer -> SDL Error : %s\n",
	      SDL_GetError());
      return (-1);
    }
  return (0);
}
