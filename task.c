#include "main.h"

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 *
 * Return: void
 */
void get_sigint(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n\\_(^-^)_/\n", 12);
}

/**
 * main - Entry point
 * @ac: Args count
 * @av: Args
 * @env: Environment
 *
 * Return: Always 0
 */
int main(int ac, char **av, char *env[])
{
	int is_interact = (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)),
		k = 0, i = 0;
	size_t buf_size = 0;
	data_shell data;
	char *buffer = NULL;

	UNUSED(av);
	UNUSED(ac);
	signal(SIGINT, get_sigint);
	set_data(&data, env);
	while (1)
	{
		if (is_interact)
			printf("$ "), fflush(stdout);
		if (getline(&buffer, &buf_size, stdin) == -1)
			break;
		if (buffer[0] != '\n')
		{
			for (; k < MAX_ARGS; k++)
				data.av[k] = NULL;
			split_commands(&data, buffer);
			free(data.input);
			data.counter++;
		}
	}
	for (i = 0; data._environ[i]; i++)
		free(data._environ[i]);
	free(buffer);

	return (0);
}

/**
 * execute - executes command
 * @command: command to execute
 *
 * Return: 0 for success, -1 for failure
 */
int execute(data_shell command)
{
	int status, found = 0;
	char *exec = NULL;

	if (access(command.args[0], X_OK) == 0)
		found = 1;
	else
	{
		exec = find_executable(command.args[0], command._environ);
		if (exec)
		{
			found = 1;
			command.args[0] = _strdup(exec);
		}
		else
			command.status = 2;
		free(exec);
	}
	if (found == 1)
	{
		command.pid = fork(); /* Fork a new process */
		if (command.pid == 0)
		{
			command.status = 0;
			return (execve(command.args[0], command.args, command._environ));
		}
		else if (command.pid > 0) /* Wait for the child process to complete */
		{
			waitpid(command.pid, &status, 0);
			command.status = WEXITSTATUS(status);
		}
		else
			perror("./hsh: 0");
	}
	else
		command.status = 127;
	get_error(command.args, command.status, command.counter);
	return (0);
}
