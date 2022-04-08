#include <unistd.h>
#include <stdio.h>


void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_arr(int array[10], int col_max)
{
    int    i;

    i = 1;
    while (i <= col_max)
    {
        ft_putchar(array[i] + 48);
        i++;
    }
    if (array[1] != 10 - col_max)
    {
        ft_putchar(',');
        ft_putchar(' ');
    }
}

void    ft_print_combn(int array[10], int n, int col, int col_max)
{
    array[col] = n;
    if (n <= 9)
    {
        if (col+1<=col_max)
        {
            if (n!=9)
                ft_print_combn(array, n + 1, col + 1, col_max);
            ft_print_combn(array, n + 1, col, col_max);
        }
        else
        {
            ft_print_arr(array, col_max);
            if (n<9)
                ft_print_combn(array, n + 1, col, col_max);
        }
    }
}

int    main()
{
    int    array[10];
    int    i;
    int    n;

    array[0] = 0;
    i = 1;
    n = 3;
    ft_print_combn(array, 0, 1, n);
    return (0);
}
