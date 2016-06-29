/*
** client.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed Jun 29 14:37:49 2016 Erwan Dupard
** Last update Wed Jun 29 16:25:44 2016 Barthelemy Gouby
*/

#include "server.h"

static void		init_client(t_client *client)
{
  client->host_name = NULL;
  client->server_name = NULL;
  client->socket = 0;
  client->character = NULL;
  client->type = UNSPECIFIED;
  initialize_buffer(&client->buffer_in, CIRC_PAGE_NBR * PAGE_SIZE);
  initialize_buffer(&client->buffer_out, CIRC_PAGE_NBR * PAGE_SIZE);
}

static t_client		*reallocate_clients(t_server *server)
{
  int			i;
  t_client		*new_clients;

  i = -1;
  while (server->clients[++i].host_name)
    ;
  if ((new_clients = malloc(sizeof(*new_clients) * (i + 2))) == NULL)
    return (NULL);
  i = -1;
  while (server->clients[++i].host_name)
    new_clients[i] = server->clients[i];
  init_client(&new_clients[i]);
  free(server->clients);
  server->clients = new_clients;
  server->client_pool_size++;
  return (&new_clients[i]);
}

int			add_client(t_server *server)
{
  socklen_t		length;
  int			i;
  t_client		*new_client;

  new_client = NULL;
  i = -1;
  while (++i < server->client_pool_size)
    {
      if (server->clients[i].socket == 0)
	new_client = &server->clients[i];
    }
  new_client = (new_client == NULL ? reallocate_clients(server) : new_client);
  if (new_client == NULL)
    return (RETURN_SUCCESS);
  length = sizeof(new_client->in);
  if ((new_client->socket = accept(server->socket,
				   (struct sockaddr *)&new_client->in,
				   &length)) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  new_client->type = UNSPECIFIED;
  printf("[^] New connection : %s:%d\n",
	 inet_ntoa(new_client->in.sin_addr),
	 ntohs(new_client->in.sin_port));
  write_to_buffer(&new_client->buffer_out, WELCOME, strlen(WELCOME));
  return (RETURN_SUCCESS);
}
