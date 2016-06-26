/*
** ai.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 10 14:31:29 2016 Gabriel Goude
** Last update Sun Jun 26 17:13:33 2016 Erwan Dupard
*/

#include <stdlib.h>
#include <circular_buffer/circular_buffer.h>
#include "resources.h"

int			ai(t_infos *infos)
{
  static int		i = 0;

  if (!i)
    {
      gauche(infos);
      i++;
    }
  avance(infos);
  return (RETURN_SUCCESS);
}
