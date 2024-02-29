# Simple Shell
_The simple shell project_

# Synopsis
This repository holds all the code necessary for our custom simple shell to run. Our shell currently handles the executions of executables found in the environmental variable PATH, with or without their full paths. Sample commands that our shell supports include ls (/bin/ls), pwd, echo, which, whereis, etc. We've also created the following builtins.

- Resources
Read or watch:

Unix shell
Thompson shell
Ken Thompson
man or help:

sh (Run sh as well)
Learning Objectives

- General
Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?

# Builtins
exit exits shell (Usage: exit [status])
env prints environmental variables (Usage: env)
setenv creates or modifies an environmental variable (Usage: setenv name value)
unsetenv removes an envrionmental variable (Usage: unsetenv name value)
cd changes directories (Usage: cd [-][~][path])
Functions and system calls used
read, signal, malloc, free, getcwd, chdir, access, execve, wait, write, exit

# Compilation
Use this command to compile the shell
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

# Authors
Adjumany Yann
