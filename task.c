#include "main.h"

/**
 * execute_command - Execute a command entered by the user
 * @buffer: The command entered by the user
 */
void execute_command(char *buffer)
{
	pid_t pid;
	int status;
	char *args[] = { "", NULL};

	if (buffer)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* Child process */
			args[0] = buffer;
			if (execve(buffer, args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */
			waitpid(pid, &status, 0);
		}
	}
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		characters_read = getline(&buffer, &bufsize, stdin);
		if (characters_read == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}

		buffer[_strlen(buffer) - 1] = '\0'; /* Remove newline character */
		execute_command(buffer);
	}

	free(buffer);
	return (0);
}


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

