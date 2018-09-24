/*
** minishell.h for minishell in /home/JB.Melet/Projets/Système_Unix/PSU_2016_minishell1/include
** 
** Made by JeanBaptiste Melet
** Login   <JB.Melet@epitech.net>
** 
** Started on  Mon Jun 12 12:32:22 2017 JeanBaptiste Melet
** Last update Sun Oct  8 14:54:47 2017 jean-baptiste
*/

#ifndef MINISHELL_H_

# define MINISHELL_H_

/****************
 *Error Handling*
 ****************/

# define SEGFAULT		"Segmentation fault\n"
# define SEGFAULT_DUMPED	"Segmentation fault (core dumped)\n"
# define FLOAT_EXCEPTION	"Floating exception\n"
# define FLOAT_EXCEPTION_DUMPED	"Floating exception (core dumped)\n"

# define EXEC_ERROR		"Exec format error."
# define BINARY_ERROR		"Wrong Architecture."
# define COMMAND_ERROR		"Command not found.\n"
# define PERM_ERROR		"Permission denied.\n"
# define INVALID_NULL		"Invalid null command.\n"
# define NO_SUCH_FILE		"No such file or directory.\n"

/****************
 *Builtins error*
 ****************/

# define SETENV_AV		"setenv: Too many arguments.\n"
# define SETENV_NAME		"setenv: Variable name must"
# define SETENV_LETTER		" begin with a letter.\n"
# define SETENV_ALPHA		"contain alphanumeric characters."
# define CD_AV			"cd: Too many arguments.\n"
# define CD_DIR			": No such file or directory.\n"
# define ALIAS_ERROR		"alias: Too dangerous to alias that.\n"

# define EXIT_SUCCES		0
# define EXIT_ERROR		1
# define EXIT_SEG		139
# define EXIT_EXCEPTION		136
# define EXIT			"exit\n"

/*******
 *Shell*
 *******/

typedef struct			s_info_shell
{
  char				*command;
  char				*mem;
  char				*path_save;
  char				**tab;
  char				**tab_mem;
  char				**historic;
  char				**alias_tab;
  int				tablen;
  int				exit_value;
  int				flags_value;
  int				alias_value;
}				t_info_shell;

/**********
 *builtins*
 **********/

typedef struct			s_builtin
{
  char				*code;
  int				(*fc)(t_info_shell *);
}				t_builtin;

int				which(t_info_shell *);
int				my_cd(t_info_shell *);
int				where(t_info_shell *);
int				repeat(t_info_shell *);
int				my_exit(t_info_shell *);
int				cd_point(t_info_shell *);
int				my_set_env(t_info_shell *);
int				my_unset_env(t_info_shell *);
int				my_display_env(t_info_shell *);
int				print_historic(t_info_shell *);
int				create_my_alias(t_info_shell *);

int				exec(t_info_shell *, char *);
int				execute_command(t_info_shell *);
char				*is_valid_command(t_info_shell *);

/***********
 *fonctions*
 ***********/

int				my_strlen(char *);
int				my_tablen(char **);
int				my_str_isalpha(char *);
int				my_strcmp(char *, char *);
int				verif_first_letter(char *);
int				my_find_str(char *, char *);
int				search_path(char **, char *);
int				command_verif(t_info_shell *);
void				prompt();
void				free_all(char *, char **);
void				free_struct(t_info_shell *);
char				*read_file(char *);
char				*my_strdup(char *);
char				*my_epurstr(char *);
char				*get_path(char **, char *);
char				*my_strcat(char *, char *, int);
char				**my_str_to_wordtab(char *, char);

/***************
 *Get_next_line*
 ***************/

# define READ_SIZE		1
char				*get_next_line(int);
char				*get_next_line_dbg(int);

/*************
 *MINISHELL 2*
 *************/

# define STANDARD_OUTPUT	1
# define BOOL			"bool"
# define FD_EXIT		0
# define FD_ENTRY		1

typedef struct			s_flag
{
  char				*code;
  int				(*fc)(t_info_shell *);
}				t_flag;

int				my_count(char *, char);
int				execution_in_chain(t_info_shell *);
char				*little_verif(char *);
char				*command_normed(char *, char);
char				**cut_tab(char **, char *);

int				or(t_info_shell *);
int				and(t_info_shell *);
int				pipes(t_info_shell *);
int				all_chevron(t_info_shell *);
int				left_chevron(t_info_shell *);
int				error_chevron(t_info_shell *);
int				right_chevron(t_info_shell *);
int				double_right_chevron(t_info_shell *);
int				double_error_chevron(t_info_shell *);

/*******
 *Alias*
 *******/

typedef struct			s_count
{
  int				i;
  int				j;
  int				k;
  int				l;
}				t_count;

int				my_alias(t_info_shell *);
char				**get_my_alias();
char				**cut_commands(char **);
char				**cut_alias(char **);
int				recognize_my_alias(char **, char **,
						   t_info_shell *);
char				*create_valid_alias(char **);
char				**add_new_alias(char **, char *);
int				alias_check(t_info_shell *);
int				replace_alias(char **, char *, char *);

/******
 *42SH*
 ******/

# define AND			1
# define OR			2
# define PATH			"/usr/local/sbin:/usr/local/bin:/usr/bin:"
# define PATH_TWO		"/usr/lib/jvm/default/bin:/usr/bin/site_perl:"
# define PATH_THREE		"/usr/bin/vendor_perl:/usr/bin/core_perl"
# define MY_ALIAS		"bool"

char				**my_ls(char *, int *);
void				tabulation(char *);
char				**history_add(char **, char *);
char				**copy_my_tab(char **);
char				**reverse_tab(char **);
int				parsing(t_info_shell *);
char				*clean_pipes(char *, char);
void				init_struct(t_info_shell *);
int				find_flags(t_info_shell *);
int				free_tmp(t_info_shell *, char *);
int				my_magic_quote(t_info_shell *);

#endif /* !MINISHELL_H_ */
