#include "main.h"

/**
 * error_get_cd - error message for cd command in get_cd
 * @counter: count of commands or operations
 * @args: list of arguments
 * @cmd: name or command associated with the error
 * Return: Error message
 */
char *error_get_cd(char **args, char *cmd, int counter)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(counter);

	if (args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = strlen(args[1]);
	}

	length = strlen(cmd) + strlen(args[0]);
	length += strlen(ver_str) + strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL) /* Change error check from '0' to 'NULL' for clarity. */
	{
		free(ver_str);
		return (NULL);
	}
	strcat_cd(args, msg, error, ver_str);

	return (error);
}

/**
 * error_not_found - generic error message for command not found
 * @counter: count of commands or operations
 * @args: list of arguments
 * @cmd: shell name
 * Return: Error message
 */
char *error_not_found(char **args, char *cmd, int counter)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(counter);
	length = strlen(cmd) + strlen(ver_str) + strlen(args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));

	if (error == NULL) /* Use NULL for clarity instead of '0' */
	{
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, "./hsh");
	strncat(error, ": ", 3);
	strncat(error, ver_str, strlen(ver_str));
	strncat(error, ": ", 3);
	strncat(error, args[0], strlen(args[0]));
	strncat(error, ": not found\n", 13);

	free(ver_str);

	return (error);
}

/**
 * error_exit_shell - generic error message for exit in get_exit
 * @counter:  a command or operation counter
 * @args:  list of arguments. Specifically, args[0] and args[1] are being used
 * @cmd: shell name
 * Return: Error message
 */
char *error_exit_shell(char **args, char *cmd, int counter)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(counter);
	length = strlen(cmd) + strlen(ver_str) + strlen(args[0]) +
			 strlen(args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));

	if (error == NULL) /* Using NULL for clarity instead of '0'*/
	{
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, "./hsh");
	strncat(error, ": ", 3);
	strncat(error, ver_str, strlen(ver_str));
	strncat(error, ": ", 3);
	strncat(error, args[0], strlen(args[0]));
	strncat(error, ": Illegal number: ", 19);
	strncat(error, args[1], strlen(args[1]));
	strncat(error, "\n", 3);

	free(ver_str);

	return (error);
}

/**
 * error_env - error message for env in get_env
 * @counter: command or operation counter
 * @args: list of arguments, specifically args[0]
 * @cmd: shell name
 * Return: error message.
 */
char *error_env(char **args, char *cmd, int counter)
{
	int length;
	char *error;
	char *ver_str;
	char *msg = ": Unable to add/remove from environment\n";

	ver_str = aux_itoa(counter);
	length = strlen(cmd) + strlen(ver_str) + strlen(args[0]) +
			strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL) /* Using NULL for clarity instead of '0'. */
	{
		/* If error is NULL (malloc failed), there's no need to free it. */
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, "./hsh");
	strncat(error, ": ", 3);
	strncat(error, ver_str, strlen(ver_str));
	strncat(error, ": ", 3);
	strncat(error, args[0], strlen(args[0]));
	strncat(error, msg, strlen(msg));

	free(ver_str);

	return (error);
}

/**
 * error_path_126 - error message for path and failure denied permission
 * @counter: command or operation counte
 * @args: list of arguments, specifically args[0]
 * @cmd: shell name
 *
 * Return: The error string.
 */

char *error_path_126(char **args, char *cmd, int counter)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(counter);
	length = strlen(cmd) + strlen(ver_str) + strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));

	if (error == NULL) /* Using NULL for clarity instead of '0'. */
	{
		/* If error is NULL (malloc failed), there's no need to free it. */
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, "./hsh");
	strncat(error, ": ", 3);
	strncat(error, ver_str, strlen(ver_str));
	strncat(error, ": ", 3);
	strncat(error, args[0], strlen(args[0]));
	strncat(error, ": Permission denied\n", 24);

	free(ver_str);

	return (error);
}
