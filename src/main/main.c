/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:48:30 by moseddik          #+#    #+#             */
/*   Updated: 2022/07/07 16:26:51 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_print_tokens(t_token_list *head)
{
	t_token_list  *tmp;
	char *str[7] = {"WORD", "PIPE", "REDIRECTION", "OPERATOR", "LEFTPAREN", "RIGHTPAREN"};
	if (head == NULL)
		printf("head is Null\n");
	while (ft_strcmp(head->lexeme, "newline"))
	{
		printf("[%s] --> [%s]\n", head->lexeme, str[head->type]);
		tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL;
	}
}

int	main(int ac, char **av)
{
	char			*cmd;
	t_token_list	**head;

	(void)ac;
	(void)av;

	head = malloc(sizeof(t_token_list *));
	signals_handler();
	while (1)
	{
		cmd = readline("\001\e[1;36m\002MiniShell~ \001\e[0m\002");
		if (cmd != NULL && *cmd != 0)
		{
			(add_history(cmd), tokenizer(cmd, head));
			ft_print_tokens(*head);
			*head = ft_lstnew_token("content");
		}
		else if (cmd == NULL)
			ctl_d_handler();
	}
}
