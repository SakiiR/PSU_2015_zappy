/*
** xclose.c for xclose in /home/billot_t/TEK2/PSU_2015_myftp
** 
** Made by Thomas Billot
** Login   <billot_t@epitech.net>
** 
** Started on  Tue May 10 14:32:01 2016 Thomas Billot
** Last update Wed Jun 15 17:27:26 2016 Thomas Billot
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "xfunc.h"

int		xclose(int fd)
{
  if (close(fd) == -1)
    {
      perror("close");
      return (-1);
    }
  return (0);
}
