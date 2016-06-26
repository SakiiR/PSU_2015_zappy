/*
** write_elem_case.c for write_elem_case in /home/aknin_k/rendu/tek2/reseau/zappy/PSU_2015_zappy/server_src
** 
** Made by Karine Aknin
** Login   <aknin_k@epitech.net>
** 
** Started on  Thu Jun 23 18:40:06 2016 Karine Aknin
** Last update Sun Jun 26 17:44:58 2016 Erwan Dupard
*/

#include "server.h"

extern t_ressource_name_c	g_correspondances[];

int				write_joueur(char *message, int i,
					     char *str)
{
  int				it;

  it = 0;
  while (str[it])
    {
      message[i] = str[it];
      i++;
      it++;
    }
  return (i);
}

int				write_characters(char *message, t_case *cases,
						 t_client *client, int i)
{
  int				nb_characters;

  nb_characters = 0;
  nb_characters = count_character(cases);
  if (nb_characters > 0)
    {
      while (nb_characters > 0)
	{
	  i = write_joueur(message, i , " joueur");
	  nb_characters--;
	}
    }
  return (i);
  (void)client;
}

int				edit_message_ressource(char *message, int i,
						       int it, int ressources)
{
  char				*name_ressource;
  int				a;

  a = -1;
  while (g_correspondances[++a].name)
    {
      if (g_correspondances[a].type_identifier == (unsigned int)it)
	{
	  name_ressource = g_correspondances[a].name;
	  break ;
	}
    }
  if (name_ressource)
    {
      while (ressources > 0)
	{
	  a = 0;
	  message[i] = ' ';
	  i++;
	  while (name_ressource[a])
	    message[i++] = name_ressource[a++];
	  ressources--;
	}
    }
  return (i);
}

int				write_ressources(char *message, t_case *cases,
						 int i)
{
  int				ressources;
  int				it;

  it = 0;
  while (it < NUMBER_OF_TYPES)
    {
      ressources = cases->quantities[it];
      if (ressources > 0)
	i = edit_message_ressource(message, i, it, ressources);
      it++;
    }
  return (i);
}

int				write_elem_case(char *message, t_case *cases,
						t_client *client, int i)
{
  i = write_characters(message, cases, client, i);
  i = write_ressources(message, cases, i);
  message[i] = ',';
  i++;
  return (i);
}
