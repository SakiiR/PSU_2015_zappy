/*
** main.c for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Sat Jun  4 17:48:27 2016 Erwan Dupard
** Last update Fri Jun 10 16:56:50 2016 Barthelemy Gouby
*/

#include "server.h"

static t_client			*init_clients(t_client *clients)
{
  int				i;

  i = -1;
  while (++i < MAX_CLIENTS)
    {
      clients[i].socket = 0;
      clients[i].host_name = NULL;
      clients[i].server_name = NULL;
      if (initialize_buffer(&clients[i].buffer_in,
			    BUFFER_SIZE) == RETURN_FAILURE)
	return (NULL);
      if (initialize_buffer(&clients[i].buffer_out,
			    BUFFER_SIZE) == RETURN_FAILURE)
	return (NULL);
    }
  return (clients);
}

static int			initialize_socket(t_server *server)
{
  if ((server->clients = malloc(sizeof(*server->clients) *
				MAX_CLIENTS)) == NULL)
    return (RETURN_FAILURE);
  if ((server->socket = socket(AF_INET, SOCK_STREAM, 0)) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  server->in.sin_family = AF_INET;
  server->in.sin_addr.s_addr = INADDR_ANY;
  server->in.sin_port = htons(server->port);
  if (bind(server->socket,
	   (struct sockaddr *)&server->in,
	   sizeof(server->in)) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (listen(server->socket, 10) == -1)
    return (RETURN_FAILURE);
  printf("[^] Listenning on port %d\n", server->port);
  if (!(server->clients = init_clients(server->clients)))
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

static void			close_connection(t_server *server)
{
  int				i;

  i = -1;
  while (i < MAX_CLIENTS)
    {
      if (server->clients[i].socket > 0)
	close(server->clients[i].socket);
      server->clients[i].socket = 0;
      free(server->clients[i].buffer_in.memory);
      free(server->clients[i].buffer_out.memory);
    }
  close(server->socket);
  free(server->clients);
}

int				main(int argc, char **argv)
{
  t_server			server;

  if (get_options(argc, argv, &server) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  /* printf("OPTIONS!\n"); */
  /* printf("options->port : %d\n", options.port); */
  /* printf("options->world_x : %d\n", options.world_x); */
  /* printf("options->world_y : %d\n", options.world_y); */
  /* printf("options->max_clients : %d\n", options.max_clients); */
  /* printf("options->speed : %d\n", options.speed); */
  /* printf("options->teams : %p\n", (void *)options.teams); */
  /* printf("options->nbr_of_team : %i\n", options.nbr_of_teams); */

  if (initialize_map(&server.game_data.map) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  initialize_ressources(&server);
  /* text_display_map(&server.map); */

  if (initialize_socket(&server) == RETURN_FAILURE)
    {
      printf("[-] Failed to initialize connection ..\n");
      return (RETURN_FAILURE);
    }
  if (process_server(&server) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  close_connection(&server);

  return (RETURN_SUCCESS);
}
