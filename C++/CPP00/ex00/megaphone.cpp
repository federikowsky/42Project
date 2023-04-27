/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:58:27 by rdi-russ          #+#    #+#             */
/*   Updated: 2023/03/14 15:56:01 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main(int ac, char **av)
{
	int i;
	int x;

	i = 1;
	if(ac > 1)
	{
		while (av[i])
		{
			x = 0;
			while(av[i][x])
			{
				if(av[i][x] >=97 && av[i][x] <=122)
				{
					av[i][x] -= 32;
				}
				std::cout << av[i][x];
				x++;
			}
			i++;
			std::cout << ' ';
		}
		std::cout << std::endl;  
	}
	else
	{
		 std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return(0);
}