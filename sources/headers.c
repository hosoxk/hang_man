#include "../include/hang_man.h"

//using printf instead of ft_printf because of "\"
void	print_header(void)
{
	printf(" _____                          \n");
	printf("|  |  |___ ___ ___ _____ ___ ___ \n");
	printf("|     | .'|   | . |     | .'|   |\n");
	printf("|__|__|__,|_|_|_  |_|_|_|__,|_|_|\n");
	printf("              |___|              \n");
	printf("\n");	
}

void	print_game_over(void)
{
	printf(" _____                  _____             \n");
	printf("|   __|___ _____ ___   |     |_ _ ___ ___ \n");
	printf("|  |  | .'|     | -_|  |  |  | | | -_|  _|\n");
	printf("|_____|__,|_|_|_|___|  |_____|\\_/|___|_|  \n");
	printf("\n");
}

void	print_succes(void)
{
	printf("                           __\n");
	printf(" _____                    |  |\n");
	printf("|   __|_ _ ___ ___ ___ ___|  |\n");
	printf("|__   | | |  _|  _| -_|_ -|__|\n");
	printf("|_____|___|___|___|___|___|__|\n");
	printf("\n");
}
