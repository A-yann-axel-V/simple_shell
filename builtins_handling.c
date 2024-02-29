#include "main.h"

/**
 * get_builtin - builtins that pass the command in the arg
 * @command: command
 * Return: function of the builtin command
 */
int get_builtin(data_shell command)
{
	builtin_t builtins[] = {
		{ "env", builtin_env },  { "help", get_help },
		{ "exit", built_in_exit }, { "cd", cd_shell },
		{ "setenv", built_in_setenv },
		{ "unsetenv", built_in_unsetenv },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(builtins[i].name, command.args[0]) == 0)
			return (builtins[i].f(command));
	}

	return (execute(command));
}

/**
 * update_value - Updates values
 * @command: Command
 * @varname: Varname
 * @value: Value
 *
 * Return: void
 */
void update_value(data_shell command, char *varname, char *value)
{
	command.av[0] = _strdup(varname);
	command.av[1] = _strdup(value);
	command.av[2] = NULL;

	built_in_setenv(command);
}

/**
 * get_help - help built-in
 * @command: Command
 *
 * Return: int
 */
int get_help(data_shell command)
{
	UNUSED(command);
	return (0);
}
