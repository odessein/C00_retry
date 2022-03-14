//Header//
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	buff;

	if (nb < 0)
	{
		write(1 ,"-", 1);
		if (nb == -2147483648)
		{
			ft_putnbr(214748364);
			ft_putnbr(8);
			return ;
		}
		nb *= -1;
	}
	buff = nb % 10 + 48;
	if (nb < 9)
		buff = nb + 48;
	else
		ft_putnbr(nb/10);
	write(1, &buff , 1);
}

int	main()
{
	ft_putnbr(-2147483648);
	return (0);
}
