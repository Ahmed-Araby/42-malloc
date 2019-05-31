/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 01:57:33 by jterrazz          #+#    #+#             */
/*   Updated: 2019/05/30 18:14:21 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void print_range_group(t_range *range) {
	if (range->group == TINY) {
		ft_putstr("TINY");
	} else if (range->group == SMALL) {
		ft_putstr("SMALL");
	} else {
		ft_putstr("LARGE");
	}
}
