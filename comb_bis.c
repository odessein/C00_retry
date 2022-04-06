#include <unistd.h>
#include <stdio.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_arr(int array[10], int col_max)
{
	int	i;

	i = 1;
	while (i <= col_max)
	{
		ft_putchar(array[i] + 48);
		i++;
	}
}

//Funtion called when the last element of your array if 9 and then, check where we can increment value, moving in the array. If we cannot, it's finished
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
	return (1);
}

void	ft_print_combn(int array[10], int n, int col, int col_max)
{
	if (n <= 9)
	{
		if (col <= col_max)
		{
			array[col] = n;
			ft_print_combn(array, n + 1, col + 1, col_max);
		}
		else
		{
			ft_print_arr(array, col_max);
			ft_putchar(',');
			ft_putchar(' ');
			ft_print_combn(array, n, col - 1, col_max);
		}
	}
	else
	{
		ft_print_arr(array, col_max);
		if (ft_check_and_move_col(array, &col, col_max))
			return;
		ft_putchar(',');
		ft_putchar(' ');
		n = array[col] + 1;
		ft_print_combn(array, n, col, col_max);
	}
}
/*
void	ft_recurs(int i)
{
	if (i >= 0)
	{
		ft_putchar(i + 48);
		ft_recurs(i - 1);
	}
	ft_putchar('>');
	ft_putchar(i + 48);
	ft_putchar('x');
}
*/
int	main()
{
	int	array[10];
	int	i;
	int	n;

	array[0] = 0;
	i = 1;
	n = 9;
	ft_print_combn(array, 0, 1, n);
	return (0);
}
