/*
** my_str_to_wordtab.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun 14 17:23:39 2016 Erwan Dupard
** Last update Sun Jun 26 16:09:24 2016 Erwan Dupard
*/

#ifndef MY_STR_TO_WORDTAB_H_
# define MY_STR_TO_WORDTAB_H_

# include <stdlib.h>
# include <stdio.h>

void					free_word_tab(char **tab);
char					**my_str_to_wordtab(const char *str,
							    const char *forbidden);

#endif /* ! MY_STR_TO_WORDTAB_H_ */
