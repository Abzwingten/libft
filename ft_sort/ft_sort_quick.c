/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:40:26 by rantario          #+#    #+#             */
/*   Updated: 2022/01/19 12:08:38 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	quick_sort(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	pivot;
	int	tmp;

	i = low;
	j = high;
	pivot = arr[(low + high) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = tmp;
		}
	}
	if (low < j)
		quick_sort(arr, low, j);
	if (i < high)
		quick_sort(arr, i, high);
}
