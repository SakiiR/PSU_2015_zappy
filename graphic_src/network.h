/*
** network.h for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 11:07:28 2016 Thomas Billot
** Last update Tue Jun 14 14:59:31 2016 Thomas Billot
*/

#ifndef NETWORK_H_
# define NETWORK_H_

#include "graphical.h"
#include "../utils/circular_buffer/circular_buffer.h"
#include <arpa/inet.h>

# define RETURN_SUCESS (0)
# define RETURN_FAILURE (-1)

# define SOCKET_ERROR (-1)

typedef int t_socket;
typedef struct sockaddr_in t_sockaddr;
typedef struct in_addr t_inaddr;
typedef struct protoent t_protocol;

typedef struct				s_server
{
  t_socket			       	socket;
  t_sockaddr				in;
  t_circular_buffer			buffer_in;
  t_circular_buffer			buffer_out;
}					t_server;

int			launch_client(t_server *server);

#endif /* !NETWORK_H_ */
