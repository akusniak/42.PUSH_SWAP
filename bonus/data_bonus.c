/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:16:30 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/05 15:56:59 by akusniak         ###   ########.fr       */
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

static int	ft_is_it_really_a_int(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i = i + 1;
	while (arg[i] == '0')
		i = i + 1;
	while (arg[i] != '\0')
	{
		i = i + 1;
		count = count + 1;
	}
	if (count > 11)
		return (NO);
	else
		return (YES);
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
			&& ft_is_duplicate(ft_atoll(argv[i]), block, data->a) == NO
			&& ft_is_it_really_a_int(argv[i]) == YES)
		{
			data->a[block++] = ft_atoll(argv[i]);
		}
		else
			return (KO);
	}
	data->error_code = ft_find_biggest(data->a, data->len_a) + 1;
	return (OK);
}
