/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:00:22 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/15 19:16:15 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_push(t_number **src, t_number **dst)
{
	t_number	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dst;
	if (*dst)
		(*dst)->prev = node;
	*dst = node;
}

void	pa(t_number **b, t_number **a)
{
	do_push(b, a);
	register_cmd("pa");
}

void	pb(t_number **a, t_number **b)
{
	do_push(a, b);
	register_cmd("pb");
}
