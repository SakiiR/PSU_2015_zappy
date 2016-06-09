/*
** graphical.h for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 14:43:41 2016 Thomas Billot
** Last update Thu Jun  9 16:15:27 2016 Thomas Billot
*/

#ifndef GRAPHICAL_H_
# define GRAPHICAL_H_

#define	MSZ "msz" /* Taille de la carte */
#define BCT "bct" /* Contenu de toute la carte (une case | toutes les cases) */
#define TNA "tna" /* Nom des équipes */
#define PNW "pnw" /* Connexion d'un nouveau joueur */
#define PPO "ppo" /* Position d'un joueur */
#define PLV "plv" /* Niveau d'un joueur */
#define PIN "pin" /* Inventaire d'un joueur */
#define PEX "pex" /* Expluse un joueur */
#define PBC "pbc" /* Un joueur fait un broadcast */
#define PIC "pic" /* Debut d'incantation pour tout les joueurs sur la case */
#define PIE "pie" /* Fin d'incantation avec resultat (1 ou 0) */
#define PFK "pfk" /* Le joueur pond un oeuf */   
#define PDR "pdr" /* Le joueur jete une ressource */
#define PGT "pgt" /* Le joueur prends une ressource */
#define PDI "pdi" /* Le joueur est mort de faim */
#define ENW "enw" /* L'oeuf a ete pondu sur la case par le joueur */
#define EHT "eht" /* L'oeuf eclos */
#define EBO "ebo" /* Un joueur s'est connecte pour l'oeuf */
#define EBI "ebi" /* L'oeuf eclos est mort de faim */
#define SGT "sgt" /* Demande l'unite de temps du serveur */
#define SEG "seg" /* Fin du jeu, l'equipe donne gagne */
#define SMG "smg" /* Message du serveur */
#define SUC "suc" /* Commande du serveur */
#define SBP "sbp" /* Mauvais parametres de commande */

typedef struct		s_ptr
{ 
  const char		*id;
  const int		s_id = 3;
  //  int			(*f)(t_option *);
}			t_ptr;

/* !GRAPHICAL_H_ */
