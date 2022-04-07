#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//Funtion called when the last element of your array if 9 and then, check where we can increment value rescting logical incrementation, by moving in the array. Return True when we have the max value rescpting rules.
int	ft_check_and_move_col(int array[10], int *col, int col_max)
{
	while (*col > 2)
	{
		*col = *col - 1;
		if (array[*col] != array[*col - 1] + 1)
		{
			*col = *col - 1;
			return (0);
		}
	}
	if (array[1] == 10 - col_max)
		return (1);
	return (0);
}

void	ft_display(int array[10], int col, int col_max)
{
	int	i;

	i = 1;
	while (i <= col_max)
	{
		ft_putchar(array[i] + 48);
		i++;
	}
	if (!ft_check_and_move_col(array, &col, col_max))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_combn(int array[10], int n, int col, int col_max)
{
	if (n <= 9)
	{
		if (col <= col_max)
		{
			array[col] = n;
			ft_combn(array, n + 1, col + 1, col_max);
		}
		else
		{
			ft_display(array, col ,col_max);
			ft_combn(array, n, col - 1, col_max);
		}
	}
	else
	{
		ft_display(array, col, col_max);
		if (ft_check_and_move_col(array, &col, col_max))
			return;
		n = array[col] + 1;
		ft_combn(array, n, col, col_max);
	}
}

void	ft_print_combn(int n)
{
	int	array[10];

	if (n <= 9 && n >= 1)
		ft_combn(array, 0, 1, n);
}

int	main()
{
	ft_print_combn(0);
}
