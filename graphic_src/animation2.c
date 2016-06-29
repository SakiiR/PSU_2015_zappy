/*
** animation2.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Sat Jun 25 15:22:58 2016 Thomas Beaudet
** Last update Sun Jun 26 17:42:08 2016 Thomas Beaudet
*/

#include "graphical.h"

int			get_frame(t_anim *anim)
{
  return (anim->beg_frame + (SDL_GetTicks() / anim->delay) % anim->nb_frames);
}

void			setup_sprite(t_sprite *sprite,
				     int x, int y,
				     t_charset *charset_, int begin_frame)
{
  sprite->pos.x = (Sint16) x;
  sprite->pos.y = (Sint16) y;
  sprite->charset = charset_;
  set_anim(&sprite->anim, begin_frame, 1, 1);
  sprite->way = NORTH;
  sprite->state = STOP;
}

void			display_sprite(t_render *ress, t_sprite *sprite)
{
  SDL_Rect		src;
  int			frame;

  frame = get_frame(&sprite->anim);
  get_src_charset(sprite->charset, &src, frame);
  SDL_RenderCopy(sprite->charset->charset_, &src, ress->screen, &sprite->pos);
}
