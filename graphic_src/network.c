/*
** network.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 16:59:16 2016 Thomas Billot
** Last update Mon Jun 13 17:17:26 2016 Thomas Billot
*/

#include "network.h"
#include "xfunc.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int			setup_networking(int port)
{
  t_sockaddr		sin;
  t_socket		sock;
  t_protocol		*pe;

  if ((pe = getprotobyname("TCP")) == NULL)
    {
      fprintf(stderr, "Error in getprotobyname(): %s\n", strerror(errno));
      return (-1);
    }
  if ((sock = xsocket(AF_INET, SOCK_STREAM, pe->p_proto)) == SOCKET_ERROR)
    return (-1);
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_port = htons(port);
  if (xconnect(sock, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    {
      if (xclose(sock) == -1)
	return (-1);
      return (-1);
    }    
  return (sock);
}
