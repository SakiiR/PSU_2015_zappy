/*
** main.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 14:41:15 2016 Thomas Billot
** Last update Thu Jun  9 16:51:15 2016 Thomas Billot
*/

#include "graphical.h"
#include "xfunc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int		init_ftab(t_ptr *ftab)
{
  *ftab = {{MSZ, 3},
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
	   {SBP, 3}};
  return (0);
}


int		main(int argc, char *argv[])
{
  char		*buff;
  t_ptr		ftab;
  
  (void)argc;
  (void)argv;
  init_ftab(&ftab);
  while ((buff = get_next_line(0)) != NULL)
    {
      if (strncmp(buff, ftab.id, ftab.s_id))
	printf("Command found: %s", ftab.id);
      free(buff);
    }
  return (0);
}
