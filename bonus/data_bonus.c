/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:16:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 14:54:28 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_data	*ft_init_data_bonus(int argc)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->a = ft_alloc_simple_tab(argc - 1);
	if (data->a == NULL)
	{
		free(data);
		return (NULL);
	}
	data->b = NULL;
	data->len_a = argc - 1;
	data->len_b = 0;
	data->actions = 0;
	return (data);
}

int	ft_set_data_bonus(t_data *data, char **argv)
{
	int	i;
	int	block;

	i = 0;
	block = 0;
	while (argv[++i] != NULL)
	{
		if (ft_is_integer(ft_atoll(argv[i])) == YES
			&& ft_is_duplicate(ft_atoll(argv[i]), block, data->a) == NO)
		{
			data->a[block++] = ft_atoll(argv[i]);
		}
		else
			return (KO);
	}
	data->error_code = 0;
	return (OK);
}
