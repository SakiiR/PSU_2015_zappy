/*
** map2.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun  9 19:15:32 2016 Barthelemy Gouby
** Last update Tue Jun 14 16:20:12 2016 Erwan Dupard
*/

#include "resources.h"

int					place_character_randomly(t_map *map, t_character *character)
{
  t_u64					index;

  index = rand() % (map->width * map->height);
  return (RETURN_SUCCESS);
}
