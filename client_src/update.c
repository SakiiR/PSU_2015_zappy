/*
** update.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 17 16:56:28 2016 Gabriel Goude
** Last update Sun Jun 26 17:33:20 2016 Erwan Dupard
*/

#include "resources.h"

int				update(t_infos *infos, int (**fct)(t_infos *, char *))
{
  char				*msg;

  while ((msg = read_buf(infos)) != NULL)
    {
      if (strncmp(msg, "mort\n", 5) != 0 && strncmp(msg, "broadcast", 9) != 0)
	{
	  if (handle_msg(infos, msg, fct) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
      else
	printf("%s", msg);
    }
  return (RETURN_SUCCESS);
}

int				send_update(t_infos *infos)
{
  char				*msg;
  int				retval;

  fill_set(infos);
  while ((retval = select(infos->socket + 1,
			  NULL,
			  &(infos->select.wfds),
			  NULL,
			  &(infos->select.tv))) < 0)
    fill_set(infos);
  if (FD_ISSET(infos->socket, &(infos->select.wfds)))
    {
      while ((msg = get_next_message(&(infos->buffer))) && msg[0])
	{
	  if (!msg)
	    return (RETURN_FAILURE);
	  write(infos->socket, msg, strlen(msg));
	  free(msg);
	}
    }
  return (RETURN_SUCCESS);
}
