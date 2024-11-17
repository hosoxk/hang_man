#include "../include/hang_man.h"

void	free_data(t_word *word)
{
	if (word->str)
		free(word->str);
	if (word->matrice)
		free(word->matrice);
}
