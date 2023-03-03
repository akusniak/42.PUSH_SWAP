/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:14:13 by akusniak          #+#    #+#             */
/*   Updated: 2023/03/02 16:29:33 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ajust_len(int action_a, int *len_a, int action_b, int *len_b)
{
	if (action_a == INCREASE)
		*len_a += 1;
	else if (action_a == REDUCE)
		*len_a -= 1;
	if (action_b == INCREASE)
		*len_b += 1;
	else if (action_b == REDUCE)
		*len_b -= 1;
}

void	ft_refill_winner(int *new, int *old, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < len + 1)
	{
		new[i] = old[j];
		i = i + 1;
		j = j + 1;
	}
}

void	ft_refill_looser(int *new, int *old, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < len)
	{
		new[i] = old[j];
		i = i + 1;
		j = j + 1;
	}
}

int	*ft_intdup(int *new, int len)
{
	int	*data;
	int	i;

	i = 0;
	data = malloc(sizeof(int) * len);
	if (data == NULL)
		return (NULL);
	while (i < len)
	{
		data[i] = new[i];
		i = i + 1;
	}
	free(new);
	return (data);
}
