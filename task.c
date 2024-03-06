#include "main.h"

/**
 * execute_command - Execute a command entered by the user
 * @buffer: The command entered by the user
 */
void execute_command(char *buffer)
{
        char *token;
        pid_t pid;
        int status;

        token = strtok(buffer, " ");
        if (token != NULL)
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
                        if (execve(token, &token, NULL) == -1)
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

                buffer[str_len(buffer) - 1] = '\0'; /* Remove newline character */
                execute_command(buffer);
        }

        free(buffer);
        return (0);
}
