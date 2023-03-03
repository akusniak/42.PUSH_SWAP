/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:32:18 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/01 15:24:50 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i != argc)
	{
		ft_is_valid_arguments(argv[i]);
		i = i + 1;
	}
}

void	ft_is_valid_arguments(char *argv)
{
	int	number_of_sign;
	int	i;

	number_of_sign = 0;
	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == NO && ft_issign(argv[i]) == NO)
			ft_print_error_and_exit();
		if (ft_issign(argv[i]) == YES)
			number_of_sign = number_of_sign + 1;
		i = i + 1;
	}
	if (number_of_sign > 1)
		ft_print_error_and_exit();
}
