//Header//
#include <unistd.h>

void	ft_disp(int tab[11], int n, int check)
{
	int	i;
	char	to_print;

	i = 0;
	if (check == 0)
		write(1, "0", 1);
	while (i < n)
	{
		to_print = tab[i] + 48;
		write(1, &to_print, 1);
		i++;
	}
	if (check == 1)
	{
		if (tab[0] != 10 - n)
			write(1, ", ", 2);
	}
	else
		write(1, ", ", 2);
}

int	ft_check(int tab[11], int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (tab[i] >= tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_fill(int value, int power, int n, int tab[11])
{
	int	i;
	int	pow;
	int	buff;

	i = 0;
	pow = 1;
	while (i < n)
	{
		buff = value / (power / pow);
		if (pow == 1)
			tab[i] = buff;
		else
			tab[i] = buff % 10;
		pow *= 10;
		i++;
	}
}

int	ft_create_base(int n, int *pow)
{
	int	i;
	int	val;
	
	i = 0;
	val = i;
	while (i < n)
	{
		val += i;
		if (i + 1 < n)
		{
			*pow *= 10;
			val *= 10;
		}
		i++;
	}
	return (val);
}

void	ft_print_combn(int n)
{
	int 	val;
	int	pow;
	int	arr[11];

	if (n < 1 || n > 9)
		return ;
	pow = 1;
	val = ft_create_base(n, &pow);
	while (val / pow <= (10 - n))
	{
		if (val % pow == val)
		{
			ft_fill(val, pow / 10, n - 1, arr);
			if (ft_check(arr, n - 1))
				ft_disp(arr, n - 1, 0);
		}
		else
		{
			ft_fill(val, pow, n, arr);
			if (ft_check(arr, n))
				ft_disp(arr, n, 1);
		}
		val++;
	}
}

int	main(void)
{
	ft_print_combn(9);
}
