/*
** ai.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 10 14:31:29 2016 Gabriel Goude
** Last update Fri Jun 17 14:16:54 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <circular_buffer/circular_buffer.h>
#include "resources.h"

int			ai(t_infos *infos)
{
  (void)infos;
  return (RETURN_SUCCESS);
}

/*
 * Qu-est-ce que ce code fou ici ? :)
 */
void			fill_set(t_infos *infos)
{
  infos->select.tv.tv_usec = 0;
  infos->select.tv.tv_sec = 1;
  FD_ZERO(&(infos->select.rfds));
  FD_ZERO(&(infos->select.wfds));
  FD_SET(infos->socket, &(infos->select.rfds));
  FD_SET(infos->socket, &(infos->select.wfds));
}
