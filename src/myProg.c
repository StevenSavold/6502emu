#include <stdio.h>
#include <unistd.h>
#include "mylib.h"

int main(int argc , char **argv){

int x = 0;
int y = 0;
for(;;){
    
    y = addTwo(x);
    printf("%d\n", y);
    sleep(2);

}

return 0;
}
