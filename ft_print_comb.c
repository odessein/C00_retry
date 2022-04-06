//Header//
#include <unistd.h>

void	ft_disp(char a, int c, int c1)
{
	char z;
	char z_b;

	z = '0' + c;
	z_b = '0' + c1;
	write(1, &a, 1);
	write(1, &z_b, 1);
	write(1, &z, 1);
	if (a != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	a;
	int	counter;
	int	counter1;

	a = '0';
	counter = 2;
	counter1 = 1;
	while (a < '7')
	{
		if (counter1 >= 9)
		{
			a++;
			counter1 = (a - 48) + 1;
			counter = counter1 + 1;
		}
		ft_disp(a, counter, counter1);
		if (counter >= 9)
			counter = ++counter1;
		counter++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
