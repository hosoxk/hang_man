#include "../include/hang_man.h"

bool	check_matrice(t_word *word)
{
	int	i;

	i = 0;
	while (word->matrice[i] != '\0')
	{
		if (word->matrice[i] == '_')
			return (false);
		i++;
	}
	print_succes();
	return (true); //word completed
}

static void	use_input(t_word *word, char c)
{
	int	i;

	word->entered_corr_c = false;
	i = 0;
	while (word->str[i] != '\0')
	{
		if (word->str[i] == ft_tolower(c) || word->str[i] == ft_toupper(c))
		{
			word->matrice[i] = ft_tolower(c);
			word->entered_corr_c = true;
		}
		i++;
	}
	ft_printf("%s\n", word->matrice);
}

static void	check_strikes(t_word *word)
{
	word->strikes++;
	switch (word->strikes)
	{
		case 1:
			ft_printf("____\n|/   |\n|\n|\n|\n|\n|\n|_____\n");
			break ;
		case 2:
			ft_printf(" ____\n|/   |\n|   (_)\n|\n|\n|\n|\n|_____\n");
			break ;
		case 3:
			ft_printf("____\n|/   |\n|   (_)\n|    |\n|    |\n|\n|\n|_____\n");
			break ;
		case 4:
			ft_printf("____\n|/   |\n|   (_)\n|   \\|/\n|    |\n|\n|\n|_____\n");
			break ;
		case 5:
			ft_printf("____\n|/   |\n|   (_)\n|   \\|/\n|    |\n|   / \\\n|\n|_____\n");
			free_data(word);
			print_game_over();
			exit(0);
	}
}

bool	check_input(t_word *word, char *input)
{
	char	c;

	if (!input)
		return (false);
	if (!(ft_strcmp(input, "exit")))
	{
		ft_printf("Exiting program\n");
		free_data(word);
		exit(1);
	}
	if (ft_strlen(input) != 1)
		return (false);
	c = input[0];
	if (!(ft_isalpha((int) c)))
		return (false);
	ft_printf("You've entered: %c\n", c);
	use_input(word, c);
	if (word->entered_corr_c == false)
		check_strikes(word);
	return (true);
}
