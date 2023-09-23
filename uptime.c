#include "/home/aodelgado/CS4375/kernel/types.h"
#include "user.h"
 
int main(void){
    int ticks = uptime();
    printf("up %d clock ticks\n", ticks);
    exit(0);
}