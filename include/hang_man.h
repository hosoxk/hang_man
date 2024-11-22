/* -------------------------------------------------------------------------- */
/*                                                                            */
/*   File Name   : hang_man.h                                                 */
/*                                                                            */
/*   Author      : Yoni De Rudder                                             */
/*   Created     : 2024/11/15 16:05:49                                        */
/*   Updated     : 2024/11/15 16:05:49                                        */
/*                                                                            */
/* -------------------------------------------------------------------------- */

#ifndef HANG_MAN_H
# define HANG_MAN_H

# define FILENAME "./sources/words.txt"
# define MAX_LINE 200
#include "./libft/libft.h"
#include "./libft/sources/ft_printf/ft_printf.h"
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <readline/readline.h>

typedef struct	s_word
{
	char	*str;
	char	*matrice;
	int	strikes;
	bool	entered_corr_c;
}	t_word;

char	*check_args(int argc, char **argv);
char	*get_random_word(void);
bool	init_word(t_word *word);
void	free_data(t_word *word);
bool	check_input(t_word *word, char *input);
bool	check_matrice(t_word *word);
void	print_header(void);
void	print_game_over(void);
void	print_succes(void);

# endif
