/*
** handle1.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 17 16:52:53 2016 Gabriel Goude
** Last update Sun Jun 26 17:15:41 2016 Erwan Dupard
*/

#include <my_str_to_wordtab/my_str_to_wordtab.h>
#include "resources.h"

int				handle_avance(t_infos *infos, char *msg)
{
  int				add;

  (void)msg;
  add = infos->client->orientation == 2 ||
    infos->client->orientation == 3 ? -1 : 1;
  if (infos->client->orientation % 2 == 0)
    {
      if ((int)infos->client->y + add == -1)
	infos->client->y = infos->map->y - 1;
      else if (infos->client->y + add == infos->map->y)
	infos->client->y = 0;
      else
	infos->client->y = infos->client->y + add;
    }
  else
    {
      if ((int)infos->client->x + add == -1)
	infos->client->x = infos->map->x - 1;
      else if (infos->client->x + add == infos->map->x)
	infos->client->x = 0;
      else
	infos->client->x = infos->client->x + add;
    }
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_droite(t_infos *infos, char *msg)
{
  (void)msg;
  infos->client->orientation++;
  if (infos->client->orientation > 3)
    infos->client->orientation = 0;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_gauche(t_infos *infos, char *msg)
{
  (void)msg;
  infos->client->orientation--;
  if (infos->client->orientation < 0)
    infos->client->orientation = 3;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_inventaire(t_infos *infos, char *msg)
{
  char				**tab;
  char				**tab2;
  int				i;

  i = 0;
  if ((tab = my_str_to_wordtab(msg, "}")) == NULL)
    return (RETURN_FAILURE);
  if ((tab2 = my_str_to_wordtab(tab[0], "{")) == NULL)
    return (RETURN_FAILURE);
  free_word_tab(tab);
  if ((tab = my_str_to_wordtab(tab2[0], ",")) == NULL)
    return (RETURN_FAILURE);
  free_word_tab(tab2);
  while (tab[i])
    {
      if ((tab2 = my_str_to_wordtab(tab[i], " ")) == NULL)
	return (RETURN_FAILURE);
      infos->client->inventory[i] = atoi(tab2[1]);
      free_word_tab(tab2);
      i++;
    }
  free_word_tab(tab);
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_voir(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

