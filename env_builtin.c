#include "main.h"

/**
* built_in_setenv - Function to set an environment variable
*
*@command: parameter used
*Return: (0) otherwise (-1)
*/
int built_in_setenv(data_shell command)
{
	v_line *end_env = find_end_env(command._environ), *new_var;
	char *varname = command.av[0], *value = command.av[1];
	char **var = command._environ, *var_cpy = NULL, *line = NULL;

	if (varname && value)
	{
		for (; *var < end_env->content; var++)
		{
			var_cpy = extract(*var, 0, (int)strlen(varname));
			if (_strncmp(var_cpy, varname, strlen(varname)) == 0)
			{
				printf("%s", *var);
				free(*var);
				line = malloc(BUFFER_SIZE);
				if (line == NULL)
				{
					free(var_cpy);
					return (-1);
				}
				_sprintf_env_var(line, "%s=%s", varname, value);
				*var = _strdup(line);
				free(var_cpy);
				return (0);
			}
			free(var_cpy);
		}
		new_var = end_env->next;
		new_var->content = (char *)malloc(BUFFER_SIZE);
		if (new_var->content == NULL)
			return (-1);
		_sprintf_env_var(new_var->content, "%s=%s", varname, value);
		new_var->next = NULL;

		return (0);
	}
	command.status = -1;
	get_error(command.args, command.status, command.counter);
	return (-1);
}

/**
* find_end_env - Function to find the end of the environment variables
*@environ: parameter used
*
* Return: environ last line
*/
v_line *find_end_env(char *environ[])
{
	v_line *line = (v_line *)malloc(sizeof(v_line));

	if (line == NULL)
		return (NULL);

	while (*environ != NULL)
		environ++;

	line->content = _strdup(*(environ - 1));
	line->next = NULL;

	return (line);
}

/**
* builtin_env - env built-in
* @command: command
*
* Return: Always 0
*/
int builtin_env(data_shell command)
{
	int i;

	for (i = 0; command._environ[i]; i++)
	{
		print_string(command._environ[i]);
		print_string("\n");
	}

	return (0);
}

/**
* built_in_unsetenv - Function to unset an environment variable
* @command: command
* Return: int
*/
int built_in_unsetenv(data_shell command)
{
	char **envp = command._environ, *var, *name, *value;

	while (*envp)
	{
		name = *envp;
		value = name + strlen(name) + 1;
		var = extract(*envp, 0, (int)strlen(command.args[1]) - 1);
		if (_strcmp(var, command.args[1]) == 0)
		{
			*envp = value;
			command.status = 0;
			return (0);
		}
		envp++;
	}
	command.status = -1;

	return (get_error(command.args, command.status, command.counter));
}
