#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // 子进程代码
        printf("Child process, PID: %d\n", getpid());
        exit(EXIT_SUCCESS); // 子进程执行完毕后退出
    }
    else
    {
        // 父进程代码
        int status;
        wait(&status); // 等待子进程结束
        printf("Parent process, PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}