/*
** network.h for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 11:07:28 2016 Thomas Billot
** Last update Mon Jun 13 17:17:05 2016 Thomas Billot
*/

#ifndef NETWORK_H_
# define NETWORK_H_

#define SOCKET_ERROR -1

typedef int t_socket;
typedef struct sockaddr_in t_sockaddr;
typedef struct in_addr t_inaddr;
typedef struct protoent t_protocol;

int		setup_networking(int port);

#endif /* !NETWORK_H_ */
