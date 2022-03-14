//Header//
#include <unistd.h>

void	ft_print_numbers(void)
{
	int 	i;
	char	buf;

	i = 0;
	while (i < 10)
	{
		buf = i + 48;
		write(1, &buf, 1);
		i++;
	}
}
