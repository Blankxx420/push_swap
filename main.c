/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:16:29 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/05 19:27:11 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_printf("%s",
			"Wrong number of parameters: expected minimum 2 number");
	}
	else
	{
		parse_argv(argv);
	}
}