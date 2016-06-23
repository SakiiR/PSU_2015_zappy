/*
** handle1.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 17 16:52:53 2016 Gabriel Goude
** Last update Thu Jun 23 15:39:56 2016 Gabriel Goude
*/

#include "resources.h"
#include <my_str_to_wordtab/my_str_to_wordtab.h>

int				handle_avance(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_droite(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_gauche(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_inventaire(t_infos *infos, char *msg)
{
  char				**tab;
  char				**tab2;
  int				i;

  i = 0;
  tab = my_str_to_wordtab(msg, "}");
  tab2 = my_str_to_wordtab(tab[0], "{");
  free_word_tab(tab);
  tab = my_str_to_wordtab(tab2[0], ",");
  free_word_tab(tab2);
  while (tab[i])
  {
    tab2 = my_str_to_wordtab(tab[i], " ");
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

