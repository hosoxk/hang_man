#include "../include/hang_man.h"

int	main(int argc, char **argv)
{
	t_word	word;

	if (!(word.str = check_args(argc, argv)))
		return (ft_printf("Correct usage: enter \"random\" or enter own word\n"), 1);
	init_word(&word);
/*	while (1)
	{

	}*/
	free_data(&word);
	return (0);
}
