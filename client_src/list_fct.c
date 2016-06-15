/*
** list_fct.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 14 14:26:33 2016 Gabriel Goude
** Last update Tue Jun 14 17:13:57 2016 Erwan Dupard
*/

#include <stdlib.h>
#include "resources.h"

int				add_elem(t_infos *infos, int id)
{
  t_request			*request;
  t_request			*tmp;

  if ((request = malloc(sizeof(t_request))) == NULL)
    return (RETURN_FAILURE);
  request->request = id;
  request->next = NULL;
  tmp = infos->request;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (tmp)
    tmp->next = request;
  else
    infos->request = request;
  return (RETURN_SUCCESS);
}

int				remove_elem(t_infos *infos)
{
  t_request			*request;

  if (infos->request)
    {
      request = infos->request->next;
      free(infos->request);
      infos->request = request;
    }
  return (RETURN_SUCCESS);
}
