/*
** expulse.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Jun 20 15:45:12 2016 Erwan Dupard
** Last update Mon Jun 20 16:04:42 2016 Erwan Dupard
*/

#include "server.h"

t_expulse_case				g_expulse_case[] = {
  {NORTH, &expulse_north},
  {SOUTH, &expulse_south},
  {EAST, &expulse_est},
  {WEST, &expulse_west},
  {UNDEFINED, NULL}
};

void					expulse_north(int x, int y, int *new_x, int *new_y)
{
  *new_x = x;
  *new_y = y - 1;
}

void					expulse_south(int x, int y, int *new_x, int *new_y)
{
  *new_x = x;
  *new_y = y + 1;
}

void					expulse_est(int x, int y, int *new_x, int *new_y)
{
  *new_x = x + 1;
  *new_y = y;
}

void					expulse_west(int x, int y, int *new_x, int *new_y)
{
  *new_x = x - 1;
  *new_y = y;
}

int					expulse_player(t_map *map, t_character *character, e_orientation orientation)
{
  t_case				next_case;
  int					i;

  i = -1;
  next_case.characters = NULL;
  while (g_expulse_case[++i].type != UNDEFINED)
    {
      if (g_expulse_case[i].type == orientation)
	g_expulse_case[i].f(character->current_case->x,
			    character->current_case->y,
			    (int *)&next_case.x,
			    (int *)&next_case.y);
    }
  next_case.x = next_case.x % map->width;
  next_case.y = next_case.y % map->height;
  /*
   * Move player to next case and send to it the payload
   */
  return (RETURN_SUCCESS);
}
