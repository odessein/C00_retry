//Header//
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	buff;

	if (nb < 0)
	{
		write(1 ,"-", 1);
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb *= -1;
	}
	buff = nb % 10 + 48;
	if (nb < 9)
		buff = nb + 48;
	else
		ft_putnbr(nb/10);
	ft_putchar(buff);
}

int	main()
{
	ft_putnbr(-2147483648);
	return (0);
}
