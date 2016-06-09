/*
** main.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 14:41:15 2016 Thomas Billot
** Last update Thu Jun  9 16:17:30 2016 Thomas Billot
*/

#include "graphical.h"

int		init_ftab(t_ptr *ftab)
{
  ftab = {{MSZ},
	  {BCT},
	  {TNA},
	  {PNW},
	  {PPO},
	  {PLV},
	  {PEX},
	  {PBC},
	  {PIC},
	  {PIE},
	  {PFK},
	  {PDR},
	  {PGT},
	  {PDI},
	  {ENW},
	  {EHT},
	  {EBO},
	  {EBI},
	  {SGT},
	  {SEG},
	  {SMG},
	  {SUC},
	  {SBP}};
}


int		main(int argc, char *argv[])
{
  char		*buff;
  t_ptr		ftab;
  
  (void)argc;
  (void)argv;
  while ((buff = get_next_line(0)) != NULL)
    {
      if (strncmp(buff, ftab.id, ftab.s_id))
	printf("Command found: %s", ftab.id);
      free(buff);
    }
  return (0);
}
