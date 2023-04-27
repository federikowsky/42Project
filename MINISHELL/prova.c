# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

int main(int argc, char **argv, char **envp)
{

    char **cmd = (char **)malloc(sizeof(char *) * 4);

    cmd[0] = malloc(3);
    strcpy(cmd[0], "bash");

    cmd[1] = malloc(3);
    strcpy(cmd[1], "-c");

    cmd[2] = malloc(strlen(argv[1]));
    strcpy(cmd[2], argv[1]);

    cmd[3] = 0;

    if (fork() == 0)
    {
        execve("/bin/bash", cmd, envp);
        _exit(127);
    }
    else
        wait(NULL);

}