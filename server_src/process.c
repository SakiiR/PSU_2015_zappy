/*
** process.c for myirc in /home/dupard_e/rendus/PSU_2015_myirc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue May 17 09:26:36 2016 Erwan Dupard
** Last update Sun Jun 26 17:14:23 2016 Karine Aknin
*/

#include "server.h"

static int			handle_clients_input(t_server *server, fd_set *set_in)
{
  int				i;
  int				size_read;
  char				buffer[PAGE_SIZE];
  char				*next_message;

  i = -1;
  while (++i < MAX_CLIENTS)
    {
      if (FD_ISSET(server->clients[i].socket, set_in))
	{
	  size_read = read(server->clients[i].socket, buffer, PAGE_SIZE);
	  buffer[size_read] = 0;
	  write_to_buffer(&(server->clients[i].buffer_in), buffer, size_read);
	  while ((next_message = get_next_message(&(server->clients[i].buffer_in)))
		 && next_message[0])
	    {
	      if (handle_command(next_message, server,
				 &server->clients[i]) == RETURN_FAILURE)
		return (RETURN_FAILURE);
	      free(next_message);
	    }
	  free(next_message ? next_message : NULL);
	}
    }
  return (RETURN_SUCCESS);
}

static int			handle_server_output(t_server *server, fd_set *set_out)
{
  int				i;
  char				*next_message;
  char				*data;

  i = -1;
  while (++i < MAX_CLIENTS)
    {
      if (FD_ISSET(server->clients[i].socket, set_out))
	{
	  data = read_data_from_buffer(&(server->clients[i].buffer_out));
	  free(data);
	  while ((next_message =
		  get_next_message(&(server->clients[i].buffer_out)))
		 && next_message[0])
	    {
	      write(server->clients[i].socket, next_message, strlen(next_message));
	      free(next_message);
	    }
	  if (next_message)
	    free(next_message);
	}
    }
  return (RETURN_SUCCESS);
}

static int			add_client(t_server *server)
{
  socklen_t			length;
  int				i;
  t_client			*new_client;

  new_client = NULL;
  i = -1;
  while (++i < MAX_CLIENTS)
    {
      if (server->clients[i].socket == 0)
	new_client = &server->clients[i];
    }
  if (new_client == NULL)
    return (RETURN_FAILURE);
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

int				process_server(t_server *server)
{
  fd_set			si;
  fd_set			so;

  server->game_data.next_drone_id = 1;
  server->game_data.pending_actions = NULL;
  set_time_speed(server);
  while (1)
    {
      if (select_sockets(server, &si, &so) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      if (FD_ISSET(server->socket, &si))
	{
	  if (add_client(server) == RETURN_FAILURE)
	    return (RETURN_FAILURE);
	}
      if (handle_clients_input(server, &si) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      if (handle_events(server) == RETURN_FAILURE)
      	return (RETURN_FAILURE);
      if (handle_server_output(server, &so) == RETURN_FAILURE)
	return (RETURN_FAILURE);
   }
  return (RETURN_SUCCESS);
}
