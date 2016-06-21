/*
** SDL_destroy_texture.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Tue Jun 21 16:23:30 2016 Thomas Beaudet
** Last update Tue Jun 21 16:29:49 2016 Thomas Beaudet
*/

#include <graphical.h>

void			destroy_texture(t_texture *tex)
{
  int			i;

  i = 0;
  while (tex->textures[i])
    {
      SDL_DestroyTexture(tex->textures[i]);
      i++;
    }
}

void			destroy_bmps(t_texture *tex)
{
  int			i;

  i = 0;
  while (tex->bmps[i])
    {
      SDL_FreeSurface(tex->bmps[i]);
      i++;
    }
}
