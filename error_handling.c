#include "main.h"

/**
 * strcat_cd - function that concatenates the message for cd error
 * @args: list of arguments
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(char **args, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, "./hsh");
	strncat(error, ": ", 3);
	strncat(error, ver_str, strlen(ver_str));
	strncat(error, ": ", 3);
	strncat(error, args[0], strlen(args[0]));
	strncat(error, msg, strlen(msg));

	if (args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = args[1][1];
		illegal_flag[2] = '\0';
		strncat(error, illegal_flag, strlen(illegal_flag));
		free(illegal_flag);
	}
	else
		strncat(error, args[1], strlen(args[1]));

	strncat(error, "\n", 2);
	strncat(error, "\0", 1);
	return (error);
}

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @args: arguements
 * @counter: integer counter
 * @eval: error value
 *
 * Return: error
 */
int get_error(char **args, int eval, int counter)
{
	char *error = NULL;

	switch (eval)
	{
	case 0:
		break;
	case -1:
		error = error_env(args, args[0], counter);
		break;
	case 126:
		error = error_path_126(args, args[0], counter);
		break;
	case 127:
		error = error_not_found(args, args[0], counter);
		break;
	case 2:
		if (_strcmp("exit", args[0]) == 0)
			error = error_exit_shell(args, args[0], counter);
		else if (_strcmp("cd", args[0]) == 0)
			error = error_get_cd(args, args[0], counter);
		break;
	default:
		write(STDERR_FILENO, " :Unknown error code\n", 22);
		break;
	}

	if (error)
	{
		printf("%s", error);
		free(error);
	}

	return (eval);
}
