#include <stdio.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
void	input_error(char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				printf("error\n");
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 6 || ac == 5)
	{
		input_error(av);
	}
	printf("error\n");
	return (0);
}