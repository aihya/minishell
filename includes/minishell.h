/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:09:45 by aihya             #+#    #+#             */
/*   Updated: 2019/06/30 22:11:13 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "../includes/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/param.h>

# define ALNUM "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789"

# define EMPTY -2
# define INCOMPLETE -1
# define CONTINUE -1

# define OK 1
# define NOK 0
# define TRUE 1
# define FALSE 0

# define SQUOTE '\''
# define DQUOTE '"'
# define DOLLAR '$'
# define TILDE '~'

# define EXIT 2
# define ECHO 3
# define ENV 4
# define SETENV 5
# define UNSETENV 6
# define CD 7

# define BEGIN_LETTER_ERR "variable name must begin with a letter"
# define ALNUM_ERR "variable name must contain alphanumeric characters"
# define FORK_UNABLE "unable to create child process for the moment"
# define COMMAND_NF "command not found"
# define NO_FILE_OR_DIR "no such file or directory"
# define TOO_MANY_ARGS "too many arguments"
# define TOO_FEW_ARGS "too few arguments"

int		g_var;

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

char				*ms_expand(char *arg);
int					ms_exec_builtin(int function, char **args, t_env **env);
int					ms_is_builtin(char *name);
int					ms_check_input(char *line, int prev_status);
int					ms_check_quote(char *str, int pos);
int					ms_env(t_env *env);
int					ms_unsetenv(char **args, t_env **env);
int					ms_cd(char **args, t_env **env);
int					ms_match_found(char *name, t_env *env);
t_env				*ms_get_var(char *name, t_env *env);
int					ms_setenv(char **args, t_env **env);
char				**ms_parse(char *line, t_env *env);
char				**ms_expand_args(char **args, t_env *env);
int					ms_echo(char **args);
int					ms_exec_non_builtin(char **args, t_env **env);
void				signal_handler(int sig);
void				ms_prompt(int status);
void				ms_free_node(t_env **node);
t_env				*ms_node(char *name, char *value);
t_env				*ms_init_env(char **ev);
void				ms_free_env(t_env **env);
char				**ms_env_to_array(t_env *env);
void				ms_error(char *cmd, char *msg, int newline);
int					ms_path_of_directory(char *path);
int					ms_path_exist(char *path);
int					ms_path_accessible(char *path);
int					ms_check_path(char *path);
void				ms_move_to(char *path, t_env **env);
int					ms_go_back(t_env **env);
int					ms_go_home(t_env **env);
int					ms_is_executable(char *path);
void				ms_set_quote(int *quoted, char *quote, char c);
char				*ms_expand_quotes(char *arg);
int					ms_expand_dollar(char **buffer, char *arg, t_env *env);
char				*ms_expand_dollars(char *arg, t_env *env);
char				*ms_expand_tilde(char *arg, t_env *env);
char				*ms_basename(char *str);
int					ms_get_input(char **buffer, int last_status, t_lst **list);

#endif
