#include "main.h"

/**
* free_data - frees data structure
*
* @datash: data structure
* Return: no return
*/
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->av[i]; i++)
		free(datash->av[i]);
	for (i = 0; datash->args[i]; i++)
		free(datash->args[i]);
	free(datash->input);
}

/**
* set_data - Initialize data structure
*
* @datash: data structure
* @environ: Environment
*
* Return: no return
*/
void set_data(data_shell *datash, char **environ)
{
	unsigned int k = 0;
	int env_count = 0, i;

	while (k < MAX_ARGS)
	{
		datash->args[k] = NULL;
		k++;
	}
	datash->status = 0;
	datash->counter = 1;

	while (environ[env_count] != NULL)
		env_count++;

	for (i = 0; i < env_count; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
		if (datash->_environ[i] == NULL)
			exit(EXIT_FAILURE);
	}
	datash->_environ[env_count] = NULL;

	datash->pid = getpid();
}
