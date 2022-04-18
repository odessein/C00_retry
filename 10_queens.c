#include <unistd.h>
#include <stdio.h>

//Check if its possible to play at a certain positon, respecting condition
int	ft_check(int line, int col, int arr[10])
{
	int	i;
	int	l_u;
	int	l_d;

	i = 0;
	if (line > 9)
		return (0);
	l_u = line - 1;
	l_d = line + 1;
	while (i < col)
	{
		if (arr[i] == line)
			return (0);
		i++;
	}
	while (--i > -1)
	{
		if ((arr[i] == l_u && l_u > -1) || (arr[i] == l_d && l_d < 10))
			return (0);
		l_d++;
		l_u--;
	}
	return (1);
}

void	ft_display(int array[10])
{
	int	i;
	char	print;

	i = 0;
	while (i < 10)
	{
		print = array[i] + 48;
		write(1, &print, 1);
		i++;
	}
	write(1, "\n", 1);
}

//Starting by the last digit to the first to check if we found another possibilities
int	ft_recursive_check(int array[10], int n, int col, int col_min)
{
	if (col > 9)
		return (1);
	while (!ft_check(n, col, array))
	{
		if (n > 9)
		{ 
			if (col > col_min)
				return (ft_recursive_check(array, array[col - 1] + 1, col - 1, col_min));
			else
				return (0);
		}
		n++;
	}
	array[col] = n;
	return ft_recursive_check(array, 0, col + 1, col_min);
}

//On part de 0 puis on check si on peux poser la prochaine value etc -> vers la droite
void	ft_insert(int array[10], int n, int col)
{
	if (col > 9)
		return ;
	while (!ft_check(n, col, array))
	{
		if (n > 9)
		{
			return ft_insert(array, array[col - 1] + 1, col - 1);
		}
		n++;
	}
	array[col] = n;
	ft_insert(array, 0, col + 1);
}

//loop to find all possibilites and display those
int	ft_ten_queens_puzzle(void)
{
	int	array[10];
	int	*array_buf;
	int	*array_r;
	int	col_min;
	int	count;

	col_min = 1;
	count = 1;
	ft_insert(array, 0, 0);
	ft_display(array);
	array_r = array;
	while (col_min >= 0)
	{
		array_buf = array_r;
		if (ft_recursive_check(array_buf, array_buf[9] + 1, 9, col_min))
		{
			array_r = array_buf;
			ft_display(array_r);
			count++;
			col_min = 1;
		}
		col_min--;
	}
	return (count);
}

int	main(void)
{
	printf("%i", ft_ten_queens_puzzle());
}

