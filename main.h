#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMAND_LENGTH 150
#define MAX_ARGS 10
#define BUFFER_SIZE 1024
#define TOK_DELIM " \t\r\a\n"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process id
 */
typedef struct data
{
	char *av[MAX_ARGS];
	char *input;
	char *args[MAX_ARGS];
	int status;
	int counter;
	char *_environ[MAX_COMMAND_LENGTH];
	pid_t pid;
} data_shell;

/**
 * struct var_line_s - Environment variable line
 * @content: the environment variable and its value
 * @next: next node
 * Description: the environment variable
 */
typedef struct var_line_s
{
	char *content;
	struct var_line_s *next;
} v_line;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct builtin - structure for builtin functions
 * @name: builtin function name
 * @f: function
 */
typedef struct builtin
{
	char *name;
	int (*f)(struct data);
} builtin_t;

/* ------------------------------------------------ */
int get_builtin(data_shell command);
int builtin_env(data_shell command);
int built_in_exit(data_shell command);
int built_in_setenv(data_shell command);
int built_in_unsetenv(data_shell command);
int cd_shell(data_shell command);
int get_help(data_shell command);
/* ------------------------------------------------ */

v_line *find_end_env(char *environ[]);
void cd_to(data_shell *command);
char *extract(char *string, int start_index, int end_index);
void update_value(data_shell command, char *varname, char *value);

int get_error(char **args, int eval, int counter);
char *error_path_126(char **args, char *cmd, int counter);
char *error_env(char **args, char *cmd, int counter);
char *error_exit_shell(char **args, char *cmd, int counter);
char *error_not_found(char **args, char *cmd, int counter);
char *error_get_cd(char **args, char *cmd, int counter);
char *strcat_cd(char **args, char *msg, char *error, char *ver_str);
int split_commands(data_shell *datash, char *input);
void split_line(char **tokens, char *input);

char *aux_itoa(int i);
void get_sigint(int sig);
int print_string(const char *format);
char *removeSpaces(char *strng);

sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

void free_data(data_shell *datash);
void set_data(data_shell *datash, char **environ);
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);

char *find_executable(char *command, char **envp);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_double_ptr(char **str);
void _sprintf_env_var(char *buffer, const char *format, ...);

int execute(data_shell command);

void free_all(char *strng, char *strg);
char *_strrchr(char *str, int c);
int _strncmp(char *s1, char *s2, int n);
int is_digit(char c);
int _strlen(char *s);
int is_number(char *c);

char *make_cmd(data_shell cmd, char *exec);

#endif
