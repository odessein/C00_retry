#include <unistd.h>
#include <stdio.h>

//Funtion recursive_check -> Check if we can add + 1, <- vers la gauche,  without probleme with any other, then again go -> vers la droite if probleme (restart the check to the left etc (on the last valid value obviously)


//Function Check
//On part de 0 puis on check si on peux poser la prochaine value etc -> vers la droite
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
//		printf("\n l_u : %i, l_d : %i, val %i: %i", l_u, l_d, i, array[i]);
		if ((arr[i] == l_u && l_u > -1) || (arr[i] == l_d && l_d < 10))
			return (0);
		l_d++;
		l_u--;
	}
	return (1);
}
//Function display (witch count too)

void	ft_display(int array[10], int col)
{
	int	i;
	char	print;

	i = 0;
	while (i <= col)
	{
//§		printf("%i \n ", array[i]);
		print = array[i] + 48;
		write(1, &print, 1);
		i++;
	}
}

int	ft_recursive_check(int array[10], int n, int col, int col_min)
{
	if (col > 9)
		return (1);
	while (!ft_check(n, col, array))
	{
		if (n > 9)
		{ if (col > col_min)
				return (ft_recursive_check(array, array[col - 1] + 1, col - 1, col_min));
			else
				return (0);
		}
		n++;
	}
	array[col] = n;
	return ft_recursive_check(array, 0, col + 1, col_min);
}

//Classic loop (recursion usage only on the check)

void	ft_insert(int array[10], int n, int col)
{
//Init **
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
//	ft_display(array, col);
//	write(1, "\n", 1);
	ft_insert(array, 0, col + 1);
}

int	ft_ten_queens_puzzle(void)
{
	int	array[10];
	int	*array_buf;
	int	*array_r;
	int	col_min;

	ft_insert(array, 0, 0);
	ft_display(array, 9);
	write(1, "\n", 1);
	col_min = 9;
	array_r = array;
	while (col_min >= 0)
	{
		array_buf = array_r;
		if (ft_recursive_check(array_buf, array_buf[9] + 1, 9, col_min))
		{
			array_r = array_buf;
			ft_display(array, 9);
			write(1, "\n", 1);
			col_min = 9;
		}
		col_min--;
	}
	return (1);
}

int	main(void)
{
	ft_ten_queens_puzzle();
}


