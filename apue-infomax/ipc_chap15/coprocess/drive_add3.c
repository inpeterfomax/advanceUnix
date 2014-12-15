#include<stdio.h> 
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

#define MAXLINE 1024

static void sig_pipe(int signo)
{
    printf("SIGPIPE caught\n");
    exit(1);
}

int main(int argc,char *argv[])
{
    int     n, fd1[2], fd2[2];
    pid_t   pid;
    char    line[MAXLINE];

    if (signal(SIGPIPE, sig_pipe) == SIG_ERR)
        perror("signal error");

    if (pipe(fd1) < 0 || pipe(fd2) < 0)
        perror("pipe error");

    if ((pid = fork()) < 0) {
        perror("fork error");
    } else if (pid > 0) {                         /* parent */
        close(fd1[0]);
        close(fd2[1]);
        while (fgets(line, MAXLINE, stdin) != NULL) {
            n = strlen(line);
            if (write(fd1[1], line, n) != n)
                perror("write error to pipe");
            if ((n = read(fd2[0], line, MAXLINE)) < 0)
                perror("read error from pipe");
            if (n == 0) {
                perror("child closed pipe");
                break;
            }
            line[n] = 0;    /* null terminate */
            if (fputs(line, stdout) == EOF)
                perror("fputs error");
        }
        if (ferror(stdin))
            perror("fgets error on stdin");
        exit(0);
    } else {                                  /* child */
        close(fd1[1]);
        close(fd2[0]);
        if (fd1[0] != STDIN_FILENO) {
            if (dup2(fd1[0], STDIN_FILENO) != STDIN_FILENO)
                perror("dup2 error to stdin");
            close(fd1[0]);
        }

        if (fd2[1] != STDOUT_FILENO) {
            if (dup2(fd2[1], STDOUT_FILENO) != STDOUT_FILENO)
                perror("dup2 error to stdout");
            close(fd2[1]);
        }
        if (execl("./add3", "add3", (char *)0) < 0)
           perror("execl error");
    }
    exit(0);
}


