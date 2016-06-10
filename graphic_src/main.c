/*
** main.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 14:41:15 2016 Thomas Billot
** Last update Fri Jun 10 13:34:49 2016 Thomas Billot
*/

#include "graphical.h"
#include "network.h"
#include "xfunc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static t_ptr	ftab[] =
  {
    {MSZ, 3},
    {BCT, 3},
    {TNA, 3},
    {PNW, 3},
    {PPO, 3},
    {PLV, 3},
    {PEX, 3},
    {PBC, 3},
    {PIC, 3},
    {PIE, 3},
    {PFK, 3},
    {PDR, 3},
    {PGT, 3},
    {PDI, 3},
    {ENW, 3},
    {EHT, 3},
    {EBO, 3},
    {EBI, 3},
    {SGT, 3},
    {SEG, 3},
    {SMG, 3},
    {SUC, 3},
    {SBP, 3},
    {NULL, 0}
  };

int		main(int argc, char *argv[])
{
  char		*buff;
  char		**cmd;
  int		i;
  
  if (argc != 2)
    {
      fprintf(stderr, "Usage: ./bin/console [port]\n");
      return (-1);
    }
  setup_networking(atoi(argv[1]));
  while ((buff = get_next_line(0)) != NULL)
    {
      if ((cmd = my_str_to_wordtab(buff, " ")) == NULL)
	return (-1);
      i = -1;
      while (ftab[++i].id != NULL)
	{
	  if (cmd[0] != NULL)
	    {
	      if (strcmp(cmd[0], ftab[i].id) == 0)
		printf("Command found: %s\n", ftab[i].id);
	    }
	}
      free(buff);
      free_word_tab(cmd);
    }
  return (0);
}
