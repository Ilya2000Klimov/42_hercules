/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_clients.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:00:35 by irhett            #+#    #+#             */
/*   Updated: 2017/02/18 16:06:10 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pingpong.h"

void	close_clients(s_srv *srv)
{
	s_cli	*tmp;

	ft_putendl("Starting to close clients.");
	if (srv)
	{
		while ((*srv).first)
		{
			printf("Closing client on %i\n", (*(*srv).first).sockfd);
			if ((*(*srv).first).sockfd >= 0)
				close((*(*srv).first).sockfd);
			tmp = (*srv).first;
			(*srv).first = (*(*srv).first).next;
			free(tmp);
		}
	}
	ft_putendl("All clients closed.");
}
