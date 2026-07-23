/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:00:22 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/23 14:50:00 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_push(t_number **src, t_number **dst)
{
	t_number	*node;

	if (!src || !*src)
		return (0);
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dst;
	if (*dst)
		(*dst)->prev = node;
	node->prev = NULL;
	*dst = node;
	return (1);
}

void	pa(t_number **b, t_number **a)
{
	if (do_push(b, a))
		register_cmd("pa");
}

void	pb(t_number **a, t_number **b)
{
	if (do_push(a, b))
		register_cmd("pb");
}
