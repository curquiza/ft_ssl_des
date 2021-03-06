/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <curquiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:33:09 by curquiza          #+#    #+#             */
/*   Updated: 2019/04/30 18:33:11 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	left_rotate(uint32_t x, uint32_t n)
{
	return ((x << n) | (x >> (32 - n)));
}

uint32_t	uint32_right_rotate(uint32_t x, uint32_t n)
{
	return ((x >> n) | (x << (32 - n)));
}

uint32_t	uint32_right_shift(uint32_t x, uint32_t n)
{
	return (x >> n);
}

uint64_t	uint64_right_rotate(uint64_t x, uint64_t n)
{
	return ((x >> n) | (x << (64 - n)));
}

uint64_t	uint64_right_shift(uint64_t x, uint64_t n)
{
	return (x >> n);
}
