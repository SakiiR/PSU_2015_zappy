/*
** generate_message_voir.c for generate_message_voir in /home/aknin_k/rendu/tek2/reseau/zappy/PSU_2015_zappy/server_src
** 
** Made by Karine Aknin
** Login   <aknin_k@epitech.net>
** 
** Started on  Thu Jun 23 17:39:05 2016 Karine Aknin
** Last update Sat Jun 25 23:41:34 2016 Erwan Dupard
*/

#include "server.h"

int					count_character(t_case *cases)
{
  int					i;
  t_character				*tmp;

  i = 0;
  tmp = cases->characters;
  while (tmp)
   {
     tmp = tmp->next_in_case;
     i++;
    }
  return (i);
}

int					count_ressources(t_case *cases)
{
  int					i;
  t_u64					size;

  i = 0;
  size = 0;
  while (i < NUMBER_OF_TYPES)
    {
      size += cases->quantities[i];
      i++;
    }
  return (size);
}

int					count_elem(t_case **cases)
{
  int					size;
  int					i;

  size = 0;
  i = 0;
  while (cases && cases[i])
    {
      size += count_character(cases[i]);
      size += count_ressources(cases[i]);
      i++;
    }
  size = size * 100;
  if (!size)
    size = i * 10;
  return (size);
}

int					generate_message_voir(t_client *client, t_case **cases)
{
  int					i;
  char					*message;
  int					size;
  int					it;

  i = 0;
  it = 1;
  size = count_elem(cases);
  if (!(message = malloc(sizeof(*message) * (size))))
    return (RETURN_FAILURE);
  bzero(message, size);
  message[0] = '{';
  while (cases && cases[i])
    {
      it = write_elem_case(message, cases[i], client, it);
      i++;
    }
  message[it] = '}';
  message[++it] = '\n';
  message[++it] = '\0';
  write_to_buffer(&client->buffer_out, message, strlen(message));
  return (RETURN_SUCCESS);
}
