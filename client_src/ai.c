/*
** ai.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 10 14:31:29 2016 Gabriel Goude
** Last update Fri Jun 17 17:04:56 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <circular_buffer/circular_buffer.h>
#include "resources.h"

int			prend(t_infos *infos, char *str);
int			voir(t_infos *infos);
int			inventaire(t_infos *infos);

int			ai(t_infos *infos)
{
  char			*msg;

  voir(infos);
  msg = read_buf(infos);
  if (msg)
    printf("%s", msg);
  prend(infos, "nourriture");
  msg = read_buf(infos);
  if (msg)
    printf("%s", msg);
  inventaire(infos);
  msg = read_buf(infos);
  if (msg)
    printf("%s", msg);
  return (RETURN_SUCCESS);
}

/*
** AI Will be like :
** WHILE (NOT MORT)
**	update <- get messages and update local memory
**	actions <- AI instructions
**	send <- send instructions
*/
