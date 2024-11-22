#include "../include/hang_man.h"

int	main(int argc, char **argv)
{
	t_word	word;
	char	*input;

	if (!(word.str = check_args(argc, argv)))
		return (ft_printf("Correct usage: enter \"random\" or enter own word\n"), 1);
	print_header();
	init_word(&word);
	input = NULL;
	while (1)
	{
		if (check_matrice(&word))
		{
			break ;
		}
		input = readline("Enter letter or \"exit\"\n");
		check_input(&word, input);
	}
	free_data(&word);
	return (0);
}
