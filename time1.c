#include "/home/aodelgado/CS4375/kernel/types.h"
#include "user.h"

int main(int argc, char *argv[]){
    int ticks = uptime();
    if(argc < 2){
        printf("Error: Fork was unsuccessful.");
        exit(1);
    }

    int pid = fork();

    // Unsuccessful fork()
    if(pid == -1){
        printf("Error fork() unsuccessful.");
        exit(1);
    }
    // Child process
    else if(pid == 0){
    exec(argv[1], &argv[1]);
    printf("Time: %d ticks\n", ticks);
    exit(1);
    }
    else{
        // Parent process
        int p;
        if(wait(&p) == -1){
            exit(1);
        }
        else{
            printf("Elapsed time: %d clock ticks\n", ticks);
            exit(1);
        }
    }
    return 0;
}