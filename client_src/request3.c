/*
** request3.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 16:43:03 2016 Gabriel Goude
** Last update Wed Jun 08 16:47:02 2016 Gabriel Goude
*/

#include <unistd.h>
#include <stdlib.h>
#include "drone.h"

int			connect_nbr(t_client_settings *settings)
{
  write(settings->s, "connect_nbr\n", 12);
  return (EXIT_SUCCESS);
}
