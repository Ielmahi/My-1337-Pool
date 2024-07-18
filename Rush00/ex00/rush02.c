/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilelmahi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:54:48 by ilelmahi          #+#    #+#             */
/*   Updated: 2024/06/30 16:16:22 by mohnine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_char_n_times(int nn, char bb)
{
	while (nn > 0)
	{
		ft_putchar(bb);
		nn--;
	}
}

void	print_first_rows(int len)
{
	ft_putchar('A');
	if (len == 2)
		ft_putchar('A');
	else if (len >= 3)
	{
		print_char_n_times(len - 2, 'B');
		ft_putchar('A');
	}
	ft_putchar('\n');
}

void	print_middle_rows(int len)
{
	ft_putchar('B');
	if (len == 2)
		ft_putchar('B');
	else if (len >= 3)
	{
		print_char_n_times(len - 2, ' ');
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	print_last_row(int len, int deeplr)
{
	if (deeplr >= 2)
	{
		ft_putchar('C');
		if (len == 2)
			ft_putchar('C');
		else if (len >= 3)
		{
			print_char_n_times(len - 2, 'B');
			ft_putchar('C');
		}
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	int	kk;

	if (y <= 0 || x <= 0)
	{
		write(1, "error input\n", 12);
	}
	else
	{
		kk = y;
		print_first_rows(x);
		if (y == 2)
		{
			print_last_row(x, y);
		}
		else if (y >= 3)
		{
			while (kk-- > 2)
			{
				print_middle_rows(x);
			}
			print_last_row(x, y);
		}
	}
}
