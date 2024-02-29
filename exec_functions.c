#include "main.h"

/**
 * find_executable - Finds the executable
 * @command: Parameter
 * @envp: Environment
 *
 * Return: The executable if found, NULL otherwise
 */
char *find_executable(char *command, char **envp)
{
	char *path_env = NULL, *token = NULL, *full_path = NULL;
	size_t token_len = 0, command_len = 0;
	int i;

	for (i = 0; envp[i] != NULL && path_env == NULL; i++)
	{
		if (_strncmp(envp[i], "PATH=", 5) == 0)
			path_env = _strdup(envp[i] + 5);
	}
	if (path_env != NULL)
	{
		token = strtok(_strdup(path_env), ":");
		while (token)
		{
			token_len = strlen(token);
			command_len = strlen(command);
			full_path = malloc(token_len + command_len + 2);
			if (full_path)
			{
				_strcpy(full_path, token);
				full_path[token_len] = '/';
				_strcpy(full_path + token_len + 1, command);
				full_path[token_len + command_len + 1] = '\0';
				if (access(full_path, X_OK) == 0)
				{
					free(path_env);
					return (full_path);
				}
				free(full_path);
			}
			else
				return (NULL);
			token = strtok(NULL, ":");
		}
		free(token);
	}
	if (path_env)
		free(path_env);
	return (NULL);
}

/**
 * make_cmd - Rebuilds the command w/ the executable and all argumets enterred
 * @cmd: Command
 * @exec: The executable
 *
 * Return: The command built n char*
 */
char *make_cmd(data_shell cmd, char *exec)
{
	int i = 0, j = 0;
	char *res;

	res = malloc(sizeof(char) * MAX_COMMAND_LENGTH);
	if (res == NULL)
		return (NULL);
	while (exec[i])
	{
		res[i] = exec[i];
		i++;
	}
	if (cmd.args[1])
	{
		res[i++] = ' ';
		while (cmd.args[1][j])
		{
			res[i + j] = cmd.args[1][j];
			j++;
		}
	}
	res[i + j] = '\0';

	return (res);
}
