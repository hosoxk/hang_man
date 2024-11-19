#include "../include/hang_man.h"

bool	init_word(t_word *word)
{
	size_t	length;

	length = ft_strlen(word->str);
	if (!(word->matrice = malloc(sizeof (char) * (length + 1))))
		return (false);
	memset(word->matrice, '_', length);
	word->matrice[length] = '\0';
	ft_printf("word matrice = %s\n", word->matrice);
	word->strikes = 0;
	word->entered_corr_c = true;
	return (true);
}

static char	*get_random_line(FILE *file)
{
	int	line_count;
	char	lines[MAX_LINE];
	int	random_line;
	char	*random_word;
	char	*newline_pos;

	line_count = 0;
	while (fgets(lines, sizeof(lines), file) != NULL)
		line_count++;
	if (!line_count)
		return (NULL);
	srand(time(NULL));
	random_line = rand() % line_count;
	rewind(file);
	for (int i = 0; i <= random_line; i++)
		fgets(lines, sizeof(lines), file);
	newline_pos = ft_strchr(lines, '\n');
	if (newline_pos != NULL)
		*newline_pos = '\0';
	random_word = malloc(ft_strlen(lines) + 1);
	if (!random_word)
		return (perror("Memory allocation random word failed"), NULL);
	ft_strlcpy(random_word, lines, ft_strlen(lines) + 1);
	return (random_word);
}

char	*get_random_word(void)
{
	FILE	*file;
	char	*word;

	word = "lol";
	if (!(file = fopen(FILENAME, "r")))
		return (perror("Failed to open file"), NULL);
	if (!(word = get_random_line(file)))
		return (fclose(file), ft_printf("Error retrieving random line\n"), NULL);
	fclose(file);
	ft_printf("Random word = %s\n", word);
	return (word);
}
