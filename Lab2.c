//
// Created by Fisher Bachman-Rhodes on 2/10/25.
//
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    //instantiate int variables to store the fork and execvp return values
    int forkValue = 0;
    int execVal = 0;

    //implement a for loop that iterates 10 times
    for (int i = 0; i < 10; i++) {
        //use fork to create a child process
        forkValue = fork();
        char buffer[256];

        //if we are currently in the child process implement a switch to perform specific operations depending on the value of i
        if (forkValue == 0) {
            char* argList[] = {"echo", NULL, NULL};
            switch (i) {
                case 0:
                    sprintf(buffer, "Hello from child 1\nMy pid is %d and I'm executing the command 'echo'\n", getpid());
                    argList[1] = buffer;
                    break;
                case 1:
                    sprintf(buffer, "Hello from child 2\nMy pid is %d and I'm executing the command 'echo'\n", getpid());
                    argList[1] = buffer;
                    break;
                case 2:
                    sprintf(buffer, "Hello from child 3\nMy pid is %d and I'm executing the command 'echo'\n", getpid());
                    argList[1] = buffer;
                    break;
                case 3:
                    sprintf(buffer, "Hello from child 4\nMy pid is %d and I'm executing the command 'echo'\n", getpid());
                    argList[1] = buffer;
                    break;
                case 4:
                    sprintf(buffer, "Hello from child 5\nMy pid is %d and I'm executing the command 'echo'\n", getpid());
                    argList[1] = buffer;
                    break;
                case 5:
                    sprintf(buffer, "Hello from child 6\nMy pid is %d and I'm executing the command 'echo'\n", getpid());
                    argList[1] = buffer;
                    break;
                case 6:
                    sprintf(buffer, "Hello from child 7\nMy pid is %d and I'm executing the command 'echo'\n", getpid());
                    argList[1] = buffer;
                    break;
                case 7:
                    sprintf(buffer, "Hello from child 8\nMy pid is %d and I'm executing the command 'echo'\n", getpid());
                    argList[1] = buffer;
                    break;
                case 8:
                    sprintf(buffer, "Hello from child 9\nMy pid is %d and I'm executing the command 'echo'\n", getpid());
                    argList[1] = buffer;
                    break;
                case 9:
                    sprintf(buffer, "Hello from child 10\nMy pid is %d, I'm executing the command 'echo', and I was written by Fisher Bachman-Rhodes\n", getpid());
                    argList[1] = buffer;
                    break;
                default:
                    break;
            }
            //execute the 'echo command with the current argument list'
            execVal = execvp("echo", argList);

            //if the execution fails, inform the user and exit the program
            if (execVal == -1) {
                perror("Exec failed");
                exit(1);
            }
        }
    }

    //parent process
    if (forkValue > 0) {
        for (int i = 0; i < 10; i++) {
            int status;
            //wait for the child processes
            pid_t pid = waitpid(-1, &status, 0);

            //if there was an error waiting, display it and exit the program
            if (pid == -1) {
                perror("Error waiting for child");
                exit(1);
            }

            //display the exit status of the child process
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                printf("Child with pid:%d exited normally with status %d\n\n", pid, exit_status);
            } else if (WIFSIGNALED(status)) {
                int signal_number = WTERMSIG(status);
                printf("Child with pid:%d was terminated by signal %d\n\n", pid, signal_number);
            } else if (WIFSTOPPED(status)) {
                int stop_signal = WSTOPSIG(status);
                printf("Child with pid:%d was stopped by signal %d\n\n", pid, stop_signal);
            }
        }
    }
    return 0;
}
