/*
** request.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 15:17:57 2016 Gabriel Goude
** Last update Fri Jun 17 16:33:07 2016 Gabriel Goude
*/

#include <unistd.h>
#include <stdlib.h>
#include "resources.h"

int			avance(t_infos *infos)
{
  if (write_buf(infos, "avance") == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (add_elem(infos, AVANCE) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

int			droite(t_infos *infos)
{
  if (write_buf(infos, "droite") == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (add_elem(infos, DROITE))
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

int			gauche(t_infos *infos)
{
  if (write_buf(infos, "gauche") == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (add_elem(infos, GAUCHE) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

int			voir(t_infos *infos)
{
  if (write_buf(infos, "voir") == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (add_elem(infos, VOIR) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

int			inventaire(t_infos *infos)
{
  if (write_buf(infos, "inventaire") == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (add_elem(infos, INVENTAIRE) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
