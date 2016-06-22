/*
** xlisten.c for xlisten in /home/billot_t/TEK2/PSU_2015_myftp
** 
** Made by Thomas Billot
** Login   <billot_t@epitech.net>
** 
** Started on  Tue May 10 14:17:42 2016 Thomas Billot
** Last update Wed Jun 22 14:22:06 2016 Erwan Dupard
*/

#include "myftp.h"

int		xlisten(int sockfd, int backlog)
{
  if (listen(sockfd, backlog) == -1)
    {
      fprintf(stderr, "Error in xlisten(): %s\n", strerror(errno));
      return (-1);
    }
  return (0);
}
