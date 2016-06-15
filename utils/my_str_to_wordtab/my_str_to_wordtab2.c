/*
** my_str_to_wordtab2.c for myirc in /home/dupard_e/rendus/PSU_2015_myirc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed May 18 17:12:06 2016 Erwan Dupard
** Last update Tue Jun 14 17:24:33 2016 Erwan Dupard
*/

#include "my_str_to_wordtab.h"

unsigned int				wordtab_length(const char **tab)
{
  unsigned int				i;

  i = 0;
  while (tab && tab[i])
    ++i;
  return (i);
}
