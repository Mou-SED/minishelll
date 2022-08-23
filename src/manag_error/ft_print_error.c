/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:03:06 by zaabou            #+#    #+#             */
/*   Updated: 2022/08/22 03:55:00 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_print_error(char *str)
{
	int	stdo;

	stdo = dup(1);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	printf("MiniShell: syntax error near unexpected token `%s'\n", str);
	dup2(stdo, STDOUT_FILENO);
	close(stdo);
}

void	execution_errors(char *str)
{
	int	stdo;

	stdo = dup(1);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	printf("\x1b[33m Minishell : %s: %s\x1b[0m\n", str, strerror(errno));
	dup2(stdo, STDOUT_FILENO);
	close(stdo);
}

void	allocation_faild(void)
{
	int	stdo;

	stdo = dup(1);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	printf("MiniShell: Error: %s\n", strerror(errno));
	dup2(stdo, STDOUT_FILENO);
	close(stdo);
	exit(12);
}
