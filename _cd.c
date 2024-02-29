#include "main.h"

/**
* cd_shell - cd built-in
* @command: Command
*
* Return: status
*/
int cd_shell(data_shell command)
{
	if (command.args[1] == NULL)
		command.args[1] = _strdup("..");

	cd_to(&command);

	return (command.status);
}

/**
* cd_to - changes to a directory given
* by the user
* @command: Command
*
* Return: no return
*/
void cd_to(data_shell *command)
{
	char pwd[BUFFER_SIZE], dir[BUFFER_SIZE];

	if (getcwd(pwd, sizeof(pwd)) == NULL)
	{
		perror("getcwd");
		return;
	}

	if (chdir(command->args[1]) == -1)
	{
		command->status = 2;
		get_error(command->args, command->status, command->counter);
		return;
	}

	if (getcwd(dir, sizeof(dir)) == NULL)
	{
		perror("getcwd");
		return;
	}

	update_value(*command, "PWD", dir);
	update_value(*command, "OLDPWD", pwd);
}
