#include "../include/hang_man.h"

char	*check_args(int argc, char **argv)
{
	char	*word;

	if (argc != 2)
		return (NULL);
	word = NULL;
	if (!(ft_strcmp(argv[1], "random")))
	{
		word = get_random_word();
		return (word);
	}
	word = malloc(sizeof (char) * (ft_strlen(argv[1]) + 1));
	if (!word)
		return (perror("Memory allocation chosen word failed"), NULL);
	ft_strlcpy(word, argv[1], ft_strlen(argv[1]) + 1);
	return (word);
}
