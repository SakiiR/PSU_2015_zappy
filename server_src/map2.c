/*
** map2.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Thu Jun  9 19:15:32 2016 Barthelemy Gouby
*/

#include "server.h"

void					place_character_randomly(t_map *map, t_character *character)
{
  t_u64					index;

  index = rand() % (map->width * map->height);
}
