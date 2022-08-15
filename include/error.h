/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaabou <zaabou@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:05:39 by zaabou            #+#    #+#             */
/*   Updated: 2022/08/13 13:17:12 by zaabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"
# include "syntax_analysis.h"

void	ft_print_error(char *str);
bool	check_syntax_error(t_token_list *node, int *i);
bool	her_doc(t_token_list *token, int *i);

#endif