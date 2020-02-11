/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_rules.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/11 14:36:53 by videloff     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 16:40:43 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
**  - ligne de vitre commence et finit par un wall
**  - porte entouré deux murs opposés et deux sols opposés
**  - map entouré de mur
**  - au moins un floor
**  - au moins autant de clés que de portes
**  - map maximum de 50*50 blocks
**  - backtracking: verifier que la map est faisable, du beginning au ending
**                  et que les portes peuvent être ouvertes avec un nombre
**                  de clés suffisantes et accessibles.
*/

void	check_map_validity(env, file);
{

}