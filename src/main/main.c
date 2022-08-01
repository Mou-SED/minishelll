/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:48:30 by moseddik          #+#    #+#             */
/*   Updated: 2022/07/30 16:19:52 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_parse_cmd(t_ast *node)
{
	char *str[5] = {"&&", "||", "CMD", "PIPE", "()"};
	if (node == NULL)
		return ;
	if (node->type == PAR)
	{
		printf("\t\t iam '('\n");
		printf("\t\t my redir is %s\n", node->cmd_node->redir_files);
	}
	if (node->type == OR)
		printf("\t\t im ||\n");
	else if (node->type == AND)
		printf("\t\t im &&\n");
	if (node->type == PIP)
		printf("\t\tthe sub_root is |\n");
	if (node->left != NULL)
	{
		if (node->left->type == CMD)
		{
			printf("my left is : %s\n", node->left->cmd_node->cmd_args);
			printf("my file : is [%s]\n", node->left->cmd_node->redir_files);
		}
		else if (node->left->type == PIP)
			printf("my left is | \n");
		else if (node->left->type == PAR)
			printf("im %s\n", node->left->cmd_node->cmd_args);
		else
			printf("my left is %s\n", str[node->left->type]);
	}
	if (node->right != NULL)
	{
		if (node->right->type == CMD)
		{
			printf("\t\t\t\tmy right is : %s\n", node->right->cmd_node->cmd_args);
			printf("\t\t\t\tmy files : is [%s]\n", node->right->cmd_node->redir_files);
		}
		else if (node->right->type == PIP)
			printf("\t\t\t\tmy right is | \n");
		else
			printf("\t\t\t\tmy right is %s\n", str[node->right->type]);
	}
	print_parse_cmd(node->left);
	print_parse_cmd(node->right);
} // TODO: Delete this function

int	main(int ac, char **av)
{
	char			*cmd;
	t_token_list	**head;
	t_ast			*root;

	(void)ac;
	(void)av;
	head = ft_calloc(1, sizeof(t_token_list *));
	signals_handler();
	while (1)
	{
		cmd = readline("\001\e[1;36m\002MiniShell~ \001\e[0m\002");
		if (cmd != NULL && *cmd != 0)
		{
			(add_history(cmd), *head = ft_lstnew_token(NULL));
			(tokenizer(skip_space(cmd), head), free(cmd));
			if ((*head)->lexeme == NULL || (check_syntax_error(*head) == true
					&& her_doc(*head) == true))
			{
				ft_lstclear_tokens(head, &free);
				continue ;
			}
			root = building_ast(root, *head);
			if (check_empty_parenthesis(root) == true)
			{
				printf("This case is not required by the subject!\n");
				(ft_lstclear_tokens(head, &free), clear_ast(root));
				continue ;
			}
			print_parse_cmd(root);
			(ft_lstclear_tokens(head, &free), clear_ast(root));
		}
		else if (cmd == NULL)
			ctl_d_handler(head);
	}
}
