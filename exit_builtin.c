#include "main.h"

/**
 * built_in_exit - exit built-in
 *
 * @command: character used
 * Return: 0 Success, -1 otherwise
 */
int built_in_exit(data_shell command)
{
	int status;

	if (command.args[1])
	{
		status = atoi(command.args[1]);
		if (status != 0)
		{
			free_data(&command);
			exit(status);
		}
		else
		{
			command.status = 2;
			get_error(command.args, command.status, command.counter);
			return (-1);
		}
	}
	else
	{
		free_data(&command);
		exit(command.status);
	}
	return (0);
}
