//Header//

#include <unistd.h>

void	ft_print(int a, int b)
{
	char	temp_a;
	char	temp_a1;
	char	temp_b;
	char	temp_b1;

	if (a < 10)
		temp_a = '0';
	else
		temp_a = (a / 10) + 48;
	temp_a1 = (a % 10) + 48;
	if (b < 10)
		temp_b = '0';
	else
		temp_b = (b / 10) + 48;
	temp_b1 = (b % 10) + 48;
	write(1, &temp_a, 1);
	write(1, &temp_a1, 1);
	write(1, " ", 1);
	write(1, &temp_b, 1);
	write(1, &temp_b1, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a < 98)
	{
		ft_print(a, b);
		write(1, ", ", 2);
		if (b >= 99)
			b = ++a;
		b++;
	}
	ft_print(a, b);
	return ;
}

int	main()
{
	ft_print_comb2();
	return (0);
}
